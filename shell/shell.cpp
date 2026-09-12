#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sstream>
#include <vector>
#include <climits>

std::vector<std::string> path_dirs = {"bin", "/bin", "/usr/bin"}; // vetor p armazenar os diretórios do PATH
std::vector<std::string> history; // vetor p armazenar o historico de comandos

// divide a linha de comando em tokens (palvras) separados por espaço
std::vector<std::string> parse_line(const std::string& line) {
    std::vector<std::string> tokens;
    std::stringstream ss(line);
    std::string token;

    while(ss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

std::string find_executable(const std::string& command, const std::vector<std::string>& path_dirs) {
    if (command.find('/') != std::string::npos) {
        if (access(command.c_str(), X_OK) == 0) return command;
        return "";
    }
    for (const auto& dir : path_dirs) {
        std::string full_path = dir + "/" + command;
        if (access(full_path.c_str(), X_OK) == 0) return full_path;
    }
    return "";
}

void print_history() {
    int total = history.size();
    int cont = std::min(total, 10);

    for (int i = 0; i < cont; i++) {
        int index = total - 1 - i; // +recente vai ser 0 e mais antigo 9
        std::cout << i << " " << history[index] << std::endl;
    }
}

void process_command(std::string command) {
    std::vector<std::string> tokens = parse_line(command); 
    if (tokens.empty()) return;

    // se for comando interno...
    if (tokens[0] == "exit") {
        exit(tokens.size() > 1 ? std::stoi(tokens[1]) : 0);
    }

    if (tokens[0] == "pwd") { 
        char buf[PATH_MAX];
        std::cout << (getcwd(buf, sizeof(buf)) ? buf : "erro") << std::endl;
        return;
    }

    if (tokens[0] == "cd") { 
        if (tokens.size() < 2 || chdir(tokens[1].c_str()) != 0) {
            std::cout << "cd: diretório não encontrado" << std::endl;
        }
        return;
    }   

    // contagem: mais recente = 0 e assim por diante -> de 0 a 9 (mais antigo)
    if (tokens[0] == "history") {
        if (tokens.size() == 1) {
            print_history(); 
        } else if (tokens[1] == "-c") {
            history.clear();
        } else {
            int total = history.size();
            int n = std::stoi(tokens[1]);
            int index = total - 1 - n;

            if (n < 0 || index < 0 || index >= total) {
                std::cout << "comando não encontrado!" << std::endl;
            } else {
                std::string cmd = history[index];
                std::cout << cmd << std::endl;
                process_command(cmd);
            }
        }

        return;
    }

    // se for externo, procura o caminho absoluto do comando
    std::string path = find_executable(tokens[0], path_dirs);

    if (path.empty()) {
        std::cout << "Command not found: " << tokens[0] << std::endl;
        return;
    }

    std::vector<char*> argv;
    for (auto& t : tokens) argv.push_back(const_cast<char*>(t.c_str())); 
    argv.push_back(nullptr);

    pid_t pid = fork();
    if (pid < 0) { // erro ao criar o processo filho -> sabe q é filho quando o retorno é 0
        std::cout << "Erro de execução!" << std::endl;
        return;
    } else if (pid == 0) { // filho
        execve(path.c_str(), argv.data(), NULL);
        std::cout << "Erro ao executar" << std::endl;
        exit(1);
    } else { // processo pai apenas espera o filho terminar
        waitpid(pid, nullptr, 0);
    }
}

int main() {
    while (true) {
        std::cout << "𑁍 > ";
        std::string command;

        getline(std::cin, command);

        if (!command.empty()) { // verifica se o comando não está vazio
            history.push_back(command); // add o comando ao histórico
            process_command(command);
        }
    }

    return 0;
}
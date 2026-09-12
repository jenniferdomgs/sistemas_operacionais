#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sstream>
#include <vector>

std::vector<std::string> path_dirs = {"/home/jennifer/sistemas_operacionais/bin", "/bin", "/usr/bin"}; // provaveis caminhos (absolutos) p os executáveis

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

void process_command(std::string command) {
    std::vector<std::string> tokens = parse_line(command); 
    if (tokens.empty()) return;

    // se for comando interno...
    if (tokens[0] == "exit") {
        exit(tokens.size() > 1 ? std::stoi(tokens[1]) : 0);
    }

    // procura o caminho absoluto do comando
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
            process_command(command);
        }
    }

    return 0;
}
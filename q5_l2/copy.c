// implementação do cp (copia conteúdo de um arquivo para outro)

# include <fcntl.h> 
# include <unistd.h>

int main(int argc, char **argv) {
    const char *sourcefn = argv[1]; // caminho do arquivo de origem
    const char *targetfn = argv[2]; // destino
    int source = open(sourcefn, O_RDONLY); // abre o arquivo de origem em só leitura
    int target = open(targetfn, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR); // abre ou cria o de destino (se criar add permissões de leitura e escrita)
    char buf[1024];
    int s;
    
    while ((s = read(source, buf, 1024)) != 0) { // armazena bytes lidos em buf
        write(target, buf, s); // escreve no destino
    }

    close(target);
    close(source);
    return 0;
}
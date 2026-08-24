// implementação do cat simples (lê um arquivo e imprime o conteúdo)

# include <fcntl.h> 
# include <stdio.h>
# include <unistd.h>

# define BUF_SIZE 1024

int main(int argc, char **argv) {
    int fd = open(argv[1], O_RDONLY); // abre a primeira linha de comando em só leitura
    char buf[BUF_SIZE];

    if (fd != -1) {
        ssize_t numRead = read(fd, buf, BUF_SIZE - 1); // fd: de onde ler | buf: p onde copia os dados lidos | BUF_SIZE-1: qtdd máxima se bytes que vai ler

        while (numRead > 0) { // numRead guarda os bytes realmente lidos
            buf[numRead] = '\0'; // coloca o 0 p marcar o fim da string
            printf("%s\n", buf);
            numRead = read(fd, buf, BUF_SIZE - 1);
        }

    } else {
        printf("Erro ao abrir o arquivo!\n");
        return -1;
    }

    close(fd);
    return 0;
}
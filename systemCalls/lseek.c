// implementação do lseek (move o ponteiro de leitura/escrita de um arquivo aberto)

# include <fcntl.h> 
# include <stdio.h>
# include <unistd.h>

#define BUF_SIZE 10

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDONLY); // abre a primeira linha de comando em só leitura
    char buf[BUF_SIZE];

    if (fd != -1) {
        int seek = lseek(fd, (BUF_SIZE -1)*2, SEEK_SET); // pula o cursor para uma posição (fd: arquivo | deslocamento | posição absoluta do cursor)

        if (seek != -1) {
            ssize_t numRead = read(fd, buf, BUF_SIZE - 1); // guarda em buf os bytes lidos
            buf[numRead] = '\0'; 
            printf("%s\n", buf);
        } else {
            printf("Erro ao buscar o arquivo!\n");
            close(fd);
            return -1;
        }

        close(fd);
    } else {
        printf("Erro ao abrir o arquivo!\n");
        return -1;
    }

    return 0;
}
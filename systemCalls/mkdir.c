// implementação do mkdir (cria diretório)

# include <stdio.h>
# include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Erro! passe todos os argumentos necessários.");
        return -1;
    }

    if (mkdir(argv[1], S_IRUSR) == -1) { // S_IRUSR: permissão de leitura, escrita e execução p o dono
        printf("Erro ao criar diretorio\n");
        return -1;
    }

    printf("Diretorio criado!\n");
    return 0;
}
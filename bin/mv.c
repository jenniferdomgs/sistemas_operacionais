# include <stdio.h>
# include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) { // no caso da chamada ser para renomear -> receberá 2 argumentos com nome atual e futuro nome
                    // e no caso de ser mover -> receberá o nome do arquivo e o nome do diretório
        printf("Erro! passe todos os argumentos necessários.\n");
        return -1;
    }

    if (rename(argv[1], argv[2]) == -1) {
        printf("Erro ao renomear ou mover arquivo!\n");
        return -1;
    }

    printf("Arquivo movido/renomeado!\n");
    return 0;
}
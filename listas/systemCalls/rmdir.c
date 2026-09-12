# include <stdio.h>
# include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Erro! passe todos os argumentos necessários.\n");
        return -1;
    }

    if (rmdir(argv[1]) == -1) {
        printf("Erro ao remover diretório!\n"); // se não tiver vazio ou se não existir
        return -1;
    }

    printf("Diretório removido!\n");
    return 0;
}
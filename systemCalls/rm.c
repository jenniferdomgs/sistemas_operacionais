// implementação do rm (remove um arquivo)

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) { // deve ter pelo menos 1 argumento
        printf("Erro! Passe todos os argumentos necessários.\n");
        return -1;
    }

    if (unlink(argv[1]) == -1) { // remove o link do arquivo
        printf("Erro ao remover o arquivo!\n");
        return -1;
    }

    printf("Arquivo removido!\n");
    return 0;
}
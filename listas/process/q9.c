# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <unistd.h>

int valor = 5;

int main(int argc, char **argv) {
    pid_t pid;
    valor += 1; // = 6
    pid = fork(); // duplica o pai e cria o filho
    // o pid do processo filho sempre é == 0
    // e do pai > 0

    valor += 1; // pai e filho = 7

    if (pid == 0) { // true pro filho = 10
        valor += 3;
    }

    if (pid > 0) { // true pro pai = 12
        valor += 5;
        wait(NULL); // faz o pai esperar até o filho terminar
        printf("Processo pai: valor = %d\n", valor); // 12
    }

    return 0;
}

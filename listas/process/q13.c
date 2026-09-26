# include <stdio.h>
# include <unistd.h>

int main(int argc, char **argv) {
    pid_t pid1 = fork(); // P1 (pai) e P2 (filho)

    if (pid1 > 0) { // true para P1
        pid_t pid2 = fork(); // P1 cria P3 
        if (pid2 == 0) { // true
            fork(); // P3 cria P4
        }
    }

    if (pid1 == 0) { // true para P2
        fork(); // P2 cria P5
    }

    if (pid1 == 0) { // true para P2 e P5
        fork(); // P2 cria P7 e P5 cria P6
    }

    return 0;
}
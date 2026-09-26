# include <stdio.h>
# include <unistd.h>

int main(intargc, char **argv) {
    fork(); // duplica o pai fazendo o filho (2 processos) pid do pai 

    pid_t pid1 = fork(); // duplica o pai e o filho (4 processos) 
    // o pai passa a ter2 filhos, e o primeiro filho passa a ter 1 filho (vira pai)

    if (pid1 > 0) { // true para 2 processos 
        fork(); // duplica os 2 pais (4 + 2 = 6)
    }

    fork(); // duplica todos = 6 * 2 = 12 processos
    return 0;
}
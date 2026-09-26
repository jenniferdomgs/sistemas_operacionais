# include <stdio.h>
# include <unistd.h>

int main(int argc, char **argv) {
    fork(); // 2
    fork(); // 4
    fork(); // 8

    // cada fork duplica o pai e cria um filho
    return 0;
}
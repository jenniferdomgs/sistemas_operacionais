# include <iostream>
# include <pthread.h>
# include <sys/wait.h>

int valor = 1;

void *runner(void *param) {
    valor = 5;
    std::cout << "Thread: valor = " << valor << std::endl; // 5
    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    pid_t pid;
    pthread_t tid;
    pthread_attr_t attr;
    pid = fork(); // duplica pai criando filho
    if (pid == 0) {
        pthread_attr_init(&attr);
        pthread_create(&tid, &attr, runner, NULL);
        pthread_join(tid, NULL);
        valor++; // valor = 6
        std::cout << "Processo filho: valor = " << valor << std::endl;
    } else if (pid > 0) {
        wait(NULL);
        valor++; // valor = 2
        std::cout << "Processo pai: valor = " << valor << std::endl;
    }
    return 0;
}
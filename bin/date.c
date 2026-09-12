# include <stdio.h>
# include <time.h>
int main() {
    time_t agora = time(NULL);

    if (agora == -1) {
        printf("Erro!\n");
        return -1;
    }

    struct tm *hora_local = localtime(&agora);

    printf(
        "%02d/%02d/%04d %02d:%02d:%02d\n",
        hora_local->tm_mday,
        hora_local->tm_mon + 1,
        hora_local->tm_year + 1900,
        hora_local->tm_hour,
        hora_local->tm_min,
        hora_local->tm_sec
    );

    return 0;
}
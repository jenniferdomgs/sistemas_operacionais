# include <stdio.h>
# include <dirent.h>
# include <unistd.h>
# include <limits.h>

int main(int argc, char *argv[]) {
    char caminho[PATH_MAX];
    const char *camDiretorio;

    if (argc < 2) {
       if (getcwd(caminho, sizeof(caminho)) == NULL) { // chamada p pegar o diretório atual
        printf("Erro ao pegar diretório atual!\n");
        return -1;
       }
       camDiretorio = caminho;
    } else {
        camDiretorio = argv[1];
    }

    DIR *diretorio = opendir(camDiretorio); // chamda para abrir o diretório

    if ( diretorio == NULL) {
        printf("Erro ao abrir diretório!\n");
        return -1;
    }

    struct dirent *entrada;

    while ((entrada = readdir(diretorio)) != NULL) { // chamda para ler 
        printf("%s\n", entrada->d_name);
    }

    closedir(diretorio);
    return 0;
}
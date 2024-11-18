#include <stdio.h>
#include <string.h>

#define TAM 100

struct User {
    int id_user;
    char nome[TAM];
    int favoritos[TAM];
    int qtd_favoritos;
};

struct Movie {
    int id_movie;
    char titulo[TAM];
};

void menu(FILE *user, FILE *strm);
void lerStr(char *str, int tam);
void listarUsuarios(FILE *user);
void listarFilmes(FILE *strm);
void adicionarUsuario(FILE *user, int tam);
void adicionarFilme(FILE *strm, int tam);
void adicionarFilmeFavorito(FILE *user, FILE *strm, int tam);
void excluirFilme(FILE *strm);
void relatorioUsuarioFilme(FILE *user, FILE *strm);

int main() {
    FILE *arqUser;
     FILE *arqStrm;

     arqUser = fopen("user.bin", "rb+");
     if (!arqUser) {
         arqUser = fopen("user.bin", "wb+"); 
     }

     arqStrm = fopen("strm.bin", "rb+");
     if (!arqStrm) {
         arqStrm = fopen("strm.bin", "wb+"); 
     }

     menu(arqUser, arqStrm);

     fclose(arqUser);
     fclose(arqStrm);

     return 0;
}

void menu(FILE *user, FILE *strm){
    int opcao;
    do {
        printf("1 - adicionar filme\n");
        printf("2 - adicionar usuario\n");
        printf("3 - listar usuario\n");
        printf("4 - listar filmes\n");
        printf("5 - adicionar filme favorito\n");
        printf("6 - relatorio\n");
        printf("7 - excluir filme\n");

        printf("0 - sair\n");
        
        printf("Digite a opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                adicionarFilme(strm, TAM);
                break;
            case 2:
                adicionarUsuario(user, TAM);
                break;
            case 3:
                listarUsuarios(user);
                break;
            case 4:
                listarFilmes(strm);
                break;
            case 5: 
                adicionarFilmeFavorito(user, strm, TAM);
                break;
            case 6:
                relatorioUsuarioFilme(user, strm);
                break;
            case 7:
                excluirFilme(strm);
                break;

        }

    } while (opcao != 0);
}

void lerStr(char *str, int tam) {
     fgets(str, tam, stdin);
     int len = strlen(str);
     if(str[len - 1] == '\n'){
        str[len - 1] = '\0';
     }
}


void listarUsuarios(FILE *user){
    struct User u;
    rewind(user); 

    while (fread(&u, sizeof(struct User), 1, user)) {
        printf("Nomes: %s\n", u.nome);
    }
}


void listarFilmes(FILE *strm) {
    struct Movie m;
    rewind(strm);  

    while (fread(&m, sizeof(struct Movie), 1, strm)) {
        printf("Titulo: %s\n",m.titulo);
    }
}


void adicionarUsuario(FILE *user, int tam) {
    struct User u;
    char tem[TAM];

    printf("Informe o ID do usuario: ");
    scanf("%d", &u.id_user);
    lerStr(tem, TAM);
    printf("\nInforme o nome do usuario: ");
    lerStr(u.nome, tam);


    u.qtd_favoritos = 0; // Inicializa favoritos
    fseek(user, 0, SEEK_END);
    fwrite(&u, sizeof(struct User), 1, user);
    fflush(user);
}


void adicionarFilme(FILE *strm, int tam) {
    struct Movie m;
    char tem[TAM];
    printf("Informe o ID do filme: ");
    scanf("%d", &m.id_movie);
    lerStr(tem, TAM);
    printf("\nInforme o titulo do filme: ");
    lerStr(m.titulo, tam);

    fseek(strm, 0, SEEK_END);
    fwrite(&m, sizeof(struct Movie), 1, strm);
    fflush(strm);
}


void adicionarFilmeFavorito(FILE *user, FILE *strm, int tam) {
    char nomeUser[TAM], nomeFilme[TAM];
    char tem[TAM];
    struct User u;
    struct Movie m;
    int encontradoUsuario = 0, encontradoFilme = 0;

    lerStr(tem, tam);
    printf("Informe o nome do usuario: ");
    lerStr(nomeUser, tam);
    printf("\nInforme o titulo do filme: ");
    lerStr(nomeFilme, tam);

    // Verifica se o filme existe
    rewind(strm); 
    while (fread(&m, sizeof(struct Movie), 1, strm)) {
        if (strcmp(m.titulo, nomeFilme) == 0) {
            encontradoFilme = 1;
            break;
        }
    }

    if (!encontradoFilme) {
        printf("Titulo do filme %s não encontrado!\n", nomeFilme);
        return;
    }

    // Verifica se o usuário existe e adiciona o filme aos favoritos
    rewind(user); 
    FILE *arquivoTemp = fopen("usuarios_temp.bin", "wb");
    if (!arquivoTemp) {
        printf("Erro ao criar arquivo temporário!\n");
        return;
    }

    while (fread(&u, sizeof(struct User), 1, user)) {
        if (strcmp(u.nome, nomeUser) == 0) {
            encontradoUsuario = 1;

            // Adiciona o filme aos favoritos, se não já estiver cheio
            if (u.qtd_favoritos < tam) {
                u.favoritos[u.qtd_favoritos] = m.id_movie; 
                printf("Filme %s adicionado aos favoritos do usuario %s com sucesso!.\n", nomeFilme, nomeUser);
                u.qtd_favoritos++;
            } else {
                printf("O usuário já tem a lista de favoritos cheia!\n");
            }
        }
        fwrite(&u, sizeof(struct User), 1, arquivoTemp);
    }

    fclose(user);
    fclose(arquivoTemp);

    // Substitui o arquivo antigo pelo novo
    remove("user.bin");
    rename("usuarios_temp.bin", "user.bin");
    user = fopen("user.bin", "rb+");

    if (!encontradoUsuario) {
        printf("Usuário %s não encontrado!\n", nomeUser);
    }
}


void excluirFilme(FILE *strm) {
    char filmeDelet[TAM];

    printf("Nome do filme que deseja excluir:");
    lerStr(filmeDelet, TAM);

    // Cria um arquivo temporário
    FILE *arquivoTemp = fopen("temp.bin", "wb");
    if (!arquivoTemp) {
        printf("Erro ao criar arquivo temporário!\n");
        return;
    }

    struct Movie m;
    rewind(strm);  

    // Copia todos os registros que NÃO têm o ID a ser excluído
    while (fread(&m, sizeof(struct Movie), 1, strm)) {
        if (strcmp(filmeDelet, m.titulo) != 0) {
            fwrite(&m, sizeof(struct Movie), 1, arquivoTemp);
        } else {
            printf("Filme %s excluido com sucesso.\n", filmeDelet);
        }
    }

    // Fecha os arquivos
    fclose(strm);
    fclose(arquivoTemp);

    remove("strm.bin");
    rename("temp.bin", "strm.bin");

    strm = fopen("strm.bin", "rb+");
    if (!strm) {
        printf("Erro ao reabrir o arquivo original!\n");
    }
}

void relatorioUsuarioFilme(FILE *user, FILE *strm) {
    struct User u;
    struct Movie m;

    rewind(user);
    while (fread(&u, sizeof(struct User), 1, user)) {
        printf("Usuario: %s\n", u.nome);
        printf("Filmes Favoritados:\n");
        for (int i = 0; i < u.qtd_favoritos; i++) {
            int encontrado = 0;
            rewind(strm);
            while (fread(&m, sizeof(struct Movie), 1, strm)) {
                if (m.id_movie == u.favoritos[i]) {
                    printf("%s\n", m.titulo);
                    encontrado = 1;
                    break;
                }
            }
        }
        printf("\n");
    }
}


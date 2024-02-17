#include <stdio.h>
#include "../headers/inserir_inicio.h"
#include <string.h>

int inserirInicio(Playlist **primeira)
{
    Playlist *novaMusica = malloc(sizeof(Playlist));
    char nome[100], artista[100];
    printf("Digite o nome da música: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;
    printf("Digite o artista da música: ");
    fgets(artista, sizeof(artista), stdin);
    artista[strcspn(artista, "\n")] = 0;

    if (novaMusica != NULL)
    {
        strcpy(novaMusica->titulo, nome);
        strcpy(novaMusica->artista, artista);

        novaMusica->proxima = *primeira;

        *primeira = novaMusica;

        printf("Música adicionada com sucesso\n");
        return 1;
    }
    else
    {
        printf("Falha ao adicionar música\n");
        return 0;
    }
}
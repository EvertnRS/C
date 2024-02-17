#include <stdio.h>
#include "../headers/inserir_posicao.h"
#include <string.h>

int inserirNaPosicao(Playlist **primeira)
{
    int pos, x = 0;
    Playlist *novaMusica = malloc(sizeof(Playlist));
    char nome[100], artista[100];
    printf("Digite o nome da música: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;
    printf("Digite o artista da música: ");
    fgets(artista, sizeof(artista), stdin);
    artista[strcspn(artista, "\n")] = 0;
    printf("Qual a posição que você quer inserir a música: ");
    scanf("%d", &pos);

    if (novaMusica != NULL)
    {
        strcpy(novaMusica->titulo, nome);
        strcpy(novaMusica->artista, artista);
        Playlist *musicaAtual = *primeira;
        Playlist *musicaAnterior = NULL;

        while (musicaAtual != NULL && x < pos)
        {
            musicaAnterior = musicaAtual;
            musicaAtual = musicaAtual->proxima;
            x++;
        }

        if (musicaAnterior == NULL)
        {
            novaMusica->proxima = *primeira;
            *primeira = novaMusica;
        }
        else
        {
            musicaAnterior->proxima = novaMusica;
            novaMusica->proxima = musicaAtual;
        }
        printf("Musica inserida com sucesso\n");
        return 1;
    }
    else
    {
        printf("Falha ao adicionar a música\n");
        return 0;
    }
}
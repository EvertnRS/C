#include <stdio.h>
#include "../headers/imprimir_lista.h"
#include <string.h>

void imprimirLista(Playlist *primeira)
{
    Playlist *musicaAtual = primeira;
    if (musicaAtual == NULL)
    {
        printf("Playlist Vazia\n");
        return;
    }
    while (musicaAtual != NULL)
    {
        printf("Nome: %s Artista: %s\n", musicaAtual->titulo, musicaAtual->artista);
        musicaAtual = musicaAtual->proxima;
    }
    printf("\n");
}
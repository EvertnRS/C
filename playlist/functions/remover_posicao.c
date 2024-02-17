#include <stdio.h>
#include "../headers/inserir_posicao.h"
#include <string.h>
#include <stdlib.h>

void removerDaPosicao(Playlist **primeira)
{
    int pos, x = 0;
    Playlist *musicaAtual = malloc(sizeof(Playlist));
    musicaAtual = *primeira;
    Playlist *musicaAnterior = NULL;
    printf("Qual a posição que você quer deletar a música: ");
    scanf("%d", &pos);

    while (x < pos)
    {
        musicaAnterior = musicaAtual;
        musicaAtual = musicaAtual->proxima;
        x++;
    }

    if (musicaAnterior == NULL)
    {
        *primeira = musicaAtual->proxima;
    } else 
    {
        musicaAnterior->proxima = musicaAtual->proxima;
    }
    free(musicaAtual);
    musicaAtual = NULL;
    
    printf("Música removida com sucesso\n");
}
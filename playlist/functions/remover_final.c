#include <stdio.h>
#include "../headers/remover_final.h"
#include <string.h>
#include <stdlib.h>

void removerFinal(Playlist **primeira)
{
    Playlist *musicaAtual = malloc(sizeof(Playlist));
    musicaAtual = *primeira;
    char op;
    printf("Deseja deletar a última música da playlist? [S, N]\n");
    scanf("%c", &op);
    clear_buffer();
    if (op == 'S')
    {
        if ((*primeira)->proxima == NULL)
        {
            free(*primeira);
            *primeira = NULL;
        }

        while (musicaAtual->proxima->proxima != NULL)
        {
            musicaAtual = musicaAtual->proxima;
        }
        free(musicaAtual->proxima);
        musicaAtual->proxima = NULL;

        printf("Música deletada com sucesso\n");
    }
}
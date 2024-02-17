#include <stdio.h>
#include "../headers/remover_inicio.h"
#include <string.h>
#include <stdlib.h>

void removerInicio(Playlist **primeira)
{
    char op;
    printf("Deseja deletar a primeira música da playlist? [S, N]\n");
    scanf("%c", &op);
    clear_buffer();
    if (op == 'S')
    {
        if (*primeira != NULL)
        {
            Playlist *musicaParaDeletar = *primeira;
            *primeira = (*primeira)->proxima;
            free(musicaParaDeletar);
        }
    }
    printf("Música deletada com sucesso\n");
}
#include <stdio.h>
#include "../headers/recuperar_musica.h"
#include <string.h>

void recuperarMusica(Playlist *primeira)
{
    if (primeira != NULL)
    {
        int pos, cont = 0;
        Playlist *musicaAtual = primeira;
        printf("Digite a posição da música que você quer recuperar: ");
        scanf("%d", &pos);

        while (cont < pos)
        {
            if (musicaAtual->proxima == NULL)
            {
                printf("Procura encerrada\n");
                break;
            }
            musicaAtual = musicaAtual->proxima;
            cont++;
        }
        if (cont == pos)
        {
            printf("\nNome: %s Artista: %s\n", musicaAtual->titulo, musicaAtual->artista);
        }
    }
    else
    {
        printf("Playlist vazia\n");
    }
}
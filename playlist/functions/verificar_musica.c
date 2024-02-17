#include <stdio.h>
#include "../headers/verificar_musica.h"
#include <string.h>

void verificarMusica(Playlist *primeira)
{
    char nome[100];
    int pos = 0;
    printf("Qual música deseja procurar?\n");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    while (primeira != NULL)
    {
        if(strcmp(primeira->titulo, nome) == 0)
        {
            printf("Música %s do Artista %s encontrada na posição %d\n", primeira->titulo, primeira->artista, pos);
            break;
        } else if (primeira->proxima == NULL)
        {
            printf("Música não encontrada\n");
            break;
        }

        primeira = primeira->proxima;
        pos++;
    }
}
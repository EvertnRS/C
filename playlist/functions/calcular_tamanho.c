#include <stdio.h>
#include "../headers/calcular_tamanho.h"

void calcularTamanho(Playlist *primeira)
{
    int tam = 0;
    if (primeira == NULL)
    {
        printf("Playlist Vazia\n");
    }
    else
    {
        while (primeira != NULL)
        {
            primeira = primeira->proxima;
            tam++;
        }

        printf("\nTamanho: %d\n", tam);
    }
}
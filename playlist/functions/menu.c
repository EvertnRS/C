// welcome.c
#include <stdio.h>
#include "../headers/menu.h"
#include "../headers/clear_buffer.h"
#include "../headers/imprimir_lista.h"
#include "../headers/inserir_final.h"
#include "../headers/recuperar_musica.h"
#include "../headers/inserir_inicio.h"
#include "../headers/remover_final.h"
#include "../headers/remover_inicio.h"
#include "../headers/calcular_tamanho.h"
#include "../headers/inserir_posicao.h"
#include "../headers/remover_posicao.h"
#include "../headers/verificar_musica.h"

void menu()
{
    char op;
    Playlist *playlist = NULL;
    do
    {
        printf("a) Inserir no final; \n");
        printf("b) Imprimir lista; \n");
        printf("c) Recuperar a n-ésima música da lista; \n");
        printf("d) Inserir no início; \n");
        printf("e) Remover do final; \n");
        printf("f) Remover do início; \n");
        printf("g) Calcular o tamanho da playlist (número de músicas); \n");
        printf("h) Inserir/remover uma música na posição X da lista; \n");
        printf("i) Verificar se uma música existe na playlist; \n");
        printf("s) Sair; \n");
        printf("Escolha a opção: ");
        scanf("%c", &op);
        clear_buffer();

        if (op == 'a')
        {
            inserirFinal(&playlist);
        }
        else if (op == 'b')
        {
            printf("\n");
            imprimirLista(playlist);
        }
        else if (op == 'c')
        {
            recuperarMusica(playlist);
        }
        else if (op == 'd')
        {
            inserirInicio(&playlist);
        }
        else if (op == 'e')
        {
            removerFinal(&playlist);
        }
        else if (op == 'f')
        {
            removerInicio(&playlist);
        }
        else if (op == 'g')
        {
            calcularTamanho(playlist);
        }
        else if (op == 'h')
        {
            printf("Você quer Inserir ou Remover a musica?[I, R]\n");
            scanf("%c", &op);
            clear_buffer();
            if (op == 'I')
            {
                inserirNaPosicao(&playlist);
            }
            else if (op == 'R')
            {
                removerDaPosicao(&playlist);
            }
            else
            {
                printf("Opção Inválida\n");
            }
        }
        else if (op == 'i')
        {
            verificarMusica(playlist);
        }
        else
        {
            printf("Opção Inválida");
        }
    } while (op != 's');
}

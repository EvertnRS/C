#include <stdio.h>
#include <locale.h>

void clear_buffer()
{
    setlocale(LC_ALL, "Portuguese");
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        continue;
    }
}

int printMap(char mapa[6][6], int posicao[2])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (posicao[0] == i && posicao[1] == j)
            {
                mapa[i][j] = '#';
            }
            else
            {
                mapa[i][j] = '-';
            }
            printf("%c ", mapa[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int main(void)
{
    char mapa[6][6], opcao;
    int posicao[2] = {2, 2};
    printMap(mapa, posicao);
    do
    {
        printf("Digite para qual direção o personagem deve andar\n");
        printf("O: Oeste\n");
        printf("L: Leste\n");
        printf("N: Norte\n");
        printf("S: Sul\n");
        printf("X: Parar\n");
        scanf("%c", &opcao);
        clear_buffer();

        if (opcao == 'O')
        {
            if (posicao[1] == 0)
            {
                printf("Limite do mapa\n");
            }
            else
            {
                posicao[1]--;
            }
        }
        else if (opcao == 'L')
        {
            if (posicao[1] == 5)
            {
                printf("Limite do mapa\n");
            }
            else
            {
                posicao[1]++;
            }
        }
        else if (opcao == 'N')
        {
            if (posicao[0] == 0)
            {
                printf("Limite do mapa\n");
            }
            else
            {
                posicao[0]--;
            }
        }
        else if (opcao == 'S')
        {
            if (posicao[0] == 5)
            {
                printf("Limite do mapa\n");
            }
            else
            {
                posicao[0]++;
            }
        }
        else if (opcao == 'X')
        {
            break;
        }
        else
        {
            printf("Valor inválido");
        }
        printMap(mapa, posicao);
    } while (opcao != 'X');
    return 0;
}
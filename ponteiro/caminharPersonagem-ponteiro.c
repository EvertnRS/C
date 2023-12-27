#include <stdio.h>

void desenharMapa(int x, int y);
void clear_buffer();
void caminhar(int *pX, int *pY, char opcao);

int main(void)
{
    char opcao;
    int x = 2, y = 2, *pX = &x, *pY = &y;
    do
    {
        desenharMapa(x, y);
        printf("Digite para qual direção o personagem deve andar\n");
        printf("O: Oeste\n");
        printf("L: Leste\n");
        printf("N: Norte\n");
        printf("S: Sul\n");
        printf("X: Parar\n");
        scanf("%c", &opcao);
        clear_buffer();
        caminhar(pX, pY, opcao);
    } while (opcao != 'X');
    return 0;
}

void desenharMapa(int x, int y)
{
    char mapa[6][6];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (i == y && j == x)
            {
                mapa[i][j] = '#';
            }
            else
            {
                mapa[i][j] = '-';
            }
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }
}

void clear_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        continue;
    }
}

void caminhar(int *pX, int *pY, char opcao)
{
    if (*pX > 0 && *pX < 5 && *pY > 0 && *pY < 5)
    {
        if (opcao == 'O')
        {
            --*pX;
        }
        else if (opcao == 'L')
        {
            ++*pX;
        }
        else if (opcao == 'N')
        {
            --*pY;
        }
        else if (opcao == 'S')
        {
            ++*pY;
        }
        else if (opcao == 'X')
        {
            printf("Saindo...");
        }
        else
        {
            printf("Opção Inválida");
        }
    }
    else
    {
        printf("limite do mapa\n");
        switch (*pX)
        {
        case 0:
            ++*pX;
            break;
        case 5:
            --*pX;
            break;
        }
        switch (*pY)
        {
        case 0:
            ++*pY;
            break;
        case 5:
            --*pY;
            break;
        }
    }
}
#include <stdio.h>
#include <string.h>

char onibus[6][4] = {{'O', 'O', 'O', 'O'}, {'O', 'O', 'O', 'O'}, {'O', 'O', 'O', 'O'}, {'O', 'O', 'O', 'O'}, {'O', 'O', 'O', 'O'}, {'O', 'O', 'O', 'O'}};
int cadeira[6][4] = {{1, 2, 4, 3}, {5, 6, 8, 7}, {9, 10, 12, 11}, {13, 14, 16, 15}, {17, 18, 20, 19}, {21, 22, 24, 23}}, cpfs[6][4];

void clear_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        continue;
    }
}

int listarAssentos()
{
    printf("Cadeiras Vazias:\n");
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (onibus[i][j] == 'O')
            {
                printf("%d ", cadeira[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}

int cancelarPassagem(int cpf)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (cpf == cpfs[i][j])
            {
                onibus[i][j] = 'O';
                printf("Passagem Cancelada\n");
                return 0;
            }
        }
    }
}

int printarOnibus()
{
    char status[8];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (onibus[i][j] == 'O')
            {
                strcpy(status, "Livre");
            }
            else
            {
                strcpy(status, "Ocupado");
            }
            printf("%d: %s ", cadeira[i][j], status);
        }
        printf("\n");
    }
    return 0;
}

int alocarAssento(int cpf)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (onibus[i][j] == 'O')
            {
                if (cadeira[i][j] % 2 != 0)
                {
                    printf("CPF: %d Assento <%d> (Janela)\n", cpf, cadeira[i][j]);
                }
                else
                {
                    printf("CPF: %d Assento <%d> (Corredor)\n", cpf, cadeira[i][j]);
                }
                onibus[i][j] = 'X';
                cpfs[i][j] = cpf;
                return 0;
            }
        }
    }
}

int main()
{
    int cpf;
    do
    {
        printf("[-1] - Listar Assentos Vazios;\n");
        printf("[-2] - Mostrar mapa do ônibus;\n");
        printf("[-3] - Cancelar Passagem;\n");
        printf("[0] - Sair;\n");
        printf("Digite seu cpf: ");
        clear_buffer();
        scanf("%d", &cpf);
        switch (cpf)
        {
        case -1:
            listarAssentos();
            break;
        case 0:
            break;
        case -2:
            printarOnibus();
            break;
        case -3:
            printf("Digite o cpf que deseja cancelar a passagem: ");
            clear_buffer();
            scanf("%d", &cpf);
            cancelarPassagem(cpf);
            break;
        default:
            alocarAssento(cpf);
        }
    } while (cpf != 0);
    return 0;
}
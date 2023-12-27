#include <stdio.h>
#include <string.h>

typedef struct
{
    int numero;
    int cpf;
    char status[8];
    char posicao[9];
} cadeira;

int alocarAssento(int *cpf, cadeira cadeiras[24], int *index);
void criarCadeira(cadeira cadeira[24]);
void listarAssentosVazios(cadeira cadeira[24]);
void cancelarPassagem(int *pCpf, cadeira cadeira[24], int *index);
void printarOnibus();

int main(void)
{
    cadeira cadeiras[24];
    int cpf, *pCpf = &cpf, index = 0;
    criarCadeira(cadeiras);
    // for (int i = 0; i < 24; i++)
    // {
    //     printf("Digite o cpf: ");
    //     scanf("%d", pCpf);
    //     switch (cpf)
    //     {
    //     case -3:
    //         printarOnibus();
    //         break;
    //     case -2:
    //         printf("Digite o cpf que deseja cancelar a passagem: ");
    //         scanf("%d", pCpf);
    //         cancelarPassagem(pCpf, cadeiras);
    //         break;
    //     case -1:
    //         listarAssentosVazios(cadeiras);
    //         break;
    //     case 0:
    //         break;
    //         break;
    //     default:
    //         alocarAssento(pCpf, cadeiras);
    //     }
    // }
    do
    {
        printf("Digite o cpf: ");
        scanf("%d", pCpf);
        switch (cpf)
        {
        case -3:
            printarOnibus();
            break;
        case -2:
            printf("Digite o cpf que deseja cancelar a passagem: ");
            scanf("%d", pCpf);
            cancelarPassagem(pCpf, cadeiras, &index);
            break;
        case -1:
            listarAssentosVazios(cadeiras);
            break;
        case 0:
            printf("Saindo...");
            break;
        default:
            if (index < 24)
            {
                alocarAssento(pCpf, cadeiras, &index);
            }
            else
            {
                printf("Ônibus cheio.\n");
            }
        }
    } while (cpf != 0);
    return 0;
}

int alocarAssento(int *cpf, cadeira cadeiras[24], int *index)
{
    for (int i = 0; i < 24; i++)
    {
        if (strcmp(cadeiras[i].posicao, "Janela") == 0 && strcmp(cadeiras[i].status, "Livre") == 0)
        {
            cadeiras[i].cpf = *cpf;
            strcpy(cadeiras[i].status, "Ocupado");
            printf("<%d> --Assento: %d (%s)\n", cadeiras[i].cpf, cadeiras[i].numero, cadeiras[i].posicao);
            (*index)++;
            return 0;
        }
    }
    for (int i = 0; i < 24; i++)
    {
        if (strcmp(cadeiras[i].posicao, "Corredor") == 0 && strcmp(cadeiras[i].status, "Livre") == 0)
        {
            cadeiras[i].cpf = *cpf;
            strcpy(cadeiras[i].status, "Ocupado");
            printf("<%d> --Assento: %d (%s)\n", cadeiras[i].cpf, cadeiras[i].numero, cadeiras[i].posicao);
            (*index)++;
            return 0;
        }
    }
}

void listarAssentosVazios(cadeira cadeira[24])
{
    for (int i = 0; i < 24; i++)
    {
        if (strcmp(cadeira[i].status, "Livre") == 0)
        {
            printf("Assento: %d (%s)\n", cadeira[i].numero, cadeira[i].posicao);
        }
    }
}

void criarCadeira(cadeira cadeira[24])
{
    for (int i = 0; i < 24; i++)
    {
        cadeira[i].numero = i + 1;
        strcpy(cadeira[i].status, "Livre");
        if (cadeira[i].numero % 2 == 0)
        {
            strcpy(cadeira[i].posicao, "Corredor");
        }
        else
        {
            strcpy(cadeira[i].posicao, "Janela");
        }
    }
}

void cancelarPassagem(int *pCpf, cadeira cadeira[24], int *index)
{
    for (int i = 0; i < 24; i++)
    {
        if (cadeira[i].cpf == *pCpf)
        {
            strcpy(cadeira[i].status, "Livre");
            cadeira[i].cpf = 0;
            (*index)--;
            break;
        }
    }
    printf("Passagem Cancelada\n");
}

void printarOnibus()
{
    int numero[6][4] = {{1, 2, 4, 3}, {5, 6, 8, 7}, {9, 10, 12, 11}, {13, 14, 16, 15}, {17, 18, 20, 19}, {21, 22, 24, 23}};
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", numero[i][j]);
        }
        printf("\n");
    }
}
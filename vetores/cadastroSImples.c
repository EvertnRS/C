#include <stdio.h>
#include <string.h>

int main(void)
{
    char nomes[10][100];
    int rgs[10], opcao, rg;
    for (int i = 0; i < 10; i++)
    {
        printf("[1] Cadastrar Pessoa\n");
        printf("[2] Pesquisar Pessoa\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite o nome da pessoa: ");
            scanf("%s", nomes[i]);
            printf("Digite o RG da pessoa: ");
            scanf("%d", &rgs[i]);
            break;
        case 2:
            printf("Digite o RG da pessoa: ");
            scanf("%d", &rg);
            for (int p = 0; p < 10; p++)
            {
                if (rgs[p] == rg)
                {
                    printf("Nome: %s \n", nomes[p]);
                }
            }
        }
    }
    return 0;
}
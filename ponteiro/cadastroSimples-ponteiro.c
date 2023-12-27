#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pessoa
{
    char nome[100];
    long int cpf;
} Pessoa;

void cadastrarPessoa(Pessoa *lista, int *index);
void clear_buffer();
void pesquisarPessoa(Pessoa *lista, int *index);

int main()
{
    int op, index = 0;
    Pessoa *listaPessoas = calloc(10, sizeof(Pessoa));
    do
    {
        printf("[1] - Cadastrar Pessoa\n");
        printf("[2] - Pesquisar Pessoa\n");
        printf("Digite a opção que deseja realizar: \n");
        scanf("%d", &op);
        clear_buffer();
        switch (op)
        {
        case 1:
            cadastrarPessoa(listaPessoas, &index);
            break;
        case 2:
            pesquisarPessoa(listaPessoas, &index);
            break;
        default:
            printf("Opção Inválida");
            break;
        }
    } while (op != 0);
    return 0;
}

void cadastrarPessoa(Pessoa *lista, int *index)
{
    char nome[100];
    long int cpf;
    if (*index < 10)
    {
        printf("Digite o nome da pessoa que deseja cadastrar:\n");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = 0; // retira o \n da string
        printf("Digite o cpf de %s:\n", nome);
        scanf("%li", &cpf);
        clear_buffer();
        strcpy(lista[*index].nome, nome);
        lista[*index].cpf = cpf;
        (*index)++;
    }
    else
    {
        printf("Lista cheia\n");
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

void pesquisarPessoa(Pessoa *lista, int *index)
{
    long int cpf;
    int x = 0;
    printf("Digite o  cpf da pessoa que deseja pesquisar: ");
    scanf("%li", &cpf);
    for (int i = 0; i < *index; i++)
    {
        if (lista[i].cpf == cpf)
        {
            puts(lista[i].nome);
            x++;
        }
    }
    if (x == 0)
    {
        printf("Não encontrado\n");
    }
}
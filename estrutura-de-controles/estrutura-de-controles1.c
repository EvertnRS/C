#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    int n[5];
    do
    {
        printf("Digite o código: ");
        scanf("%d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &n[4]);
    } while (n[1] >= 10 || n[2] >= 10 || n[3] >= 10 || n[4] >= 10 || n[0] >= 10);
    for (int i = 0; i <= 5; i++)
    {
        for (int j = 0; j < n[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
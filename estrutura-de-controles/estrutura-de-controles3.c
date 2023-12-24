#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    int cod, quant;
    float tot = 0;
    do
    {
        printf("1   $2.98\n");
        printf("2   $4.50\n");
        printf("3   $9.98\n");
        printf("4   $4.49\n");
        printf("5   $6.87\n");
        printf("Digite o código e a quantidade do produto: ");
        scanf("%d %d", &cod, &quant);
        switch (cod)
        {
        case 1:
            tot += 2.98 * quant;
            break;
        case 2:
            tot += 4.50 * quant;
            break;
        case 3:
            tot += 9.98 * quant;
            break;
        case 4:
            tot += 4.49 * quant;
            break;
        case 5:
            tot += 6.87 * quant;
            break;
        }
    } while (cod != 0 && quant != 0);
    printf("Total: %.2f", tot);
    return 0;
}
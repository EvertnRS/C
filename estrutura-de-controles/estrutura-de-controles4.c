#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    float val;
    int n50 = 0, n20 = 0, n10 = 0, n5 = 0, n1 = 0;
    printf("Valor lido: ");
    scanf("%f", &val);
    while (val > 0)
    {
        if (val >= 50)
        {
            val = val - 50.0;
            n50++;
        }
        else if (val >= 20)
        {
            val -= 20.0;
            n20++;
        }
        else if (val >= 10)
        {
            val -= 10.0;
            n10++;
        }
        else if (val >= 5)
        {
            val -= 5.0;
            n5++;
        }
        else
        {
            val -= 1.0;
            n1++;
        }
    }
    printf("Cédulas:\n");
    printf("%d de 50\n", n50);
    printf("%d de 20\n", n20);
    printf("%d de 10\n", n10);
    printf("%d de 5\n", n5);
    printf("%d de 1\n", n1);
    return 0;
}
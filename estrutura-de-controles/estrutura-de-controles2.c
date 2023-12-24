#include <stdio.h>

int main(void)
{
    for (int i = 10; i > 0; i--)
    {
        for (int j = i; j <= 10; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (int i = 1; i <= 10; i++)
    {
        for (int j = i; j <= 10; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
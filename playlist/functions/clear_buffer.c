#include <stdio.h>
#include "../headers/clear_buffer.h"

void clear_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        continue;
    }
}
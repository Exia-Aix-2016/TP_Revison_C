#include <stdio.h>
#include <stdlib.h>

int fx_trouverCode(int code);

int main()
{
    int i, res;
    for (i = 0; i < 1000000; i++)
    {
        if (fx_trouverCode(i))
        {
            res = i;
            i = 1000000;
        }
    }
    printf("Le code est %d\n", res); //12548
    return 0;
}

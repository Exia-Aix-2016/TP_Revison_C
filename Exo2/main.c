#include <stdio.h>
#include <stdlib.h>

double moyenne(int *tab);

int main()
{
    int tab[] = {5, 8, 3, NULL};
    printf("Moyenne : %g", moyenne(tab));
    return 0;
}

double moyenne(int *tab)
{
    double somme = 0.0;
    int i = 0;

    while (tab[i] != NULL)
    {
        somme += tab[i];
        i++;
    }
    return somme / i;
}
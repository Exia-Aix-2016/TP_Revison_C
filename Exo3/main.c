#include <stdio.h>
#include <stdlib.h>

int *ajouter(int *ptab, int *size);
void afficher(int *tab, int size);

int main()
{
    int size = 0;
    int *tab;
    while (1)
    {
        system("cls");
        tab = ajouter(tab, &size);
        afficher(tab, size);
        system("pause");
    }
    return 0;
}

int *ajouter(int *ptab, int *size)
{
    int val;
    int ind;
    int *tab;
    int i;

    printf("Valeur a ajouter : ");
    scanf("%d", &val);

    printf("Choisir un index \n");
    for (i = 0; i <= *size; i++)
    {
        printf("%d ", i);
    }
    printf("\n> ");
    scanf("%d", &ind);

    if (0 <= ind && ind <= (*size + 1))
    {
        *size = *size + 1;

        tab = malloc(sizeof(int) * (*size));

        for (i = 0; i < ind; i++)
        {
            tab[i] = ptab[i];
        }

        tab[ind] = val;
        for (i = (ind + 1); i < *size; i++)
        {
            tab[i] = ptab[i - 1];
        }
        free(ptab);

        return tab;
    }
    else
    {
        printf("Error\n");
        return ptab;
    }
}

void afficher(int *tab, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("Value : %d ; Adresse : %x\n", tab[i], tab + i);
    }
}
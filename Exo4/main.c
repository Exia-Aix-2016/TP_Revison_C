#include <stdio.h>
#include <stdlib.h>

struct res
{
    int *tab;
    int size;
};

void saisir(int *tab, int size);
void afficher(int *tab, int size);
struct res *trouver_doublons(int *tab1, int *tab2, int size1, int size2);

int main()
{
    int *tab1;
    int *tab2;
    int size1;
    int size2;
    struct res *rp;

    while (1)
    {
        system("cls");

        printf("Size1 : ");
        scanf("%d", &size1);

        printf("Size2 : ");
        scanf("%d", &size2);

        tab1 = malloc(sizeof(int) * size1);
        tab2 = malloc(sizeof(int) * size2);

        printf("Tab1 :\n");
        saisir(tab1, size1);
        printf("Tab2 :\n");
        saisir(tab2, size2);

        rp = trouver_doublons(tab1, tab2, size1, size2);

        afficher(rp->tab, rp->size);

        system("pause");
    }
    return 0;
}

void saisir(int *tab, int size)
{
    int i, x;
    for (i = 0; i < size; i++)
    {
        printf("Value %d -> ", i);
        scanf("%d", &x);
        tab[i] = x;
    }
}

void afficher(int *tab, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("Value %d : %d\n", i, tab[i]);
    }
}

struct res *trouver_doublons(int *tab1, int *tab2, int size1, int size2)
{
    struct res r;
    int *tab;
    int *temp;
    int size = 0;
    int i, y, z, w;
    int in;
    int find;
    for (i = 0; i < size1; i++)
    {
        int in = 0;
        for (y = 0; y < size; y++)
        {
            if (tab[y] == tab1[i])
            {
                in = 1;
            }
        }
        if (!in)
        {
            find = 0;
            for (z = 0; z < size2; z++)
            {
                if (z <= size1)
                {
                    if (tab2[z] == tab1[i])
                    {
                        find = 1;
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if (find)
            {
                temp = malloc(sizeof(int) * size);
                for (w = 0; w < size; w++)
                {
                    temp[w] = tab[w];
                }
                size++;
                free(tab);
                tab = malloc(sizeof(int) * size);
                for (w = 0; w < size - 1; w++)
                {
                    tab[w] = temp[w];
                }
                tab[size - 1] = tab1[i];
                free(temp);
            }
        }
    }
    r.size = size;
    r.tab = tab;
    return &r;
}

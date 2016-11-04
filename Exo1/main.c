#include <stdio.h>
#include <stdlib.h>

double carre(double nbr);
void disp(double res);

int main()
{
    double nbr;
    while (1)
    {
        system("cls");
        printf("Votre nombre : ");
        scanf("%lf", &nbr);
        disp(carre(nbr));
        system("pause");
    }
    return 0;
}

double carre(double nbr)
{
    return pow(nbr, 2);
}

void disp(double res)
{
    printf("Votre resultat : %g\n", res);
}

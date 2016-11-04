#include <stdio.h>
#include <stdlib.h>

char *crypt(char *msg, char *key);

int main()
{
    char msg[140];
    char key[140];
    char *res;

    while (1)
    {
        system("cls");

        printf("Key : ");
        fgets(key, 140, stdin);

        printf("Msg : ");
        fgets(msg, 140, stdin);

        res = crypt(msg, key);
        printf("Message encode : %s \n", res);

        printf("Message decode : %s \n", crypt(res, key));

        system("pause");
    }
    return 0;
}

char *crypt(char *msg, char *key)
{
    int i;
    int sm = strlen(msg);
    int sk = strlen(key);
    char *res;

    res = malloc(sizeof(char) * sm);

    for (i = 0; i < sm; i++)
    {
        res[i] = msg[i] ^ key[i % sk];
        printf("%c ^ %c = %c\n", msg[i], key[i % sk], res[i]);
    }
    return res;
}

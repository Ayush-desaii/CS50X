#include <cs50.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int only_digits(string text);

int main(int argc, string argv[])
{
    int i;
    if(!(argc == 2))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    int a = only_digits(argv[1]);
    if(a == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int k = atoi(argv[1]);

    string p = get_string("plaintext:  ");
    string c[strlen(p)];


    printf("ciphertext: ");

    for(i=0;i<strlen(p);i++)
    {
        if(isupper(p[i]))
        {
            printf("%c", ((p[i] - 'A' + k)%26) + 'A');
        }
        else if(islower(p[i]))
        {
            printf("%c", ((p[i] - 'a' + k)%26) + 'a');
        }
        else
        {
            printf("%c",p[i]);
        }
    }

    printf("\n");
    return 0;
}



int only_digits(string text)
{
    int i;
    for(i=0;i<strlen(text);i++)
    {
        if(text[i]<48 || text[i]>57)
        {
            return 1;
        }
    }
    return 0;
}
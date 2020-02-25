//Marcin Nahajowski

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int palindrom(char *wsk)
{
    int dlugosc = 0;
    char *wsk2 = wsk;
    while((*wsk >= 'a' && *wsk <= 'z') || (*wsk >= 'A' && *wsk <= 'Z'))     // znalezienie d³ugoœci ci¹gu znaków i adresu ostatniego wskaŸnika
    {
        wsk++;
        dlugosc++;
    }
    wsk--;
    while(wsk2 < wsk)       // sprawdzanie czy ci¹g znaków jest palindromem
    {
        if(*wsk2 != *wsk)
            return 0;
        wsk2++;
        wsk--;
    }
    return 1;
}
int main ()
{
    char *wsk;
    wsk = (char*)malloc(80*sizeof(char));
    fgets(wsk, 80, stdin);
    char *wsk3 = wsk;
    if(palindrom(wsk) == 1)
    {
        printf("PALINDROM: %s", wsk);
    }
    else
    {
            printf("%s", wsk);
    }
    free (wsk3);
    return 0;
}

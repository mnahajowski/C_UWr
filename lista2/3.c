// Marcin Nahajowski

#include <stdio.h>
#include <math.h>
#include <string.h>
char tab1[6001];
char tab2[6001];
int test_pusty (int n)
{
    for (int i = 0; i < n; i++)
    {
        if(tab2[i] != ' ' && tab2[i] !=  '\t')
        {
            return 1;
        }

    }
    return 0;
}
int test (int a, int b)
{
    if (a != b)
    {
        return 1;
    }
    for (int i = 0; i < a ;i++)
    {
        if (tab1[i] != tab2[i])
        {
            return 1;
        }
    }
    return 0;
}
int main ()
{
    for (int i = 0; i < 6000; i++)
    {
        tab1[i] = ' ';
    }
    int dlugosc = 5999;
    tab1[6000] = '\0';
    while(fgets(tab2, 6001, stdin) != NULL)
    {

        int x = strlen(tab2) - 2;
        if (test_pusty (x) == 1)
        {
            while (tab2[x] == ' ' || tab2[x] == '\t')
            {
                x--;
            }
        }
        if (test(dlugosc, x))
        {
            printf ("%s", tab2);
        }

        for (int i = 0; (tab1[i] = tab2[i]) != '\0'; i++)
        {
            dlugosc = x;
        }
    }

return 0;
}

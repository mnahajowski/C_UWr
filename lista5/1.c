// Marcin Nahajowski

#include <stdio.h>
#include <stdlib.h>
int tab_parz[100];
int SpiralaWiersz(int n, int k, int l)
{
    int i;
    if(n == 1)
    {
        printf("%4d", 1);
        return l;
    }
    if(n % 2 == 0)
    {
        if(k == n)
        {
            i = n*n - 2*n +2;
            while (i <= n*n - n + 1)
            {
                printf("%4d", i);


                i++;
            }
        }
        else
        {
            tab_parz[l] = n*n - n + 1 + (n-k);
            if(n > 2)
            {
                return SpiralaWiersz(n - 1,k,l+1);
            }
            else
            {
                return l;
            }
        }
    }
    else if(n%2 == 1 && n!=1)
    {
        if(k == 1)
        {
            i = n * n - n + 1;
            while (i >= n * n - n + 1 - n + 1)
            {
                printf("%4d", i);
                i--;
            }
        }
        else
        {
            printf("%4d", n*n-(n-k));

            return (SpiralaWiersz(n -1, k -1, l));
        }
    }
    return l;
}
int main(int argc, char **argv)
{
    int l = 0;
    if(argc > 2)
    {
        int a = atoi(argv[1]) ;
        int b = atoi(argv[2]);
        int c = SpiralaWiersz(a, b, l);
        if(b == (a+1) / 2 && a > 1)
        {
            printf("   1");
        }
        while(c >= 0)
        {
            printf("%4d", tab_parz[c]);
            c--;
        }
        return 0;
    }
    int a;
    if(argc < 2)
    {
        a = 17;
    }
    else
    {
        a = atoi(argv[1]);
    }
    for(int i = 1; i<=a; i++)
    {
        int c = SpiralaWiersz(a, i, l);
        if(i == (a+1) / 2 && a > 1)
        {
            printf("   1");
            printf("   4");
        }
        while(c > 0)
        {
            printf("%4d", tab_parz[c-1]);
            c--;
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>
int funkcja (int n)
{
    if (n == 2)
    {
        return 1;
    }
    else if (n%2 != 0)
    {
        for (int i = 3; i * i <=n; i+=2)
        {
            if(n%i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

int main ()
{
    int n;
    scanf ("%d", &n);


int licznik = 0;
if (n<=2 || n%2 == 1)
{
    printf("NIEPOPRAWNA LICZBA");
    return 0;
}
else
{
    for (int i = 2; i <= n/2; i++)
    {
        int a = i;
        int b = n - i;
        if (funkcja(a) == 1 && funkcja(b) == 1)
        {
            licznik++;
            /*
            printf ("%d \t", i);
            printf ("%d \t", j);
            printf("%d", licznik);
            printf ("\n");
            */
        }
    }
}
if (licznik == 0)
{
    printf("NIEPOPRAWNA LICZBA");
}
else
{
    printf("%d", licznik);
}

return 0;
}

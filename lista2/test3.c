//Marcin Nahajowski

#include <stdio.h>
int tab[10000];
char tab2[100000];
char tab4[100000];
char tab5[1];
int NumInput (int baza)
{
    tab5[0] = 0;
    int i = 0;
    int a = getchar();

    while (a != '.')
    {
        while ((a < '0' || a > '9') || a >= (baza + '0'))       //wusuwanie niedopuszczalnych znakow
        {
            if (a == '-')
            {
                tab5[0] = 1;
            }
            a = getchar();
        }
        i++;
        tab[i] = a - '0';
        a = getchar();
    }

    int wynik = 0;

    for (int j = 0; j <= i; j++)        // tworzenie liczby w int
    {
        wynik *=10;
        wynik += tab[j];

    }

    if (tab5[0] == 1)
    {
        putchar('-');       // sprawdzanie znaku
    }

    return wynik;
}
int NumOutput(int baza, int x)
{


    baza = 2;       // wybór systemu, na ktory chcemy zamienic
    int liczba = x;
    int wynik = x;
    int m = 0;

    while (x > 0)
    {

        tab4[m] = x%baza;   // zmiana systemu
        x = x / baza;
        m++;

    }

    int k = 0;

    while (liczba > 0)
    {

        tab2[k] = liczba%10 ;       // wczytywanie liczb w okreslonych systemach do tablic
        liczba = liczba / 10;
        k++;
    }

    for (int i = k-1; i >=0; i--)
    {
        putchar(tab2[i] + '0');
    }

    if(tab[0] != 0)
    {
        putchar('.');
    }

    putchar('\t');

    if(tab5[0] == 1)
    {
        putchar('-');
    }
    for (int i = m -1; i >= 0; i--)         // wypisywania liczb
    {
        putchar(tab4[i] + '0');
    }
    putchar('\n');

    return wynik;

}

int main ()
{
    int baza = 10;
    while (NumOutput (baza, NumInput(baza)) !=0)
    {

    }

    return 0;
}

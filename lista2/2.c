//Marcin Nahajowski

#include <stdio.h>
int tab_liczba1[10000];
int tab_liczba2[10000];
char tab_znak[1];
char tablica2[10000];
char tab2[100000];
char tab4[100000];
char tab5[1];
char tab6[10000];
int NumInput (int baza)
{
    baza = baza;
    tab5[0] = 0;
    int i = -1;
    int a = getchar();
    int kropka = 0;
    int k = -1;
    tab_liczba2[0] = 0;
    while (kropka != 2 && tab_znak[0] != '!')
    {
        while (a == ' ')
        {
                a = getchar();
        }
        if(a == '.')
        {
            kropka++;
        }
        if(kropka ==1 && tab_liczba2[0] == 0)           // deklaracje pierwszej i drugiej liczby
        {
            a = getchar();
            while (a == ' ')
            {
                a = getchar();
            }
            tab_znak[0] = a;

            a = getchar();
            while (a == ' ')
            {
                a = getchar();
            }
        }


        if (kropka == 0)
        {

            i++;
            tab_liczba1[i] = a - '0';


        }

        else if(kropka == 1)
        {
            k++;
            tab_liczba2[k] = a - '0';



        }

        if (kropka != 2 && tab_znak[0] != '!')
        {
            a = getchar();

        }

    }


    int wynik1 = 0;
    int wynik2 = 0;

    for (int j = 0; j <= i; j++)        // tworzenie liczby w int
    {

        wynik1 *=10;
        wynik1 += tab_liczba1[j];

    }
    for (int j = 0; j <= k; j++)        // tworzenie liczby w int
    {

        wynik2 *=10;
        wynik2 += tab_liczba2[j];

    }

    int koniec = 10000000;
    if (wynik1 == 0)
    {
        return koniec;
    }
    int wynik_calk = 0;
    if(tab_znak[0] == '+')
    {
        wynik_calk = wynik1 + wynik2;
    }
    if(tab_znak[0] == '-')
    {
        wynik_calk = wynik1 - wynik2;
    }
    if(tab_znak[0] == '*')
    {
        wynik_calk = wynik1 * wynik2;
    }
    if(tab_znak[0] == '/')
    {
        wynik_calk = wynik1 / wynik2;
    }
    if(tab_znak[0] == '!')
    {
        wynik_calk = 1;
        for (int o = wynik1; o > 0; o--)
        {
            wynik_calk *=o;
        }
    }



    if (tab5[0]%2 == 1)
    {
        putchar('-');
    }

    return wynik_calk;
}
int NumOutput(int baza, int x)
{


    if (x == 10000000)
    {
        return 0;
    }
    baza = 16;       // wybór systemu, na ktory chcemy zamienic
    int liczba = x;
    int e = x;
    int d = 0;
    while (e > 0)
    {

        tablica2[d] = e%10 ;       // wczytywanie liczb w okreslonych systemach do tablic
        e = e / 10;
        d++;
    }

    for (int i = d-1; i >=0; i--)
    {
        putchar(tablica2[i] + '0');
    }
    putchar('\t');

    int wynik = x;
    int m = 0;
    int n = 0;
    if (baza == 16)
    {

        while (wynik > 0)
        {

            if(wynik%baza == 10)
            {
                tab6[n] = 'A';

            }
            else if(wynik%baza == 11)
            {
                tab6[n] = 'B';
            }
            else if(wynik%baza == 12)
            {
                tab6[n] = 'C';
            }
            else if(wynik%baza == 13)
            {
                tab6[n] = 'D';
            }
            else if(wynik%baza == 14)
            {
                tab6[n] = 'E';
            }
            else if(wynik%baza == 15)
            {
                tab6[n] = 'F';
            }
            else if(wynik%baza < 10)
            {
                tab6[n] = wynik%baza +'0';

            }
            wynik = wynik/baza;
            n++;
        }


        for (int u = n-1; u >=0; u--)
        {
            putchar(tab6[u]);
        }

    }
    else

    {


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

        if(tab_liczba1[0] != 0)
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
    return wynik;
}

int main ()
{
    int baza = 10;
    while (NumOutput (baza, NumInput(baza)))
    {

    }

    return 0;
}

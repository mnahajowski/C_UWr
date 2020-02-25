// Marcin Nahajowski

#include <stdio.h>
#include <math.h>
#define Pi 3.14
double zamiana_x(double x, double y, double r)      // funkcja zamieniajaca 1 wspolrzedna na wspolrzedna ukladu kartezjanskiego
{
    double a;
    a = r * cos(x/180*Pi) * cos(y/180*Pi);
    return a;
}
double zamiana_y(double x, double y, double r)  // funkcja zamieniajaca 1 wspolrzedna na wspolrzedna ukladu kartezjanskiego
{
    double a;
    a = r * sin(x/180*Pi) * cos(y/180*Pi);
    return a;
}


double function(double poprzedni_x, double poprzedni_y, double nowy_x, double nowy_y)       // obliczanie dlugosci wektora
{
    double dlugosc = 0;
    double a = (nowy_x - poprzedni_x)*(nowy_x - poprzedni_x);
    double b = (nowy_y - poprzedni_y)*(nowy_y - poprzedni_y);
    dlugosc = sqrt(a + b);
    return dlugosc;
}
void zeruj(char tab[], int n)      // czyszczenie tablicy przechowujacej znak np. <trkpt
{
    for(int i = 0; i < n; i++)
    {
        tab[i] = '0';
    }
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        return 0;
    }
    char tab[10]; // tablica przechowuja czy tam jest trktpl
    int licznik_wierszy = 0;
    int licznik_znakow = 0;
    double dlugosc_sciezki = 0.0;
    int ilosc_punktow = 0;
    double poprzedni_x = 0.0, poprzedni_y = 0.0;
    double nowy_x = 0.0, nowy_y = 0.0;
    const double r = 6371.0; // w kilmoetrach
    FILE *plik = fopen(argv[1], "r");
    char sign;
    int a = 0; // indeks w tablicy na trkpt
    int ilosc_liczb = 0;

    while(fscanf(plik, "%c", &sign) != EOF)     // wczytywanie po znaku do konca pliku
    {
        licznik_znakow++;

        if(sign == '\n')        // zliczanie wierszy
        {
            licznik_wierszy++;
        }

        if((a == 0 && sign == '<') || (a == 1 && sign == 't') || (a == 2 && sign == 'r') || (a == 3 && sign == 'k') || (a == 4 && sign == 'p') || (a == 5 && sign == 't'))      // sprawdzanie czy ciag znakow to <trkpt
        {
            tab[a] = sign;
            a++;
        }
        else if((a == 1 && sign != 't') || (a == 2 && sign != 'r') || (a == 3 && sign != 'k') || (a == 4 && sign != 'p') || (a == 5 && sign != 't'))        // sprawdzenie czy ciag znakow zaczynajacy sie podobnie jak <trkpt to na pewno ten ciag znakow a nie na przyklad <time
        {
            zeruj(tab,a);
            a = 0;
        }

        if((a == 6 && sign == '"' && ilosc_liczb == 0) || (a == 6 && sign == '"' && ilosc_liczb == 2 && nowy_x == poprzedni_x && nowy_y == poprzedni_y)) // znalezismy <trkpt
        {
            nowy_x = 0.0;
            fscanf(plik, "%c", &sign);
            licznik_znakow++;
            while(sign !=  '.')         // wczytywanie do '.' czesci calkowitej i mnozenie przez 10
            {
                nowy_x *=10.0;
                nowy_x += (sign - '0');
                fscanf(plik, "%c", &sign);
                licznik_znakow++;
            }

            fscanf(plik, "%c", &sign);
            licznik_znakow++;
            double dzielnik = 10.0;

            while(sign != '"')          // wczytywanie do '"' czesci ulamkowej i dzielenie przez 10
            {
                nowy_x += ((sign - '0')/dzielnik);
                dzielnik *=10.0;
                fscanf(plik, "%c", &sign);
                licznik_znakow++;
            }

            ilosc_liczb = 1;
            fscanf(plik, "%c", &sign);
            licznik_znakow++;
        }

        if(a == 6 && sign == '"' && ilosc_liczb == 1)
        {
            nowy_y = 0.0;
            fscanf(plik, "%c", &sign);
            licznik_znakow++;
            while(sign !=  '.')                 // wczytywanie do '.' czesci calkowitej i mnozenie przez 10
            {
                nowy_y *=10.0;
                nowy_y += (sign - '0');
                fscanf(plik, "%c", &sign);
                licznik_znakow++;
            }

            fscanf(plik, "%c", &sign);
            licznik_znakow++;
            double dzielnik = 10.0;

            while(sign != '"')              // wczytywanie do '"' czesci ulamkowej i dzielenie przez 10
            {
                nowy_y += ((sign - '0')/dzielnik);
                dzielnik *=10.0;
                fscanf(plik, "%c", &sign);
                licznik_znakow++;
            }

            ilosc_liczb = 2;
            fscanf(plik, "%c", &sign);
            licznik_znakow++;
            double xx = zamiana_x(nowy_x, nowy_y, r);       // zamiana 1 wspolrzednej na wspolrzedna w ukladzie kartezjanskim
            double yy = zamiana_y(nowy_x, nowy_y, r);       // zamiana 2 wspolrzednej na wspolrzedna w ukladzie kartezjanskim
            nowy_x = xx;
            nowy_y = yy;
            a = 0;

            if(poprzedni_x == 0.0 && poprzedni_y == 0.0)
            {
                poprzedni_x = nowy_x;
                poprzedni_y = nowy_y;
                a = 6;
            }

            ilosc_punktow++;
        }

        if(ilosc_liczb == 2 && poprzedni_x != nowy_x && poprzedni_y != nowy_y)          // zliczanie dlugosci sciezki na podstawie sumy dlugosci poszczegolnych wektorow
        {
                dlugosc_sciezki += function(poprzedni_x, poprzedni_y, nowy_x, nowy_y);
                poprzedni_x = nowy_x;
                poprzedni_y = nowy_y;
                zeruj(tab,11);
                ilosc_liczb = 0;
        }
    }

    printf("%d %d %d %f", licznik_znakow, licznik_wierszy, ilosc_punktow, dlugosc_sciezki);     // wypisanie wynikow
    fclose(plik);
    return 0;
}

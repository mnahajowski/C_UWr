// Marcin Nahajowski

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h.>
typedef struct liczba{      // struktura
    float a;
    float b;
}Liczba;

bool czy_przedzial(Liczba liczba)           // sprawdzanie czy punkt nalezy do przedzialu
{
    if(((liczba.a)*(liczba.a) + (liczba.b) * (liczba.b)) < 4)
    {
        return 1;
    }
    return 0;
}

Liczba odejmowanie(Liczba liczba, Liczba liczba2)       // odejmowanie liczb zespolonych
{
    liczba.a = liczba.a - liczba2.a;
    liczba.b = liczba.b - liczba2.b;
    return liczba;
}

Liczba iteracja(Liczba liczba, Liczba liczba2)      // mnozenie liczb zespolonych i wywolywanie funkcji na odejmowanie liczb zespolonych
{
    Liczba liczba_dod;
    liczba_dod.a = liczba.a;
    liczba_dod.b = liczba.b;
    liczba.a = liczba.a * liczba.a - liczba.b * liczba.b;
    liczba.b = liczba_dod.a * liczba.b + liczba_dod.a * liczba.b;
    return odejmowanie(liczba, liczba2);

}

int main(int argc, char *argv[])
{
    Liczba a;
    a.a = -1.0;
    a.b = 1.0;
    Liczba c;
    float y, x;

    if(argc < 3)            // sprawdzanie i pobieranie rozdzielczosci jako argumentow wywolania programu
    {
        y = 40;
        x = 25;
    }
    else
    {
        y = atoi(argv[1]);
        x = atoi(argv[2]);
    }

    if(argc < 5)        // sprawdzanie i pobieranie czesci rzeczywiste i urojonej stalej c jako argumentow wywolania programu
    {
        c.a = 0.1;
        c.b = 0.83;
    }
    else
    {
        c.a = atof(argv[3]);
        c.b = atof(argv[4]);
    }

    float przeskok_x = 2.0 / (x-1.0);
    float przeskok_y = 2.0 / (y-1.0);
    Liczba liczba1;
    Liczba liczba2; // 2 struktury pomocnicze

    while(a.b >=  -1.0)
    {
        liczba1.b = a.b;
        while(a.a <= 1.0)
        {
            liczba1.a = a.a;
            liczba1.b = a.b;

            for(int i = 0; i < 200; i++)
            {
                liczba2 = iteracja(a, c);
                a.a = liczba2.a;
                a.b = liczba2.b;
            }

            if(czy_przedzial(a))
            {
                printf("O");
            }
            else
            {
                printf(" ");
            }

            a.a = liczba1.a;
            a.b = liczba1.b;
            a.a += przeskok_y;

        }
        printf("\n");
        a.a = -1.0;
        a.b = liczba1.b;
        a.b -= przeskok_x;
    }

    return 0;
}

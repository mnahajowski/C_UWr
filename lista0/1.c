#include <stdio.h>
int main()
{
    int liczba;
    scanf ("%d", &liczba);
    int liczba2 = liczba;
    int poczatek = liczba;
    int licznik = 0;
    while (liczba2 > 0)
    {
        licznik++;
        liczba2=liczba2/10;
    }
    int liczba3;
    int wynik = 0;
    while (liczba > 0)
    {
        liczba3 = liczba%10;
         liczba=liczba/10;
            int potega = licznik;
            int wynik1 = 1;
            while (potega > 0)
            {
                wynik1 = wynik1 * liczba3;
                potega--;
            }
        wynik = wynik + wynik1;
    }
    if (wynik == poczatek)

        printf ("TAK");
    else
        printf("NIE");
    return 0;
}

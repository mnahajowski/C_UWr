#include <stdio.h>
#include <stdbool.h>
int tab[201][21];
int main()
{
    int liczba;
    int ilosc_czasow;
    scanf("%d", &liczba);
    if(liczba == 0)
    {
        return 0;
    }
    for (int i = 0; i < liczba; i++)
    {
        int czas;
        scanf("%d", &czas);
        scanf("%d", &ilosc_czasow);
        int j = 2;
        tab[0][i] = czas;
        tab[1][i] = ilosc_czasow;
        while (j <= ilosc_czasow+1)
        {
            int godzina, minuta;
            scanf("%d", &godzina);
            scanf("%d", &minuta);
            godzina *=60;
            tab[j][i] = tab[j][i] + godzina + minuta;
            j++;
        }
    }
    unsigned long long czas_min = 1000000;
    unsigned long long suma_czas = 0;
    int aktualny_czas = 0;
    int godzina_min;
    int numer = 1;
    bool test = false;
    int czas_obecny = 0;
    for(int i = 2; i <=tab[1][0]+1; i++)
    {
        aktualny_czas = tab[i][0];
        suma_czas = tab[0][0];
        int komorka = 2;
        czas_obecny = tab[i][0] + tab[0][0];
        while(numer < liczba)
        {
            czas_obecny = czas_obecny%1440;
            if(czas_obecny <= tab[komorka][numer])
            {
                test = true;
                suma_czas = suma_czas + tab[0][numer] + (tab[komorka][numer] - czas_obecny);
                czas_obecny = tab[komorka][numer] + tab[0][numer];
            }
            else
            {
                komorka++;
            }

           if(test == false && komorka == tab[1][numer]+ 2)
            {
                suma_czas = suma_czas + tab[0][numer] + (tab[2][numer] - czas_obecny + 1440);
                czas_obecny = tab[2][numer] + tab[0][numer];
                numer++;
                komorka = 2;
                test = false;
            }
            if(test == true)
            {
                numer++;
                komorka = 2;
                test = false;
            }
        }
        numer = 1;
        if(suma_czas < czas_min)
        {
            czas_min = suma_czas;
            godzina_min = aktualny_czas;
        }
        suma_czas = 0;
    }
    int godziny, minuty;
    godziny = godzina_min / 60;
    minuty = godzina_min%60;
    int godziny2, minuty2;
    godziny2 = czas_min /60;
    minuty2 = czas_min%60;
    printf("%d %d %d %d", godziny, minuty, godziny2, minuty2);

    return 0;
}

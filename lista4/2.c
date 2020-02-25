#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
typedef unsigned short TypDaty;
char *DniTyg[] = {"pon", "wto", "sro", "czw", "pia", "sob", "nie"};
int DlugMies[] = {31,28,31,30,31,30,31,31,30,31,30,31};
char *NazwaRoku[] = {"rok malpy", "rok koguta", "rok swini", "rok szczura", "rok tygrysa", "rok krolika", "rok smoka", "rok weza", "rok konia", "rok owcy", "rok kozy", "rok psa"};
char *NazwaMiesiaca[] = {"stycznia", "lutego", "marca", "kwietnia", "maja", "czerwca", "lipca", "sierpnia", "wrzesnia", "pazdziernika", "listopada", "grudnia"};
bool tab[17];
int tab_sum[5];
int tab_bin[20];
TypDaty ZrobDate(short dt, short d, short m, short rok)
{
    int i = 3;
    while(i >=0)
    {
        tab_bin[i] = rok%2;
        rok = rok/2;
        i--;
    }

    i = 7;
    while(i>=4)
    {
        tab_bin[i] = m%2;
        m = m/2;
        i--;
    }

    i = 12;
    while(i >= 8)
    {
        tab_bin[i] = d%2;
        d = d/2;
        i--;
    }

    i = 15;
    while(i >= 13)
    {
        tab_bin[i] = dt%2;
        dt = dt/2;
        i--;
    }
    int suma = 0;
    int mnoznik = 1;
    for (int j = 15; j >=0; j--)
    {
        suma+= tab_bin[j]*mnoznik;
        mnoznik *=2;
    }
    return suma;
}
TypDaty NumerDni (short d, short m, short rok)
{
    int suma = 0;
    suma += (rok-1) * 365 + d + m*31 - (m/2);
    if(m > 2)
        suma -=2;
    return suma;
}
TypDaty BladDaty (TypDaty data)
{
    bool test2 = true;
    TypDaty liczba = data;
    int s1=0;
    int i = 0;
    int mnoznik = 1;
    while(i < 3)
    {
        s1+=(liczba&1) * mnoznik;
        liczba>>=1;
        mnoznik *=2;
        i++;
    }
    if(s1 < 1 || s1 > 7)
    {
        int k = 16;
        while (k > 13)
        {
            data = data | (1 << k);
            k--;
            tab[k] = true;
        }
        test2 = false;
    }
    else
        tab_sum[0] = s1;
    int s2 = 0;
    mnoznik = 1;
    i = 0;
    while (i < 5)
    {
        s2 += (liczba&1) * mnoznik;
        liczba>>=1;

        mnoznik *=2;
        i++;
    }
    if(s2 < 1 || s2 > 31)
    {
        int k =13;
        while(k > 8)
        {
            data = data | (1 << k);
            k--;
            tab[k] = true;
        }
        test2 = false;
    }
    else
        tab_sum[1] = s2;
    int s3 = 0;
    mnoznik = 1;
    i = 0;
    while (i < 4)
    {
        s3 += (liczba&1) * mnoznik;
        liczba >>=1;
        mnoznik *=2;
        i++;
    }
    if (s3 < 1 || s3 > 12)
    {
        int k = 8;
        while (k > 4)
        {
            data = data | (1 << k);
            k--;
            tab[k] = true;
            test2= true;
        }
        test2= false;
    }
    else
        tab_sum[2] = s3;
    if(s2 > DlugMies[s3-1])
    {
        int k = 13;
        while (k > 4)
        {
            data = data | (1 << k);
            k--;
            tab[k] = true;
        }
        test2 = false;
    }
    int s4 = 0;
    mnoznik= 1;
    i = 0;
    while (i < 4)
    {
        s4 += (liczba&1) * mnoznik;
        liczba >>=1;
        mnoznik *=2;
        i++;
    }
    if(s4 < 1 || s4 > 12)
    {
        int k = 4;
        while (k > 0)
        {
            data = data | (1 << k);
            k--;
            tab[k] = true;
        }
        test2 = false;
    }

    else
        tab_sum[3]  = s4;
    if (test2 == false)
        return data;
    else
        return 0;
}
void WypiszDate(int tab_sum[4])
{
    printf("%s , \t", DniTyg[tab_sum[0]-1]);
    printf("%d ",  tab_sum[1]);
    printf("%s, \t ", NazwaMiesiaca[tab_sum[2]-1]);
    printf("%s", NazwaRoku[tab_sum[3]-1]);
    printf("(%d) \n", tab_sum[3]);
}
int main ()
{
    short int dt1, d1, m1, rok1;
    scanf("%hd %hd %hd %hd", &dt1, &d1 , &m1, &rok1);
    if(dt1 == 0)
        return 0;

    short dt2, d2, m2, rok2;
    scanf("%hd %hd %hd %hd", &dt2, &d2, &m2, &rok2);
    if(dt2 == 0)
        return 0;
//   int liczba = 1;
//   bool czy_poprawna = true;
    while(dt1 != 0 && dt2 !=0)
    {

        TypDaty x = BladDaty(ZrobDate(dt1, d1, m1, rok1));
        if(x == 0)
        {
            /*          if(liczba%2 == 1)
                          czy_poprawna = true;
             */         WypiszDate (tab_sum); // jeszcze roznica
            for (int i = 0; i < 16; i++)
            {
                printf("%d", tab_bin[i]);
            }
            printf("\n");





        }
        else
        {
            for(int i = 15; i >=0; i--)
            {
                if(tab[i] == true)
                    printf("%d \t", 16 - i);
            }
            printf("\n");
            /*          if(liczba%2 == 1)
                          czy_poprawna = false;
             */
        }
        TypDaty y = BladDaty(ZrobDate(dt2, d2, m2, rok2));
        if(y == 0)
        {
            /*          if(liczba%2 == 1)
                          czy_poprawna = true;
             */         WypiszDate (tab_sum); // jeszcze roznica
            for (int i = 0; i < 16; i++)
            {
                printf("%d", tab_bin[i]);
            }
            printf("\n");





        }
        else
        {
            for(int i = 15; i >=0; i--)
            {
                if(tab[i] == true)
                    printf("%d \t", 16 - i);
            }
            printf("\n");
            /*          if(liczba%2 == 1)
                          czy_poprawna = false;
             */
        }
        if(x == 0 && y == 0)
        {
            int a = NumerDni(d1, m1, rok1);
            int b = NumerDni(d2, m2, rok2);
            if(a > b)
            {
                printf("%d \n", a-b);
            }
            else
            {
                printf("%d \n", b - a);
            }
        }


        scanf("%hd %hd %hd %hd", &dt1, &d1, &m1, &rok1);
        scanf("%hd %hd %hd %hd", &dt2, &d2, &m2, &rok2);
    }

    return 0;
}

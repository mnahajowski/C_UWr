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
    TypDaty data;
    scanf ("%hu", &data);
    while (data != 0)
    {
        TypDaty x = BladDaty(data);
        if(x == 0)
        {
            WypiszDate (tab_sum);
        }
        else
        {
            for(int i = 15; i >=0; i--)
            {
                if(tab[i] == true)
                    printf("%d \t", 16 - i);
            }
            printf("\n");
        }
        scanf("%hu", &data);
    }
    return 0;
}

#include <stdio.h>

void funkcja(int kolumna, char tab[][kolumna+2], int kroki[][kolumna+2], int kolumna_numer, int wiersz_numer)
{

    if(tab[wiersz_numer+1][kolumna_numer] == '-' && (kroki[wiersz_numer+1][kolumna_numer] == 0 || kroki[wiersz_numer][kolumna_numer]+1 < kroki[wiersz_numer+1][kolumna_numer]))
    {
        kroki[wiersz_numer+1][kolumna_numer] = kroki[wiersz_numer][kolumna_numer]+1;
        funkcja(kolumna, tab, kroki, kolumna_numer, wiersz_numer+1);
    }


    if(tab[wiersz_numer][kolumna_numer+1] == '-' && (kroki[wiersz_numer][kolumna_numer+1] == 0 || kroki[wiersz_numer][kolumna_numer]+1 < kroki[wiersz_numer][kolumna_numer+1]))
    {
        kroki[wiersz_numer][kolumna_numer+1] = kroki[wiersz_numer][kolumna_numer]+1;
        funkcja(kolumna, tab, kroki, kolumna_numer+1, wiersz_numer);
    }


    if(tab[wiersz_numer][kolumna_numer-1] == '-' && (kroki[wiersz_numer][kolumna_numer-1] == 0 || kroki[wiersz_numer][kolumna_numer]+1 < kroki[wiersz_numer][kolumna_numer-1]))
    {
        kroki[wiersz_numer][kolumna_numer-1] = kroki[wiersz_numer][kolumna_numer]+1;
        funkcja(kolumna, tab, kroki, kolumna_numer-1, wiersz_numer);
    }


    if(tab[wiersz_numer-1][kolumna_numer] == '-' && (kroki[wiersz_numer-1][kolumna_numer] == 0 || kroki[wiersz_numer][kolumna_numer]+1 < kroki[wiersz_numer-1][kolumna_numer]))
    {
        kroki[wiersz_numer-1][kolumna_numer] = kroki[wiersz_numer][kolumna_numer]+1;
        funkcja(kolumna, tab, kroki, kolumna_numer, wiersz_numer-1);
    }

}

int main()
{
    int wiersz = 0;
    int kolumna = 0;
    int a=0, b=0;

    scanf("%d %d", &wiersz, &kolumna);
    char tab[wiersz+2][kolumna+2];

    for(int i=0; i<wiersz; i++)
    {
        for(int j=0; j<kolumna+1; j++)
        {
            scanf("%c", &tab[i][j]);
        }
        tab[i][kolumna+1] = '#';
    }



    for(int i=0; i<wiersz; i++)
    {
        for(int j=0; j<kolumna; j++)
        {
            tab[i][j] = tab[i][j+1];
            if(tab[i][j]=='!')
            {
                a = i;b = j;
            }
        }
    }

    int kroki[wiersz+2][kolumna+2];

    for(int i=0; i<wiersz; i++)
    {
        for(int j=0; j<kolumna; j++)
        {
            kroki[i][j] = 0;
        }
    }

    funkcja(kolumna, tab, kroki, b, a);

    int maxim=0;

    for(int i=0; i<wiersz; i++)
    {
        for(int j=0; j<kolumna; j++)
        {
            if(kroki[i][j]==0 && tab[i][j]=='-')
            {
                printf("-1");
                return 0;
            }
        }
    }

    for(int i=0; i<wiersz; i++)
    {
        for(int j=0; j<kolumna; j++)
        {
            if(kroki[i][j] > maxim)
            {
                maxim = kroki[i][j];
            }
        }
    }

    printf("%d", maxim);

    return 0;
}

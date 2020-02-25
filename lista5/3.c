#include <stdio.h>

void dol_rzad(int kolumna, int wiersz, int tab[][wiersz], int numer)
{
    int granica = 0;
    granica = numer;

    for(int i=0; i<kolumna; i++)
    {
        tab[i][numer] = 0;
    }

    while(granica > 0)
    {
        for(int i=0; i<kolumna; i++)
        {
            tab[i][granica] = tab[i][granica - 1];
        }
        granica--;
    }

    for(int i=0; i<kolumna; i++)
    {
        tab[i][0] = 0;
    }
}


void pelne_linie(int kolumna, int wiersz, int tab[][wiersz])
{
    int test;
    test = 1;

    for(int i=0; i<wiersz; i++)
    {
        test = 1;
        for(int j=0; j<kolumna; j++)
        {
            if(tab[j][i] == 0)
            {
                test = 0;
            }
        }
        if(test == 1)
        {
            dol_rzad(kolumna, wiersz, tab, i);
        }
    }

}
void figury(int numer_kolumny, int numer_wiersza, int tab[][numer_wiersza], char c, int poczatek)
{
    int i;
    i = 0;

    if(c=='K')
    {
        while(tab[poczatek][i+1]==0 && tab[poczatek+1][i+1] == 0 && i+1 < numer_wiersza)
        {
            i++;
        }

        tab[poczatek][i] = 1;
        tab[poczatek+1][i] = 1;
        tab[poczatek][i-1] = 1;
        tab[poczatek+1][i-1] = 1;

    }
    else if(c=='T')
    {
        while(tab[poczatek+1][i+1]==0 && tab[poczatek][i] == 0 && tab[poczatek+2][i] == 0 && i+1 < numer_wiersza)
        {
            i++;
        }

        tab[poczatek][i-1] = 1;
        tab[poczatek+1][i-1] = 1;
        tab[poczatek+1][i] = 1;
        tab[poczatek+2][i-1] = 1;

    }
    else if(c=='I')
    {
        while(tab[poczatek][i+1]==0 && i+1 < numer_wiersza)
        {
            i++;
        }

        tab[poczatek][i]=1;
        tab[poczatek][i-1]=1;
        tab[poczatek][i-2]=1;
        tab[poczatek][i-3]=1;

    }
    else if(c=='F')
    {
        i++;
        while(tab[poczatek][i+1] == 0 && tab[poczatek+1][i-1] == 0 && i+1<numer_wiersza)
        {
            i++;
        }

        tab[poczatek][i] = 1;
        tab[poczatek][i-1] = 1;
        tab[poczatek][i-2] = 1;
        tab[poczatek+1][i-2] = 1;

    }
    else if(c=='W')
    {
        while(tab[poczatek][i+1] == 0 && tab[poczatek+1][i+1] == 0 && tab[poczatek+2][i+1] == 0 && tab[poczatek+3][i+1] == 0 && tab[poczatek+4][i+1] == 0 && i+1 < numer_wiersza)
        {
            i++;
        }

        tab[poczatek][i] = 1;
        tab[poczatek+1][i] = 1;
        tab[poczatek+2][i] = 1;
        tab[poczatek+3][i] = 1;
        tab[poczatek+4][i] = 1;
        tab[poczatek][i-1] = 1;
        tab[poczatek][i-2] = 1;
        tab[poczatek+2][i-1] = 1;
        tab[poczatek+2][i-2] = 1;
        tab[poczatek+4][i-1] = 1;
        tab[poczatek+4][i-2] = 1;
    }
    else if(c=='*')
    {
        while(tab[poczatek][i+1] == 0 && i+1 < numer_wiersza)
        {
            i++;
        }

        if(poczatek == 0)
        {
            if(i==0)
            {
                tab[0][0] = 0;
                tab[poczatek][i+1] = 0;
                tab[poczatek+1][i] = 0;
                tab[poczatek+1][i+1] = 0;

            }
            else if(i == numer_wiersza-1)
            {
                tab[poczatek][i] = 0;
                tab[poczatek][i-1] = 0;
                tab[poczatek+1][i-1] = 0;
                tab[poczatek+1][i] = 0;

            }
            else
            {
                tab[poczatek][i] = 0;
                tab[poczatek][i-1] = 0;
                tab[poczatek][i+1] = 0;
                tab[poczatek+1][i] = 0;
                tab[poczatek+1][i+1] = 0;
                tab[poczatek+1][i-1] = 0;

            }

        }
        else if(poczatek == numer_kolumny-1)
        {
            if(i==0)
            {
                tab[poczatek][i] = 0;
                tab[poczatek-1][i] = 0;
                tab[poczatek-1][i+1] = 0;
                tab[poczatek][i+1] = 0;

            }
            else if(i == numer_wiersza-1)
            {
                tab[poczatek][i] = 0;
                tab[poczatek][i-1] = 0;
                tab[poczatek-1][i-1] = 0;
                tab[poczatek-1][i] = 0;

            }
            else
            {
                tab[poczatek][i] = 0;
                tab[poczatek][i-1] = 0;
                tab[poczatek][i+1] = 0;
                tab[poczatek-1][i-1] = 0;
                tab[poczatek-1][i] = 0;
                tab[poczatek-1][i+1] = 0;
            }

        }
        else
        {
            if(i==0)
            {
                tab[poczatek][i] = 0;
                tab[poczatek-1][i] = 0;
                tab[poczatek+1][i] = 0;
                tab[poczatek-1][i+1] = 0;
                tab[poczatek][i+1] = 0;
                tab[poczatek+1][i+1] = 0;

            }
            else if(i == numer_wiersza-1)
            {
                tab[poczatek][i] = 0;
                tab[poczatek-1][i] = 0;
                tab[poczatek+1][i] = 0;
                tab[poczatek][i-1] = 0;
                tab[poczatek-1][i-1] = 0;
                tab[poczatek+1][i-1] = 0;

            }
            else
            {
                tab[poczatek-1][i-1] = 0;
                tab[poczatek][i-1] = 0;
                tab[poczatek+1][i-1] = 0;
                tab[poczatek-1][i] = 0;
                tab[poczatek][i] = 0;
                tab[poczatek+1][i] = 0;
                tab[poczatek-1][i+1] = 0;
                tab[poczatek][i+1] = 0;
                tab[poczatek+1][i+1] = 0;
            }
        }
    }

    i = 0;
}


int main()
{
    int kolumna;
    int wiersz;
    int x;
    char c;

    int k=0;

    scanf("%d %d %d", &kolumna, &wiersz, &k);
    if(wiersz < 0 || kolumna < 0 || k < 0)
    {
        return 0;
    }
    int tab[kolumna][wiersz];

    for(int i=0; i<wiersz; i++)
    {
        for(int j=0; j<kolumna; j++)
        {
            tab[j][i] = 0;
        }
    }


    for(int i=0; i<k; i++)
    {
        c = getchar();
        scanf("%c %d", &c, &x);
        figury(kolumna, wiersz, tab, c, x);
        pelne_linie(kolumna, wiersz, tab);
    }

    char koniec_tab[kolumna][wiersz];

    for(int i=0; i<wiersz; i++)
    {
        for(int j=0; j<kolumna; j++)
        {
            koniec_tab[j][i] = '.';
        }
    }

    for(int i=0; i<wiersz; i++)
    {
        for(int j=0; j<kolumna; j++)
        {
            if (tab[j][i] == 1)
            {
                koniec_tab[j][i] = 'X';
            }
        }
    }

    for(int i=0; i<wiersz; i++)
    {
        for(int j=0; j<kolumna; j++)
        {
            printf("%c", koniec_tab[j][i]);
        }
        printf("\n");
    }

    return 0;
}

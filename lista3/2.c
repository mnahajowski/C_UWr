// Marcin Nahajowski

#include <stdio.h>
#include <stdbool.h>
char tablica[2001];
void zeruj (char tablica[])
{
    for (int i = 0; i < 2000; i++)
    {
        tablica[i] = ' ';
    }
}
void print(char tablica[])
{
    for (int i = 0; i < 2000; i++)
    {
        if(i % 80 == 0)
        {
            printf("\n ");
        }
        printf("%c", tablica[i]);
    }

}
void odwroc (char tablica[])
{
    char tablica2[2001];
    for (int i = 0; i < 2000; i++)
    {
        tablica2[i] = tablica[i];
    }
    for(int i = 0; i <2000 ; i++)
    {
        tablica[i]  = tablica2[1999-(i/80+1)*80+i%80+1];
    }
}
bool czy_w_kole (int x, int x0, int y, int y0, int r)
{
    if ((x - x0)*(x-x0)+ (y-y0)*(y-y0) <= r *r)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void DrawElip (int x0, int y0, int r)
{
    y0++;
    int i = 0;
    for (int x = 1; x <= 25; x++)
    {
        for (int y = 0; y < 80; y++)
        {
            if (czy_w_kole(x, y0, y, x0, r))
            {
                tablica[i] = 'X';
            }

            i++;
        }
    }
}
void DrawRect (int x0, int y0, int w, int h)
{
    y0++;
        int i = 0;
    for (int x = 1; x <= 25; x++)
    {
        for (int y = 0; y < 80; y++)
        {
            if (x >= y0 && y >=x0 && x <y0+h && y<x0+w)
            {
                tablica[i] = 'X';
            }
            i++;
        }

    }
}
void trojkat (int x0, int y0, int dl)
{
    y0++;
    int i = 0;
    int licznik = 0;
    for (int x = 1; x <=25; x++)
    {
        for (int y = 0; y < 80; y++)
        {
            if(x >= y0 && y >= x0 && y<=x0+dl && dl > 0)
            {
                tablica[i] = 'X';
                licznik++;
                if(licznik == dl)
                {
                    dl -=2;
                    x0++;
                    y0++;
                    licznik = 0;
                }
            }
            i++;
        }
    }
}
void choinka(int x0, int y0, int wys)
{
    y0++;
    int i =0;
    int dl = 1;
    int h = 0;
    int licznik = 0;
    int x2 = x0;
    int y2 = y0;
    for (int x = 1; x <=25; x++)
    {
        for (int y = 0; y < 80; y++)
        {
            if(x >= y0 && y >= x0 && y <=x0+dl && h < wys)
            {
                tablica[i] = 'X';
                licznik++;
                if (licznik == dl)
                {
                    dl +=2;
                    x0--;
                    y0++;
                    h++;
                    licznik = 0;
                }
            }
            i++;
        }
    }
    int pien = 0;
    int pien_dl = wys/4;
    if(pien_dl == 0)
    {
        pien_dl = 1;
    }
    while(pien < pien_dl)
    {
        tablica[(y2-1)*80+wys*80+x2+pien*80] = 'X';
        pien++;
    }
}

int main()
{
    char tab[100];
    fgets(tab, 100, stdin);
    for (int i = 0; i < 2000; i++)
    {
        tablica[i] = ' ';
    }
    int  b, c, d, e;
    char a;
    sscanf (tab, "%c %d %d %d %d", &a,&b,&c,&d, &e );
    while (a != 'q')
    {
        if(a == 'c')
        {
            DrawElip(b,c,d);
        }
        if (a == 'r')
        {
            DrawRect (b,c,d,e);
        }
        if (a == 'p')
        {
            print(tablica);
        }
        if (a == 'z')
        {
            zeruj(tablica);
        }
        if(a == 't')
        {
            trojkat(b,c,d);
        }
        if (a == 'x')
        {
            choinka(b,c,d);
        }
        if(a == 'm')
        {
            odwroc(tablica);
        }
        fgets(tab, 100, stdin);
        sscanf (tab, "%c %d %d %d %d", &a,&b,&c,&d, &e);
    }
    return 0;
}

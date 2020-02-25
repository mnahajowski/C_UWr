// Marcin Nahajowski

#include <stdio.h>
#include <stdbool.h>
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
    for (int x = 1; x < y0+r+1; x++)
    {
        for (int y = 0; y < x0+r+1; y++)
        {
            if (czy_w_kole(x, y0, y, x0, r))
            {
                printf("X");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
}
void DrawRect (int x0, int y0, int w, int h)
{
    y0++;
    for (int x = 1; x < y0 +h; x++)
    {
        for (int y = 0; y < x0+w; y++)
        {
            if (x >= y0 && y >=x0 && x <=y0+h && y <= x0 +w)
            {
                printf("X");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
}
int main()
{
    char tab[10];
    printf  ("Witamy w programie, ktory ma na celu narysowanie kola lub prostokata \nLitera c oznacza kolo, r - prostokat a q - konczy dzialanie programu \nNastepnie podane sa parametry dla konkretnej figury \nOto przykladowy kolo dla danych \t c 3 3 2 \n");
    DrawElip(3,3,2);
    fgets(tab, 100, stdin);
    int  b, c, d, e;
    char a;
    sscanf (tab, "%c %d %d %d %d", &a,&b,&c,&d, &e );
    while (a != 'q')
    {
        if(a == 'c')
        {
            DrawElip(b,c,d);
        }
        else if (a == 'r')
        {
            DrawRect (b,c,d,e);
        }
        fgets(tab, 10, stdin);
        sscanf (tab, "%c %d %d %d %d", &a,&b,&c,&d, &e);
    }
    return 0;
}

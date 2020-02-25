#include <stdio.h>
#include <stdlib.h>
void funkcja(int i, int j, int a, int b, int tab[a+1][b+1], int tab2[a+1][b+1])
{
    tab2[i][j] = 1;
    if(tab[i-1][j] == 1 && tab2[i-1][j] == 0)
        funkcja(i-1, j, a,b,tab, tab2);
    if(tab[i-1][j-1] == 1 && tab2[i-1][j-1] == 0)
        funkcja(i-1, j-1, a,b,tab, tab2);
    if(tab[i][j-1] == 1 && tab2[i][j-1] == 0)
        funkcja(i, j-1, a,b,tab, tab2);
    if(tab[i+1][j] == 1 && tab2[i+1][j] == 0)
        funkcja(i+1, j,a,b ,tab, tab2);
    if(tab[i+1][j+1] == 1 && tab2[i+1][j+1] == 0)
        funkcja(i+1, j+1,a,b ,tab, tab2);
    if(tab[i+1][j-1] == 1 && tab2[i+1][j-1] == 0)
        funkcja(i+1, j-1, a,b,tab, tab2);
    if(tab[i][j+1] == 1 && tab2[i][j+1] == 0)
        funkcja(i, j+1, a,b,tab, tab2);
    if(tab[i-1][j+1] == 1 && tab2[i-1][j+1] == 0)
        funkcja(i-1, j+1, a,b,tab, tab2);
}
int main ()
{
    char *wsk;
    wsk = (char*)malloc(80*sizeof(char));
    fgets(wsk, 80, stdin);
    int a;
    int b;
    scanf("%d %d", &a, &b);
    int tab[a+1][b+1];
    int tab2[a+1][b+1];
    for (int i = 0; i < b; i++)
    {
        for(int j = 0; j < a; j++)
        {
            scanf("%d", &tab[j][i]);
            tab2[j][i] = 0;
        }
    }
    int licznik = 0;
    for (int i = 0; i < b; i++)
    {
        for(int j = 0; j < a; j++)
        {
            if(tab[j][i] == 1 && tab2[j][i] == 0)
            {
                licznik++;
                funkcja(j,i,a,b,tab,tab2);
            }
            else
                tab2[j][i] = 1;
        }
    }
    printf("%d", licznik);
    return 0;
}

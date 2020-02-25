#include <stdio.h>
int tab_ojciec[101];
int tab_gleb[101];
void dodaj(int tab_ojciec[], int tab_gleb[], int a, int b)
{
    tab_ojciec[a] = b;
    tab_gleb[a] = tab_gleb[b] + 1;
}

void przenies(int tab_ojciec[], int tab_gleb[], int a, int b)
{
    tab_ojciec[a] = b;
    tab_gleb[a] = tab_gleb[b] + 1;
    for(int i = 1; i < 100; i++)
    {
        if(tab_ojciec[i] == a)
        {
            przenies(tab_ojciec, tab_gleb,i,a);
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    char c;
    int i = 0;
    while(i < n)
    {
        c = getchar();
        c = getchar();
        int a,b;
        scanf("%d %d", &a ,&b);
        if(c == 'd')
        {
            dodaj(tab_ojciec, tab_gleb,a,b);
        }
        else if(c == 'p')
        {
            przenies(tab_ojciec, tab_gleb,a,b);
        }
        i++;
    }
    printf("%d \n", tab_gleb[2]+1);
    return 0;
}

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAXIM 128

int tab[MAXIM];
int number_of_points;
int result;
typedef struct point
{

    bool if_sign;
    int o;
    struct point *left, *right;

} Point;

void text()
{   // wczytywanie znakow i wpisywanie ich kodow ascii do tablicy intowej
    int sign;
    while((sign = getchar()) != EOF)
    {
        tab[sign]++;
    }

}


void selection_sort()
{
    int value;
    for(int i = 0; i < MAXIM-1; i++)
    {
        value = tab[i];
        for(int j = i + 1; j < MAXIM; j++)
        {
            if(tab[i] > tab[j])
            {
                value = tab[i];
                tab[i] = tab[j];
                tab[j] = value;
            }
        }
    }
}

Point *w[MAXIM];        // wskaznik na pierwszy element tablicy struktur o rozmiarze MAXIM

void create_point()
{
    // mamy tu juz posorotwana tablice
    int i = 0;
    while(i < MAXIM && tab[i] == 0)
    {
        i++;
    }

    for(int j = 0; i < MAXIM; i++, j++)
    {
        w[j] = (Point *)malloc(sizeof(Point));
        w[j] -> if_sign = true;
        w[j] -> o = tab[i];
        w[j] -> left = NULL;
        w[j] -> right = NULL;
        number_of_points++;
    }
}

void swap_point(Point **x, Point **y)
{
    Point *z;
    z = *x;
    *x = *y;
    *y = z;
}

void move_point(int start)
{
    // wstawienie wierzcholka na wlasciwe miejsce w liscie(pod katem prawdopodobienstwia, postrtowania)
    while(start <= number_of_points-2 && ((w[start] -> o) > (w[start+1] -> o)))
    {
        swap_point(&w[start], &w[start+1]);
        start++;
    }

}

// tworzymy drzewo
void create_tree()
{
    //wez dwa wierzcholki o najmniejszym prawdopodbienstwie o polacz za pomoca nowego wierzcholka
    // nowy wierzcholek wstaw do listy(posortowanej oprocz tego wierzcholka0 na wlasciwe miejsce
    // powtarzaj dopoki nie zostanie jeden (ostatni) wierzcholek

    for(int i =1; i < number_of_points; i++)
    {
        Point *neww = (Point *)malloc(sizeof(Point));
        neww -> if_sign = false;
        neww -> o = ((w[i-1] -> o) + (w[i] -> o));
        neww -> left = w[i-1];
        neww -> right = w[i];

        w[i] = neww;
        move_point(i);
    }
}

void DFS(Point *act, int h)
{
    //przechodzimy po drzewie aby zliczyc wynik
    if(act -> if_sign == true)
        result += (act -> o)*h;
    if(act -> left != NULL)
        DFS(act -> left, h+1);
    if(act -> right != NULL)
        DFS(act -> right, h+1);
}

int main()
{
    text();
    selection_sort();
    create_point();
    create_tree();
    DFS(w[number_of_points-1],0);
    printf("%d \n", result);
    return 0;
}

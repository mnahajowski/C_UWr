#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct PtList {

    float x;
    float y;
    float z;
    char  nazwa[60];
    struct PtList *nastepny;
}PtList;

typedef struct List{

    PtList *start;
    PtList *end;
    int rozmiar;
}List;

bool czy_pusta(List *list, bool p)
{
    if(list->end == NULL && p)
        printf("Lista Pusta\n");
    return list -> end == NULL;
}


void wypisz_element(PtList *element)
{
    printf("%s = (%f, %f, %f)\n", element -> nazwa, element -> x, element -> y, element ->z);
}

void wypisz_pierwszy_ostatni(List *list)
{
    czy_pusta(list, true);
    wypisz_element(list -> start);
    wypisz_element(list -> end);
}

void dodaj_na_koniec(List *list, float x, float y, float z, char nazwa[])
{
    PtList * element = (PtList *)malloc(sizeof(PtList));
    list->rozmiar++;
    element->x = x;
    element->y = y;
    element->z = z;
    element->nastepny = NULL;
    int i = 0;

    while(nazwa[i] != '\n'){
        element -> nazwa[i] = nazwa[i];
        i++;
    }

    if(czy_pusta(list, false))
    {
        list -> start = element;
        list -> end = element;
        return;
    }
    list->end->nastepny = element;
    list -> end = element;
}

void wyswietl_liste(List *list)
{
    if(czy_pusta(list, true))
        return;
    PtList *element = list -> start;
    do{
        wypisz_element(element);
        element = element -> nastepny;
    }while(element != NULL);
}

int main()
{
    float x, y, z;
    char nazwa[60];
    List list; list.start = list.end = NULL; list.rozmiar = 0;
    while(scanf("%f %f %f", &x, &y, &z) == 3 && fgets(nazwa, 60, stdin) != NULL && strcmp(nazwa, "KONIEC") != 0){
        dodaj_na_koniec(&list, x, y, z, nazwa);
    }
    printf("ROZMIAR: %d\n", list.rozmiar);
    wypisz_pierwszy_ostatni(&list);
    char tekst[5];
    printf("Czy wypisac cala liste?\n");
    scanf("%s", tekst);
    if (strcmp(tekst, "TAK") == 0)
        wyswietl_liste(&list);

    return 0;
}

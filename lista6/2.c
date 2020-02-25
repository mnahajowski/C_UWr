// Marcin Nahajowski


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct samochod
{
    char producent[101];
    char model[101];
    int rok;
    int pojemnosc;
} Samochod;

int rok (const void * a, const void * b)        // sortowanie wed³ug roku
{
    Samochod* Samochod_a = (Samochod*) a;
    Samochod* Samochod_b = (Samochod*) b;
    if(((*Samochod_a).rok) <  (*Samochod_b).rok) return -1;
    else if((*Samochod_a).rok  ==  (*Samochod_b).rok) return 0;
    else return 1;
}

int wedlug_m (const void * a, const void * b)           // sortowanie wedlug modelu
{
    Samochod * Samochod_a = (Samochod*) a;
    Samochod* Samochod_b = (Samochod*) b;
    if(strcmp ((*Samochod_a).model, (*Samochod_b).model) > 0)
    {
        return 1;
    }
    else if(strcmp ((*Samochod_a).model, (*Samochod_b).model) == 0)
        return 0;
    else
        return -1;
}

int wedlug_p (const void * a, const void * b)       // sortowanie wedlug producenta
{
    Samochod * Samochod_a = (Samochod*) a;
    Samochod* Samochod_b = (Samochod*) b;
    if(strcmp ((*Samochod_a).producent, (*Samochod_b).producent) > 0)
    {
        return 1;
    }
    else if(strcmp ((*Samochod_a).producent, (*Samochod_b).producent) == 0)
        return 0;
    else
        return -1;
}

int main (int argc, char *argv[])
{
    Samochod tab[1000];
    if(argc > 2)
    {

        FILE *hPlik = fopen(argv[1],"r");
        int i = 0;
        while(fgets(tab[i].producent,101,hPlik) != NULL)        // wczytywanie elementow kolejnych struktur
        {
            fgets(tab[i].model, 101, hPlik);
            fscanf(hPlik, "%d ", &tab[i].rok);
            fscanf(hPlik, "%d ", &tab[i].pojemnosc);
            i++;
        }
        fclose(hPlik);

        char *znak = argv[2];
        if(*znak == 'r')
        {
                qsort(tab, i, sizeof(Samochod), rok);
        }

        else if(*znak == 'm')
        {
                qsort(tab, i, sizeof(Samochod), wedlug_m);
        }
        else if(*znak == 'p')
        {
            qsort(tab, i, sizeof(Samochod), wedlug_p);
        }

        for(int j = 0; j <i; j++)       // wypisywanie
        {
            printf ("%s", tab[j].producent);
            printf ("%s", tab[j].model);
            printf ("%d \n", tab[j].rok);
            printf ("%d \n", tab[j].pojemnosc);
        }
    }
    return 0;
}

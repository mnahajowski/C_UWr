#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int licznik=0;
int liczba__zmiennych = 0;
int wejscie_liczba=0;
int wyjscie_liczba=0;

bool zmienne[128], kry[26], kryt[128];

char wejscie_stos[10007];
char wyjscie[10007];

int waga_tab[128];
bool lacznosc_tab[128];

bool operator_spraw(char n)
{
    if((lacznosc_tab[(int)n] != 1 && waga_tab[(int)n] <= waga_tab[(int)wejscie_stos[wejscie_liczba-1]]) || (lacznosc_tab[(int)n] == 1 && waga_tab[(int)n] < waga_tab[(int)wejscie_stos[wejscie_liczba-1]]))
    {
        return 1;
    }

    return 0;
}

bool is_zmienne()
{
    bool wyniki[10007];
    int rozm = 0;
    for(int i = 0; i < wyjscie_liczba; i++)
    {
        if(isalpha(wyjscie[i]) || isdigit(wyjscie[i]))
        {
            if(isalpha(wyjscie[i]))
                wyniki[rozm++] = kryt[(int)wyjscie[i]];
            else
                wyniki[rozm++] = wyjscie[i] - '0';
        }
        else if(wyjscie[i] == '~')
        {
            wyniki[rozm-1] = !wyniki[rozm-1];
        }
        else if(wyjscie[i] == '&')
        {
            wyniki[rozm-2] = wyniki[rozm-2] && wyniki[rozm-1];
            rozm--;
        }
        else if(wyjscie[i] == '|')
        {
            wyniki[rozm-2] = wyniki[rozm-2] || wyniki[rozm-1];
            rozm--;
        }
        else if(wyjscie[i] == '>')
        {
            wyniki[rozm-2] = !wyniki[rozm-2] || wyniki[rozm-1];
            rozm--;
        } else
        {
            if((wyniki[rozm-2] && wyniki[rozm-1]) || (!wyniki[rozm-2] && !wyniki[rozm-1]))
            {
                wyniki[rozm-2] = 1;

            } else
            {
                wyniki[rozm-2] = 0;
            }
            rozm--;
        }
    }

    return wyniki[0];
}

void clear(void)
{
    licznik = 0;
    wejscie_liczba = 0;
    wyjscie_liczba = 0;
    liczba__zmiennych = 0;

    for(int i='a'; i <= 'z'; i++)
        zmienne[i] = 0;

}


int main()
{
    int n=0;

    char znak;
    scanf("%d ", &n);

    char zmienne_2[26];

    waga_tab['('] = -100;
    waga_tab['~'] = 5;
    waga_tab['&'] = 4;
    waga_tab['|'] = 3;
    waga_tab['>'] = 2;
    waga_tab['='] = 1;

    lacznosc_tab['>'] = 1;

    for(int i=0; i<n; i++)
    {
        znak = getchar();
        while(znak != ';')
        {
            if(isalpha(znak) || isdigit(znak))
            {

                wyjscie[wyjscie_liczba] = znak;
                wyjscie_liczba++;

                if(isalpha(znak) && !zmienne[(int)znak])
                {
                    zmienne_2[liczba__zmiennych++] = znak;
                }

                zmienne[(int)znak] = 1;

            } else if(znak=='(')
            {
                wejscie_stos[wejscie_liczba] = znak;
                wejscie_liczba++;


            } else if(znak==')')
            {
                while(wejscie_stos[wejscie_liczba-1] != '(')
                {
                    wyjscie[wyjscie_liczba] = wejscie_stos[wejscie_liczba-1];
                    wyjscie_liczba++;
                    wejscie_liczba--;
                }

                wejscie_liczba--;

            } else
            {
                if(wejscie_liczba > 0 && znak == '~' && wejscie_stos[wejscie_liczba-1] == '~')
                {
                    wejscie_liczba--;

                } else
                {
                    while(wejscie_liczba > 0 && operator_spraw(znak))
                    {
                        wyjscie[wyjscie_liczba] = wejscie_stos[wejscie_liczba - 1];
                        wyjscie_liczba++;
                        wejscie_liczba--;
                    }

                    wejscie_stos[wejscie_liczba] = znak;
                    wejscie_liczba++;
                }
            }
            znak = getchar();
        }

        while(wejscie_liczba >= 0)
        {
            wyjscie[wyjscie_liczba] = wejscie_stos[wejscie_liczba-1];
            wyjscie_liczba++;
            wejscie_liczba--;
        }

        for(int i = 0; i < (1 << liczba__zmiennych); i++)
        {
            for(int j = 0; j < liczba__zmiennych; j++)
            {
                if( (i & (1 << j) ) != 0)
                {
                    kryt[(int)zmienne_2[j]] = 1;
                } else
                {
                    kryt[(int)zmienne_2[j]] = 0;
                }
            }
            if(is_zmienne())
                licznik++;
        }

        printf("%d\n", licznik);
        clear();
    }

    return 0;
}

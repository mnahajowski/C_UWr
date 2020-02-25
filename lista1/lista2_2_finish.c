// Marcin Nahajowski

#include <stdio.h>
int main ()
{
    int ilosc_5 = 0, ilosc_2 = 0;
    int n , m;
    int czesc_calk = 0, liczba_przed_okresem = 0, liczba_w_okresie = 0;
    scanf ("%d", &n);
    scanf ("%d", &m);
    if (m == 0)
    {
        printf ("Bledne dane"); // sprawdzenie danyych
        return 0;
    }
    int test = 0;
    if(n < 0)
    {
        n= n * (-1);
        test++;
    }
    if (m < 0)
    {
        m = m * (-1);       // sprawdzenie znaku
        test++;
    }
    if (n%m == 0)
    {
        int x = n/m;
        printf("%d", x);
        return 0;
    }
    if (n > m)
    {
        czesc_calk = n/m;       // wydzielenie czêsci calkowitej
        n = n - czesc_calk * m;
    }
    int n2 = n, m2 = m;
    if (n%m == 0)
    {
        int x = n/m;
        printf("%d", x);
        return 0;
    }
//    printf ("%d \n", m);
 //   printf ("%d \n", n);
    while (n2 != m2)
    {
        if (n2 > m2)
        {
            n2 = n2 - m2;           // wyznaczenie NWD(m,n)
        }
        else
        {
            m2 = m2 - n2;
        }
    }
 //   printf ("%d \n", m2);
 //   printf ("%d \n", n2);
    n = n / n2;
    m = m / m2;
    int m4 = m;
    if (m == 2 && n ==1)
    {
        printf ("%d", czesc_calk);
        printf (",");
        printf ("5");
        return 0;
    }
    if (m == 5 && n ==1)
    {
        printf ("%d", czesc_calk);
        printf (",");
        printf ("2");
        return 0;
    }if (m == 5 && n ==2)
    {
        printf ("%d", czesc_calk);
        printf (",");
        printf ("4");
        return 0;
    }if (m == 5 && n ==3)
    {
        printf ("%d", czesc_calk);
        printf (",");
        printf ("6");
        return 0;
    }if (m == 5 && n ==4)
    {
        printf ("%d", czesc_calk);
        printf (",");
        printf ("8");
        return 0;
    }
 //   printf ("%d \n", m);
 //   printf ("%d \n", n);
    for (int i = 2; i <= m4/2; i++)
    {
        while( m4%i == 0 && i ==2)  // rozklad na 2 i 5
        {
            ilosc_2++;
            m4 = m4/2;
        }
        while(m4%i == 0 && i == 5)
        {
            ilosc_5++;
            m4 = m4 / 5;
        }
        if(i > 5)
        {
            i = m4;
        }
    }
//    printf ("%d \n", ilosc_2);
  //  printf ("%d \n", ilosc_5);
    int ilosc_przed_okresem;
    if(ilosc_2 >= ilosc_5)
    {
        ilosc_przed_okresem = ilosc_2;      //zliczenie liczby cyfr przed okresem
    }
    else
    {
        ilosc_przed_okresem = ilosc_5;
    }
    printf ("%d \n", ilosc_przed_okresem);
 //   printf ("%d \n", m);
 //   printf ("%d \n", n);
 int liczba_zer = 0;
    for (int i = 0; i < ilosc_przed_okresem; i++)
    {
        liczba_przed_okresem = liczba_przed_okresem * 10;       // okreslenie liczby przed okresem
        n= n *10;
        if (liczba_przed_okresem == 0 && n/m == 0)
        {
            liczba_zer++;
        }

        liczba_przed_okresem += n/m;
        n = n - (n/m * m);
    }
    printf ("%d \n", liczba_zer);
    printf ("%d \n", ilosc_przed_okresem);
    printf ("%d \n", liczba_przed_okresem);
    int zmienna = 9;
    int ilosc_cyfr_w_okresie = 1;
    int liczba_zer_w_okresie = 0;
    int m3 = m;
    while (m3 %2 == 0)
    {
        m3 = m3/2;
    }
    while (m3 % 5 == 0)     // zmiana mianownika
    {
        m3 = m3 / 5;
    }



    while (zmienna % m3 != 0)
    {
        zmienna = (zmienna + 1) * 10 - 1;
        ilosc_cyfr_w_okresie++;
    }
  //  printf ("%d \n", ilosc_cyfr_w_okresie);
 //   printf ("%d \n", liczba_w_okresie);
 //   printf ("%d \n", m);
 //   printf ("%d \n", n);
    for (int  i = 0; i < ilosc_cyfr_w_okresie; i++)
    {
        liczba_w_okresie = liczba_w_okresie * 10;
        n = n* 10;
        if (liczba_w_okresie == 0 && n/m == 0)      // okreslenie liczby w okresie
        {
            liczba_zer_w_okresie++;
        }
        liczba_w_okresie += n/m;

        n = n - (n/m * m);
    }
    printf ("%d \n", liczba_zer_w_okresie);
//    printf ("%d \n", liczba_w_okresie);

    if (test %2 ==1)
    {
        printf("-");
    }
    if (liczba_w_okresie !=0 && ilosc_przed_okresem !=0 && liczba_przed_okresem == 0 && liczba_zer > 0)
    {
        printf("%d", czesc_calk);
        printf (",");
        for (int i = 0; i < liczba_zer; i++)        // wypisywanie, przypadki
        {
            printf("0");
        }
        printf ("(");
        for (int i = 0; i < liczba_zer_w_okresie; i++)
        {
            printf("0");
        }
        printf ("%d", liczba_w_okresie);
        printf (")");
        return 0;
    }
    if (liczba_w_okresie ==0 && ilosc_przed_okresem !=0 && liczba_przed_okresem == 0 && liczba_zer > 0)
    {
        printf("%d", czesc_calk);
        printf (",");
        for (int i = 0; i < liczba_zer; i++)
        {
            printf("0");
        }
        return 0;
    }

    if (liczba_w_okresie !=0 && ilosc_przed_okresem !=0)
    {
        printf("%d", czesc_calk);
        printf (",");
        for (int i = 0; i < liczba_zer; i++)
        {
            printf("0");
        }
        printf ("%d", liczba_przed_okresem);
        printf ("(");
        for (int i = 0; i < liczba_zer_w_okresie; i++)
        {
            printf("0");
        }
        printf ("%d", liczba_w_okresie);
        printf (")");
        return 0;
    }
    if (ilosc_cyfr_w_okresie == 0 || liczba_w_okresie == 0)
    {
        printf("%d", czesc_calk);
        printf (",");
        for (int i = 0; i < liczba_zer; i++)
        {
            printf("0");
        }
        printf ("%d", liczba_przed_okresem);
        return 0;
    }
    if (liczba_w_okresie !=0 && ilosc_przed_okresem ==0)
    {
        printf("%d", czesc_calk);
        printf (",");
        for (int i = 0; i < liczba_zer; i++)
        {
            printf("0");
        }
        printf ("(");
        for (int i = 0; i < liczba_zer_w_okresie; i++)
        {
            printf("0");
        }
        printf ("%d", liczba_w_okresie);
        printf (")");
        return 0;
    }


    return 0;
}

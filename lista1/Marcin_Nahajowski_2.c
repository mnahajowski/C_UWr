// Marcin Nahajowski

#include <math.h>
#include <stdio.h>
#define PI 3.141592653589793238462
int main()
{
       double suma = 0;
       for (double i = 0; i < 16; i++)
       {
       double x = ((4.0 / (8.0 * i + 1.0)) - 2.0 / (8.0  * i +4) - 1.0/(8.0  * i + 5.0) - 1.0/(8.0  * i + 6.0))/(pow(16.0 , i));
       suma += x;
       }

       double arc=acos(-1);
       double roznica = suma - arc;
       printf ("%g \n", roznica);
       printf("%.16f \n", suma);


    long double suma2 = 0;
    for (long double i = 0; i < 20; i++)
    {
        long double y = ((4.0 / (8.0 * i + 1.0)) - 2.0 / (8.0  * i +4) - 1.0/(8.0  * i + 5.0) - 1.0/(8.0  * i + 6.0))/(pow(16.0, i));
        suma2 += y;
    }
    long double arc2 = acosl(-1);
    long double roznica2 = suma2 - arc2;
    printf ("%g \n", (double)roznica2);
    printf ("%.20f", (double)suma2);




    return 0;
}

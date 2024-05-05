#include <stdio.h>

#define EPSILON 0.0001

int main()
{
    float i;
    float orta_nokta_x, orta_nokta_y;
    float egim;
    float ayiran_dogrunun_egimi;
    float test_point_x, test_point_y;
    float x0, a0;
    float y0, b0;

    // verilerin tanımlanması

    printf("Please enter the cordinates for first class :\n");

    for (i = 0; i < 10; i++)
    {
        scanf("%f%f", &x0, &y0);
        x0 += x0;
        y0 += y0;
    }

    // ilk class için kullanıcıdan veri alma

    printf("Please enter the cordinates for second class :\n");

    for (i = 0; i < 10; i++)
    {
        scanf("%f%f", &a0, &b0);
        a0 += a0;
        b0 += b0;
    }

    // ikinci class için kullanıcıdan veri alma

    x0 = x0 / 10;
    y0 = y0 / 10;
    a0 = a0 / 10;
    b0 = b0 / 10;

    // average kordinatları bulma

    orta_nokta_x = (x0 + a0) / 2;
    orta_nokta_y = (y0 + b0) / 2;

    // orta noktanın bulunması

    if ((y0 - b0) == 0.0)
        egim == (x0 - a0) / EPSILON;
    else
        egim = (x0 - a0) / (y0 - b0);
    ayiran_dogrunun_egimi = -1 / egim;

    // eğim için bölen kısmının 0 çıkıp çıkmamasına göre eğimi bulma

    while (1) // döngünün devam etmesi için
    {

        printf("Please enter the test points\n");
        if (scanf("%f%f", &test_point_x, &test_point_y) != 2)
            return 0; // sayı harici karakter girilirse işlemim bitirilmesi

        if (test_point_y > ayiran_dogrunun_egimi * (test_point_x - orta_nokta_x) + orta_nokta_y)
            printf("Class1\n");
        else
            printf("Class2\n");

        // classın bulunması
    }

    return 1;
}

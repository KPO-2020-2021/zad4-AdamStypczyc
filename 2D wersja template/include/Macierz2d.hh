#ifndef MACIERZ2D_HH
#define MACIERZ2D_HH

#include "macierz.hh"
typedef Macierz<double, 2> Macierz2D;
double StopienNaRadian(double kat)
{
    double radian;
    radian = kat * M_PI / 180;
    return radian;
}

void Oblicz_Macierz_Obrotu(double kat_radian, Macierz2D &Mac)
{
    Mac(0, 0) = cos(kat_radian);
    Mac(0, 1) = -sin(kat_radian);
    Mac(1, 0) = sin(kat_radian);
    Mac(1, 1) = cos(kat_radian);
}

#endif
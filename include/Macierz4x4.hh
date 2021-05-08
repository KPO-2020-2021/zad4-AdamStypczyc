#pragma once

#include "macierz.hh"
#include "size.hh"
#include "Wektor3D.hh"
/*!
 * \brief Deklaracja Macierzy4x4
 * Deklaracja macierzy z modyfikacji.
 */
typedef Macierz<double, 4> Macierz4x4;

void Oblicz_Macierz4x4(double katX, double katY, double katZ, Wektor3D V, Macierz4x4 &Mac)
{
    double radianX, radianY, radianZ;
    radianX = katX * M_PI / 180;
    radianY = katY * M_PI / 180;
    radianZ = katZ * M_PI / 180;
    Mac(0,0) = cos(radianX) * cos(radianY);
    Mac(0,1) = cos(radianX) * sin(radianY) * sin(radianZ) - sin(radianX) * cos(radianZ);
    Mac(0,2) = cos(radianX) * sin(radianY) * cos(radianZ) + sin(radianX) * sin(radianZ);
    Mac(0,3) = V[0];
    Mac(1,0) = sin(radianX) * cos(radianY);
    Mac(1,1) = sin(radianX) * sin(radianY) * sin(radianZ) + cos(radianX) * cos(radianZ);
    Mac(1,2) = sin(radianX) * sin(radianY) * cos(radianZ) - cos(radianX) * sin(radianZ);
    Mac(1,3) = V[1];
    Mac(2,0) = -sin(radianY);
    Mac(2,1) = cos(radianY) * sin(radianZ);
    Mac(2,2) = cos(radianY) * cos(radianZ);
    Mac(2,3) = V[2];
    Mac(3,0) = 0;
    Mac(3,1) = 0;
    Mac(3,2) = 0;
    Mac(3,3) = 1;
}
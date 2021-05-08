#pragma once

#include "Macierz.hh"
#include "Prostopadloscian.hh"

/*!
 * \brief Struktura Sceny przechowująca oryginaly prostopadłościan oraz macierze obrotu wokół osi.
 * \param pomocnicza_mac_X Macierz przechowująca macierz obrotu wokół osi OX.
 * \param pomocnicza_mac_Y Macierz przechowująca macierz obrotu wokół osi OY.
 * \param pomocnicza_mac_Z Macierz przechowująca macierz obrotu wokół osi OZ.
 * \param Pomocniczy_Pr Prostopadłościan przechowujący oryginalny prostopadłościan.
 */
struct Scena
{
    Macierz3x3 pomocnicza_mac_X, pomocnicza_mac_Y, pomocnicza_mac_Z; 
    Prostopadloscian Pomocniczy_Pr;
};

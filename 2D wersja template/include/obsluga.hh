#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "exampleConfig.h"
#include "example.h"
#include "Wektor2d.hh"
#include "Macierz2d.hh"
#include "Prostokat2.hh"
#include "../include/lacze_do_gnuplota.hh"
/*!
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 * 
 * EDIT: dodane kreowanie wektorow i macierzy plus obsluga lacza do gnuplota
 */
/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola 
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool ZapisWspolrzednychDoPliku(const char *sNazwaPliku, Prostokat Pr)
{
    std::ofstream StrmPlikowy;

    StrmPlikowy.open(sNazwaPliku);
    if (!StrmPlikowy.is_open())
    {
        std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
                  << ":(  nie powiodla sie." << std::endl;
        return false;
    }

    StrmPlikowy << Pr;
    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}
void pokaz_menu(char &wybor)
{
    std::cout << "Opcje: " << std::endl;
    std::cout << "o - obrot prostokata o zadany kat" << std::endl;
    std::cout << "p - przesuniecie prostokata o zadany wektor" << std::endl;
    std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
    std::cout << "m - wyswietl menu" << std::endl;
    std::cout << "k - koniec dzialania programu" << std::endl;
    std::cout << "Twoj wybor? (m - menu) > ";
    std::cin >> wybor;
    std::cout << "------------------------------------" << std::endl;
}
int menu()
{
    long int n;                 //ilość obrotów
    char wybor;                 //wybór użytkownika
    Prostokat Pr;               //prostokat
    Wektor2D translacja;        //wektor przesunięcia
    Wektor2D poczatek;          //Wektor2D odpowiedzialny za początkowy punkt prostokata
    Macierz2D obrot;            //macierz obrotu
    double tab1[2];             //tu wpisujemy współrzędne wektora początkowego
    double tab2[2];             //tu wpisujemy współrzędne wektora przesunięcia
    double w, h;                //w-szerokość prostokąta, h-wysokość
    PzG::LaczeDoGNUPlota Lacze; //łącze do gnuplota
    double kat, radian;         //kąt
    /*!
     * Linie 96 - 103 i 118
     * tworzenie prostokąta
     */
    std::cout << "Od jakiego punktu mają wychodzić pozostałe punkty?\nPodaj współrzędne x,y " << std::endl;
    while (1)
    {
        std::cin >> tab1[0];
        if (std::cin.good())
        {
            break;
        }
        else
        {
            std::cout << "Podana liczba nie była liczbą :0\nPodaj wartość jeszcze raz" << std::endl;
            std::cin.clear();
            std::cin.ignore(1024, '\n');
        }
    }
    while (1)
    {
        std::cin >> tab1[1];
        if (std::cin.good())
        {
            break;
        }
        else
        {
            std::cout << "Podana liczba nie była liczbą :0\nPodaj wartość jeszcze raz" << std::endl;
            std::cin.clear();
            std::cin.ignore(1024, '\n');
        }
    }
    poczatek = Wektor2D({tab1[0], tab1[1]});
    std::cout << "Podaj szerokość prostokata" << std::endl;
    while (1)
    {
        std::cin >> w;
        if (std::cin.good())
        {
            if (w == 0)
            {
                std::cerr << "Błąd!!! Szerokość nie może być równa 0.\nPodaj wartość jeszcze raz." << std::endl;
            }
            else
            {
                break;
            }
        }
        else
        {
            std::cout << "Podana liczba nie była liczbą :0\nPodaj wartość jeszcze raz" << std::endl;
            std::cin.clear();
            std::cin.ignore(1024, '\n');
        }
    }
    std::cout << "Podaj wysokość prostokata" << std::endl;
    while (1)
    {
        std::cin >> h;
        if (std::cin.good())
        {
            if (h == 0)
            {
                std::cerr << "Błąd!!! Wysokość nie może być równa 0.\nPodaj wartość jeszcze raz." << std::endl;
            }
            else
            {
                break;
            }
        }
        else
        {
            std::cout << "Podana liczba nie była liczbą :0\nPodaj wartość jeszcze raz" << std::endl;
            std::cin.clear();
            std::cin.ignore(1024, '\n');
        }
    }
    std::cout << "------------------------------------" << std::endl;
    //   1. Rysowane jako linia ciagl o grubosci 2 piksele
    //
    Lacze.DodajNazwePliku("../datasets/prostokat.dat", PzG::RR_Ciagly, 2);
    //
    //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
    //      których połowa długości boku wynosi 2.
    //
    Lacze.DodajNazwePliku("../datasets/prostokat.dat", PzG::RR_Punktowy, 2);
    //
    //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
    //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
    //  jako wspolrzedne punktow podajemy tylko x,y.
    //
    Lacze.ZmienTrybRys(PzG::TR_2D);
    Pr = Prostokat(poczatek, h, w);
    if (!ZapisWspolrzednychDoPliku("../datasets/prostokat.dat", Pr))
        return 1;
    Lacze.Rysuj();
    //rysowanie początkowego prostokąta
    while (1)
    {
        //wyświetlanie menu
        pokaz_menu(wybor);
        switch (wybor)
        {
        case 'o':
            /*!
             * tworzenie macierzy obrotu
             * i obrót
             */
            std::cout << "O jaki kąt ma się obrócić?" << std::endl;
            while (1)
            {
                std::cin >> kat;
                if (std::cin.good())
                {
                    break;
                }
                else
                {
                    std::cout << "Podana liczba nie była liczbą :0\nPodaj wartość jeszcze raz" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1024, '\n');
                }
            }
            std::cout << "Ile razy ma się obrócić? " << std::endl;
            while (1)
            {
                std::cin >> n;
                if (std::cin.good())
                {
                    break;
                }
                else
                {
                    std::cout << "Podana liczba nie była liczbą :0\nPodaj wartość jeszcze raz" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1024, '\n');
                }
            }
            kat = kat * n;
            while (kat < 0)
            {
                kat = kat + 360;
            }
            while (kat > 0)
            {
                kat = kat - 360;
            }
            obrot = Macierz2D();
            radian = StopienNaRadian(kat);
            Oblicz_Macierz_Obrotu(radian, obrot);
            if (!ZapisWspolrzednychDoPliku("../datasets/prostokat.dat", Pr * obrot))
                return 1;
            Lacze.Rysuj();
            //wyświetlenie długości boków prostokąta Pr
            Pr.dlugosc();
            std::cout << "------------------------------------" << std::endl;
            break;
        case 'p':
            /*!
             * tworzenie wktora przesunięcia
             * i przesunięcie
             */
            translacja = Wektor2D();
            std::cout << "O jaki wektor [x,y] ma być przesunięty prostokat? \nPodaj dwie liczby, 1. to x, a 2. to y" << std::endl;
            while (1)
            {
                std::cin >> tab2[0];
                if (std::cin.good())
                {
                    break;
                }
                else
                {
                    std::cout << "Podana liczba nie była liczbą :0\nPodaj wartość jeszcze raz" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1024, '\n');
                }
            }
            while (1)
            {
                std::cin >> tab2[1];
                if (std::cin.good())
                {
                    break;
                }
                else
                {
                    std::cout << "Podana liczba nie była liczbą :0\nPodaj wartość jeszcze raz" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1024, '\n');
                }
            }
            translacja = Wektor2D({tab2[0], tab2[1]});
            Pr = Pr + translacja;
            if (!ZapisWspolrzednychDoPliku("../datasets/prostokat.dat", Pr))
                return 1;
            Lacze.Rysuj();
            Pr.dlugosc();
            std::cout << "------------------------------------" << std::endl;
            break;
        case 'w':
            //wyświetlanie wsþółrzędnych prostokąta
            std::cout << Pr;
            std::cout << "------------------------------------" << std::endl;
            break;
        case 'm':
            //menu
            pokaz_menu(wybor);
            break;
        case 'k':
            std::cout << "Do zobaczenia!!!" << std::endl;
            return 0;
            break;
        }
    }
    return 1;
}

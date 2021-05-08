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
#include "Wektor3D.hh"
#include "Macierz.hh"
#include "Prostopadloscian.hh"
#include "Scena.hh"
#include "../include/lacze_do_gnuplota.hh"
/*!
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 * 
 * EDIT: dodane kreowanie wektorow i Macierz3x3y plus obsluga lacza do gnuplota
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
bool ZapisWspolrzednychDoPliku(const char *sNazwaPliku, Prostopadloscian Pr)
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
    std::cout << "o - obrot prostopadloscianu o zadaną sekwencję ruchów" << std::endl;
    std::cout << "p - przesuniecie prostopadloscianu o zadany wektor" << std::endl;
    std::cout << "r - wyświetlenie macierzy rotacji" << std::endl;
    std::cout << "l - wyświetlenie oryginalnego prostopadloscianu" << std::endl;
    std::cout << "s - skalowanie prostopadloscianu o zadany wektor" << std::endl;
    std::cout << "t - powtorzenie poprzedniego obrotu" << std::endl;
    std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
    std::cout << "m - wyswietl menu" << std::endl;
    std::cout << "d - sprawdź długość boków" << std::endl;
    std::cout << "k - koniec dzialania programu" << std::endl;
    std::cout << "Twoj wybor? (m - menu) > ";
    std::cin >> wybor;
    std::cout << "------------------------------------" << std::endl;
}
int menu()
{
    long int n;                        //ilość obrotów
    char wybor;                        //wybór użytkownika
    Prostopadloscian Pr;               //prostokat
    Wektor3D translacja;               //wektor przesunięcia
    Wektor3D poczatek;                 //vector odpowiedzialny za początkowy punkt prostokata
    Macierz3x3 obrotX, obrotY, obrotZ; //Macierz3x3 obrotu
    double tab1[3];                    //tu wpisujemy współrzędne wektora początkowego
    double tab2[3];                    //tu wpisujemy współrzędne wektora przesunięcia
    double w, h, d;                    //w-szerokość prostokąta, h-wysokość
    PzG::LaczeDoGNUPlota Lacze;        //łącze do gnuplota
    Scena Pomoc;
    double skala;
    char znak;
    double kat = 0, katX = 0, katY = 0, katZ = 0;
    double radianX = 0, radianY = 0, radianZ = 0;
    double tab_pomocnicza[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    Pomoc.pomocnicza_mac_X = Macierz3x3(tab_pomocnicza);
    Pomoc.pomocnicza_mac_Y = Macierz3x3(tab_pomocnicza);
    Pomoc.pomocnicza_mac_Z = Macierz3x3(tab_pomocnicza);
    /*!
     * Linie 96 - 103 i 118
     * tworzenie prostokąta
     */
    std::cout << "Od jakiego punktu mają wychodzić pozostałe punkty?\nPodaj współrzędne x,y,z " << std::endl;
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
    while (1)
    {
        std::cin >> tab1[2];
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
    poczatek = Wektor3D({tab1[0], tab1[1], tab1[2]});
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
    std::cout << "Podaj głębokość prostokata" << std::endl;
    while (1)
    {
        std::cin >> d;
        if (std::cin.good())
        {
            if (w == 0)
            {
                std::cerr << "Błąd!!! Głębokość nie może być równa 0.\nPodaj wartość jeszcze raz." << std::endl;
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
    Lacze.ZmienTrybRys(PzG::TR_3D);
    Pr = Prostopadloscian(poczatek, h, w, d);
    Pomoc.Pomocniczy_Pr = Prostopadloscian(poczatek, h, w, d);
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
             * tworzenie Macierz3x3y obrotu
             * i obrót
             */
            std::cout << "Podaj sekwencję obrotów:\nZnak . kończy wczytywanie obrotów. " << std::endl;
            //while (znak != '.')
            while (1)
            {
                while (1)
                {
                    std::cin >> znak;
                    if (std::cin.good())
                    {
                        if (znak == 'x' || znak == 'y' || znak == 'z' || znak == '.')
                        {
                            break;
                        }
                        else
                        {
                            std::cout << "Podany znak to nie odpowiedni znak znak :0\nPodaj znak odpowiedzialny za oś lub kończący sekwencję jeszcze raz jeszcze raz" << std::endl;
                            std::cin.clear();
                            std::cin.ignore(1024, '\n');
                        }
                    }
                    else
                    {
                        std::cout << "Podany znak to nie znak :0\nPodaj znak odpowiedzialny za oś jeszcze raz" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(1024, '\n');
                    }
                }
                if (znak != '.')
                {
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
                    switch (znak)
                    {
                    case 'x':
                        katX = katX + kat;
                        break;

                    case 'y':
                        katY = katY + kat;
                        break;

                    case 'z':
                        katZ = katZ + kat;
                        break;

                    default:
                        std::cout << "Złe oznaczenie osi :0\nPodaj oś jeszcze raz poprzez literę x, y lub z" << std::endl;
                        break;
                    }
                }
                else
                {
                    std::cin.ignore(1024, '\n');
                    break;
                }
            }

            std::cout << "Ile razy sekwencja ma się wykonać? " << std::endl;
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
            katX = katX * n;
            katY = katY * n;
            katZ = katZ * n;
            obrotX = Macierz3x3();
            radianX = StopienNaRadianX(katX);
            Oblicz_Macierz_ObrotuX(radianX, obrotX);

            obrotY = Macierz3x3();
            radianY = StopienNaRadianY(katY);
            Oblicz_Macierz_ObrotuY(radianY, obrotY);

            obrotZ = Macierz3x3();
            radianZ = StopienNaRadianZ(katZ);
            Oblicz_Macierz_ObrotuZ(radianZ, obrotZ);
            Pomoc.pomocnicza_mac_X = obrotX * Pomoc.pomocnicza_mac_X;
            Pomoc.pomocnicza_mac_Y = obrotY * Pomoc.pomocnicza_mac_Y;
            Pomoc.pomocnicza_mac_Z = obrotZ * Pomoc.pomocnicza_mac_Z;
            Pr = Pr * obrotX;
            Pr = Pr * obrotY;
            Pr = Pr * obrotZ;
            if (!ZapisWspolrzednychDoPliku("../datasets/prostokat.dat", Pr))
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
            translacja = Wektor3D();
            std::cout << "O jaki wektor [x,y,z] ma być przesunięty prostokat? \nPodaj trzy liczby, 1. to x, 2. to y, a 3. to z" << std::endl;
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
            while (1)
            {
                std::cin >> tab2[2];
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
            translacja = Wektor3D({tab2[0], tab2[1], tab2[2]});
            Pr = Pr + translacja;
            if (!ZapisWspolrzednychDoPliku("../datasets/prostokat.dat", Pr))
                return 1;
            Lacze.Rysuj();
            Pr.dlugosc();
            std::cout << "------------------------------------" << std::endl;
            break;
        case 's':
            std::cout << "O jaką wartość ma być przeskalowany prostopadłościan?" << std::endl;
            while (1)
            {
                std::cin >> skala;
                if (std::cin.good())
                {
                    break;
                }
                else
                {
                    std::cout << "Podana skala nie była liczbą :0\nPodaj wartość jeszcze raz" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1024, '\n');
                }
            }
            Pr = Pr * skala;
            if (!ZapisWspolrzednychDoPliku("../datasets/prostokat.dat", Pr))
                return 1;
            Lacze.Rysuj();
            Pr.dlugosc();
            std::cout << "------------------------------------" << std::endl;
            break;
        case 'w':
            //wyświetlanie wsþółrzędnych prostokąta
            /****************************
             * 
             * Zrpbić osobne przeciążenie
             * 
             * *************************/
            Pr.wyswietl_wspolrzedne();
            std::cout << "------------------------------------" << std::endl;
            break;
        case 'm':
            //menu
            pokaz_menu(wybor);
            break;
        case 'd':
            Pr.dlugosc();
            std::cout << "------------------------------------" << std::endl;
            break;
        case 'l':
            Lacze.DodajNazwePliku("../datasets/prosto_POMOC.dat", PzG::RR_Ciagly, 2);
            Lacze.DodajNazwePliku("../datasets/prosto_POMOC.dat", PzG::RR_Punktowy, 2);

            if (!ZapisWspolrzednychDoPliku("../datasets/prosto_POMOC.dat", Pomoc.Pomocniczy_Pr))
                return 1;
            Lacze.Rysuj();
            std::cout << "------------------------------------" << std::endl;
            std::cout << "Oryginlany prostopadłościan zniknie wraz z zakończeniem działania programu" << std::endl;
            std::cout << "------------------------------------" << std::endl;
            break;
        case 't':
            //wykonanie poprzedniego obrotu
            Pr = Pr * Pomoc.pomocnicza_mac_X;
            Pr = Pr * Pomoc.pomocnicza_mac_Y;
            Pr = Pr * Pomoc.pomocnicza_mac_Z;
            if (!ZapisWspolrzednychDoPliku("../datasets/prostokat.dat", Pr))
                return 1;
            Lacze.Rysuj();
            //wyświetlenie długości boków prostokąta Pr
            Pr.dlugosc();
            std::cout << "------------------------------------" << std::endl;
            break;
        case 'r':
            //wyświetlanie macierzy obrotu
            std::cout << "Macierz rotacji wokół osi OX: " << std::endl;
            std::cout << Pomoc.pomocnicza_mac_X;
            std::cout << "Macierz rotacji wokół osi OY: " << std::endl;
            std::cout << Pomoc.pomocnicza_mac_Y;
            std::cout << "Macierz rotacji wokół osi OZ: " << std::endl;
            std::cout << Pomoc.pomocnicza_mac_Z;

            std::cout << "------------------------------------" << std::endl;
            break;
        case 'k':
            std::cout << "Do zobaczenia!!!" << std::endl;
            return 0;
            break;
        }
    }
    return 1;
}

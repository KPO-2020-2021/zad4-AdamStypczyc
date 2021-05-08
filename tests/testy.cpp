#include "../tests/doctest/doctest.h"
#include "Prostopadloscian.hh"
#include "Macierz4x4.hh"
TEST_CASE("test Wektor3D konstruktor 1")
{
    Wektor3D x;
    x = Wektor3D();

    CHECK(x[0] == 0);
    CHECK(x[1] == 0);
    CHECK(x[2] == 0);
}
TEST_CASE("test Wektor3D konstrunktor 2")
{
    Wektor3D x;
    x = Wektor3D({1, 2, 3});

    CHECK(x[0] == 1);
    CHECK(x[1] == 2);
    CHECK(x[2] == 3);
}
TEST_CASE("test Wektor3D Suma 1")
{
    Wektor3D x, y, z;
    x = Wektor3D({1.0, 2.0, 3.0});
    y = Wektor3D({3.0, 4.0, 5.0});
    z = Wektor3D({4.0, 6.0, 8.0});

    CHECK(x + y == z);
}

TEST_CASE("test Wektor3D Suma 2")
{
    Wektor3D x, y, z;
    x = Wektor3D({6, 6, 6});
    y = Wektor3D({2, -3, -6});
    z = Wektor3D({8, 3, 0});
    CHECK(x + y == z);
}
TEST_CASE("test Wektor3D Suma 3")
{
    Wektor3D x, y, z;
    x = Wektor3D({6, 6});
    y = Wektor3D({0, 0});
    z = Wektor3D({6, 6});
    CHECK(x + y == z);
}
TEST_CASE("test Wektor3D Suma 4")
{
    Wektor3D x, y, z;
    x = Wektor3D({6, 6, 6});
    y = Wektor3D({0.0, 0.0});
    z = Wektor3D({6, 6, 6});
    CHECK(x + y == z);
}
TEST_CASE("test Wektor3D Suma 5")
{
    Wektor3D x, y, z;
    x = Wektor3D({6, 6, 6});
    y = Wektor3D({0.00000000001, 0.00000000001, 0.00000000001});
    z = Wektor3D({6, 6, 6});
    CHECK(x + y == z);
}
TEST_CASE("test Wektor3D Suma 6")
{
    Wektor3D x, y, z;
    x = Wektor3D({6, 6, 6});
    y = Wektor3D({0.00000000009, 0.00000000009, 0.00000000009});
    z = Wektor3D({6, 6, 6});
    CHECK(x + y == z);
}
TEST_CASE("test Wektor3D Różnica 1")
{
    Wektor3D x, y, z;
    x = Wektor3D({1, 1, 1});
    y = Wektor3D({1, -3, 1});
    z = Wektor3D({0, 4, 0});
    CHECK(x - y == z);
}
TEST_CASE("test Wektor3D Różnica 2")
{
    Wektor3D x, y, z;
    x = Wektor3D({5, 6, 7});
    y = Wektor3D({2, 3, 4});
    z = Wektor3D({3, 3, 3});
    CHECK(x - y == z);
}
TEST_CASE("test Wektor3D Różnica 3")
{
    Wektor3D x, y, z;
    x = Wektor3D({2, 2, 2});
    y = Wektor3D({0, 0, 0});
    z = Wektor3D({2, 2, 2});
    CHECK(x - y == z);
}
TEST_CASE("test Wektor3D Różnica 4")
{
    Wektor3D x, y, z;
    x = Wektor3D({1, 1, 1});
    y = Wektor3D({0.0, 0.0, 0.0});
    z = Wektor3D({1, 1, 1});
    CHECK(x - y == z);
}

TEST_CASE("test Wektor3D Różnica 5")
{
    Wektor3D x, y, z;
    x = Wektor3D({6, 6, 6});
    y = Wektor3D({0.00000000001, 0.00000000001, 0.00000000001});
    z = Wektor3D({6, 6, 6});
    CHECK(x - y == z);
}
TEST_CASE("test Wektor3D Różnica 6")
{
    Wektor3D x, y, z;
    x = Wektor3D({6, 6, 6});
    y = Wektor3D({0.00000000009, 0.00000000009, 0.00000000009});
    z = Wektor3D({6, 6, 6});
    CHECK(x - y == z);
}
TEST_CASE("test operatora [] 1")
{
    Wektor3D x, y;
    x = Wektor3D({6, 7, 8});
    y = Wektor3D({8, 9, 10});
    double a, b, c, d, e, f;
    a = 6;
    b = 7;
    c = 8;
    d = 8;
    e = 9;
    f = 10;

    CHECK(a == x[0]);
    CHECK(b == x[1]);
    CHECK(c == x[2]);
    CHECK(d == y[0]);
    CHECK(e == y[1]);
    CHECK(f == y[2]);
}
TEST_CASE("test dzielenie Wektor3D 1")
{
    Wektor3D x, wynik;
    double dzielnik = 3;
    x = Wektor3D({6, 9, 12});
    wynik = x / dzielnik;
    CHECK(wynik[0] == 2);
    CHECK(wynik[1] == 3);
    CHECK(wynik[2] == 4);
}
TEST_CASE("test dzielenie Wektor3D 2")
{
    Wektor3D x, wynik;
    double dzielnik = 3;
    x = Wektor3D({2, 2, 2});
    wynik = x / dzielnik;
    CHECK(wynik[0] == 0.666666666666666667);
    CHECK(wynik[1] == 0.666666666666666667);
    CHECK(wynik[2] == 0.666666666666666667);
}
TEST_CASE("test dzielenie Wektor3D 3")
{
    Wektor3D x;
    double dzielnik = 0;
    x = Wektor3D({2, 2, 2});
    WARN_THROWS(x / dzielnik);
}
TEST_CASE("test mnozenie Wektor3D 1")
{
    Wektor3D x, wynik;
    double mnozenie = 3;
    x = Wektor3D({6, 9, 1});
    wynik = x * mnozenie;
    CHECK(wynik[0] == 18);
    CHECK(wynik[1] == 27);
    CHECK(wynik[2] == 3);
}
TEST_CASE("test mnozenie Wektor3D 2")
{
    Wektor3D x, wynik;
    double mnozenie = 0;
    x = Wektor3D({6, 9, 12});
    wynik = x * mnozenie;
    CHECK(wynik[0] == 0);
    CHECK(wynik[1] == 0);
    CHECK(wynik[2] == 0);
}
TEST_CASE("test wyświetlanie Wektor3D standard")
{
    Wektor3D x;
    x = Wektor3D({6, 7, 8});
    std::ostringstream out;
    out << x;
    std::cout << out.str();
    CHECK("6 7 8" == out.str());
}

TEST_CASE("test wczytywanie Wektor3D standard")
{
    Wektor3D x;

    std::istringstream in("21 37 0");
    in >> x;
    std::ostringstream out;
    out << x;
    std::cout << out.str() << std::endl;
    CHECK("21 37 0" == out.str());
}
/*!
 * 
 * Macierz
 */

TEST_CASE("Test Macierz3x3 konstruktor 1")
{
    Macierz3x3 x;
    x = Macierz3x3();
    CHECK(x(0, 0) == 0);
    CHECK(x(0, 1) == 0);
    CHECK(x(0, 2) == 0);
    CHECK(x(1, 0) == 0);
    CHECK(x(1, 1) == 0);
    CHECK(x(1, 2) == 0);
    CHECK(x(2, 0) == 0);
    CHECK(x(2, 1) == 0);
    CHECK(x(2, 2) == 0);
}
TEST_CASE("Test Macierz3x3 konstruktor 2")
{
    Macierz3x3 x;
    double tab[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    x = Macierz3x3(tab);
    CHECK(x(0, 0) == 1);
    CHECK(x(0, 1) == 2);
    CHECK(x(0, 2) == 3);
    CHECK(x(1, 0) == 4);
    CHECK(x(1, 1) == 5);
    CHECK(x(1, 2) == 6);
    CHECK(x(2, 0) == 7);
    CHECK(x(2, 1) == 8);
    CHECK(x(2, 2) == 9);
}

TEST_CASE("Test Macierz3x3 dodawanie 1")
{
    Macierz3x3 a, b, c, d, e, f;
    double tab0[SIZES][SIZES] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double tab1[SIZES][SIZES] = {{5, 6, 7}, {7, 8, 8}, {9, 10, 11}};
    double tab2[SIZES][SIZES] = {{6, 8, 10}, {11, 13, 14}, {16, 18, 20}};
    a = Macierz3x3(tab0);
    b = Macierz3x3(tab1);
    c = Macierz3x3(tab2);
    d = Macierz3x3();
    e = Macierz3x3();
    f = Macierz3x3();
    CHECK(a + b == c);
    CHECK(e + d == f);
}
TEST_CASE("Test Macierz3x3 dodawanie 2")
{
    Macierz3x3 a, b, c, d, e, f, g, h, i;
    double tab0[SIZES][SIZES] = {{1, 2}, {3, 4}};
    double tab1[SIZES][SIZES] = {{0.00000000001, 0.00000000001}, {0.00000000001, 0.00000000001}};
    double tab2[SIZES][SIZES] = {{9, 10}, {11, 12}};
    double tab3[SIZES][SIZES] = {{0.000000000001, 0.000000000001}, {0.000000000001, 0.000000000001}};
    double tab4[SIZES][SIZES] = {{5, 6}, {7, 8}};
    double tab5[SIZES][SIZES] = {{0.000000000009, 0.000000000009}, {0.000000000009, 0.000000000009}};
    double tab6[SIZES][SIZES] = {{1, 2}, {3, 4}};
    double tab7[SIZES][SIZES] = {{9, 10}, {11, 12}};
    double tab8[SIZES][SIZES] = {{5, 6}, {7, 8}};
    a = Macierz3x3(tab0);
    b = Macierz3x3(tab1);
    c = Macierz3x3(tab2);
    d = Macierz3x3(tab3);
    e = Macierz3x3(tab4);
    f = Macierz3x3(tab5);
    g = Macierz3x3(tab6);
    h = Macierz3x3(tab7);
    i = Macierz3x3(tab8);
    CHECK(a + b == g);
    CHECK(c + d == h);
    CHECK(e + f == i);
}
TEST_CASE("test operatora () 1")
{
    Macierz3x3 x;
    double tab1[SIZES][SIZES] = {{1, 2}, {3, 4}, {5, 6, 7}};
    x = Macierz3x3(tab1);
    double a, b, c, d, e, f, g, h, i;
    a = 1;
    b = 2;
    c = 0;
    d = 3;
    e = 4;
    f = 0;
    g = 5;
    h = 6;
    i = 7;
    CHECK(a == x(0, 0));
    CHECK(b == x(0, 1));
    CHECK(c == x(0, 2));
    CHECK(d == x(1, 0));
    CHECK(e == x(1, 1));
    CHECK(f == x(1, 2));
    CHECK(g == x(2, 0));
    CHECK(h == x(2, 1));
    CHECK(i == x(2, 2));
}
TEST_CASE("Twst tworzenie macierzy obrotu OX 1")
{
    double kat = 45, radian;
    Macierz3x3 x;
    x = Macierz3x3();
    radian = StopienNaRadianX(kat);
    Oblicz_Macierz_ObrotuX(radian, x);
    CHECK(x(0, 0) == 1);
    CHECK(x(0, 1) == 0);
    CHECK(x(0, 2) == 0);
    CHECK(x(1, 0) == 0);
    CHECK(x(1, 1) == cos(M_PI / 4));
    CHECK(x(1, 2) == -sin(M_PI / 4));
    CHECK(x(2, 0) == 0);
    CHECK(x(2, 1) == sin(M_PI / 4));
    CHECK(x(2, 2) == cos(M_PI / 4));
}

TEST_CASE("Twst tworzenie macierzy obrotu OY 1")
{
    double kat = 60, radian;
    Macierz3x3 x;
    x = Macierz3x3();
    radian = StopienNaRadianY(kat);
    Oblicz_Macierz_ObrotuY(radian, x);
    CHECK(x(0, 0) == cos(M_PI / 3));
    CHECK(x(0, 1) == 0);
    CHECK(x(0, 2) == sin(M_PI / 3));
    CHECK(x(1, 0) == 0);
    CHECK(x(1, 1) == 1);
    CHECK(x(1, 2) == 0);
    CHECK(x(2, 0) == -sin(M_PI / 3));
    CHECK(x(2, 1) == 0);
    CHECK(x(2, 2) == cos(M_PI / 3));
}
TEST_CASE("Twst tworzenie macierzy obrotu OZ 1")
{
    double kat = 30, radian;
    Macierz3x3 x;
    x = Macierz3x3();
    radian = StopienNaRadianZ(kat);
    Oblicz_Macierz_ObrotuZ(radian, x);
    CHECK(x(0, 0) == cos(M_PI / 6));
    CHECK(x(0, 1) == -sin(M_PI / 6));
    CHECK(x(0, 2) == 0);
    CHECK(x(1, 0) == sin(M_PI / 6));
    CHECK(x(1, 1) == cos(M_PI / 6));
    CHECK(x(1, 2) == 0);
    CHECK(x(2, 0) == 0);
    CHECK(x(2, 1) == 0);
    CHECK(x(2, 2) == 1);
}
/*!
 * Prostopadloscian
 * 
 */
TEST_CASE("Test Prostopadloscian konstruktor 1")
{
    Prostopadloscian x;
    x = Prostopadloscian();
    CHECK(x[0][0] == 0);
    CHECK(x[1][0] == 0);
    CHECK(x[2][0] == 0);
    CHECK(x[3][0] == 0);
    CHECK(x[4][0] == 0);
    CHECK(x[5][0] == 0);
    CHECK(x[6][0] == 0);
    CHECK(x[7][0] == 0);
    CHECK(x[0][1] == 0);
    CHECK(x[1][1] == 0);
    CHECK(x[2][1] == 0);
    CHECK(x[3][1] == 0);
    CHECK(x[4][1] == 0);
    CHECK(x[5][1] == 0);
    CHECK(x[6][1] == 0);
    CHECK(x[7][1] == 0);
    CHECK(x[0][2] == 0);
    CHECK(x[1][2] == 0);
    CHECK(x[2][2] == 0);
    CHECK(x[3][2] == 0);
    CHECK(x[4][2] == 0);
    CHECK(x[5][2] == 0);
    CHECK(x[6][2] == 0);
    CHECK(x[7][2] == 0);
}
TEST_CASE("Test Prostopadloscian konstruktor 2")
{
    Prostopadloscian x = Prostopadloscian();
    Wektor3D poczatek = Wektor3D({2, 2, 2});
    x = Prostopadloscian(poczatek, 30, 60, 40);
    CHECK(x[0][0] == 2);
    CHECK(x[1][0] == 62);
    CHECK(x[2][0] == 62);
    CHECK(x[3][0] == 2);
    CHECK(x[4][0] == 2);
    CHECK(x[5][0] == 62);
    CHECK(x[6][0] == 62);
    CHECK(x[7][0] == 2);

    CHECK(x[0][1] == 2);
    CHECK(x[1][1] == 2);
    CHECK(x[2][1] == 2);
    CHECK(x[3][1] == 2);
    CHECK(x[4][1] == 32);
    CHECK(x[5][1] == 32);
    CHECK(x[6][1] == 32);
    CHECK(x[7][1] == 32);

    CHECK(x[0][2] == 2);
    CHECK(x[1][2] == 2);
    CHECK(x[2][2] == 42);
    CHECK(x[3][2] == 42);
    CHECK(x[4][2] == 2);
    CHECK(x[5][2] == 2);
    CHECK(x[6][2] == 42);
    CHECK(x[7][2] == 42);
}
TEST_CASE("test Prostopadloscian [] 1")
{
    Prostopadloscian x = Prostopadloscian();
    Wektor3D poczatek = Wektor3D({0, 0, 0});
    x = Prostopadloscian(poczatek, 30, 60, 90);
    std::ostringstream out0;
    out0 << x[0];
    std::cout << out0.str() << std::endl;
    CHECK("0 0 0" == out0.str());
    std::ostringstream out1;
    out1 << x[1];
    std::cout << out1.str() << std::endl;
    CHECK("60 0 0" == out1.str());
    std::ostringstream out2;
    out2 << x[2];
    std::cout << out2.str() << std::endl;
    CHECK("60 0 90" == out2.str());
    std::ostringstream out3;
    out3 << x[3];
    std::cout << out3.str() << std::endl;
    CHECK("0 0 90" == out3.str());

    std::ostringstream out4;
    out4 << x[4];
    std::cout << out4.str() << std::endl;
    CHECK("0 30 0" == out4.str());
    std::ostringstream out5;
    out5 << x[5];
    std::cout << out5.str() << std::endl;
    CHECK("60 30 0" == out5.str());
    std::ostringstream out6;
    out6 << x[6];
    std::cout << out6.str() << std::endl;
    CHECK("60 30 90" == out6.str());
    std::ostringstream out7;
    out7 << x[7];
    std::cout << out7.str() << std::endl;
    CHECK("0 30 90" == out7.str());
}
TEST_CASE("Test Prostopadloscian translacja 1")
{
    Prostopadloscian x = Prostopadloscian();
    Wektor3D translacja = Wektor3D();
    Wektor3D poczatek = Wektor3D({2, 2, 2});
    x = Prostopadloscian(poczatek, 30, 60, 90);
    translacja = Wektor3D({2, 2, 2});
    x = x + translacja;

    CHECK(x[0][0] == 4);
    CHECK(x[1][0] == 64);
    CHECK(x[2][0] == 64);
    CHECK(x[3][0] == 4);
    CHECK(x[4][0] == 4);
    CHECK(x[5][0] == 64);
    CHECK(x[6][0] == 64);
    CHECK(x[7][0] == 4);
    CHECK(x[0][1] == 4);
    CHECK(x[1][1] == 4);
    CHECK(x[2][1] == 4);
    CHECK(x[3][1] == 4);
    CHECK(x[4][1] == 34);
    CHECK(x[5][1] == 34);
    CHECK(x[6][1] == 34);
    CHECK(x[7][1] == 34);
    CHECK(x[0][2] == 4);
    CHECK(x[1][2] == 4);
    CHECK(x[2][2] == 94);
    CHECK(x[3][2] == 94);
    CHECK(x[4][2] == 4);
    CHECK(x[5][2] == 4);
    CHECK(x[6][2] == 94);
    CHECK(x[7][2] == 94);
}
TEST_CASE("Test Prostopadloscian translacja 2")
{
    Prostopadloscian x = Prostopadloscian();
    Wektor3D translacja = Wektor3D();
    Wektor3D poczatek = Wektor3D({2, 2, 2});
    x = Prostopadloscian(poczatek, 30, 60, 90);
    translacja = Wektor3D({-2, -2, -2});
    x = x + translacja;
    CHECK(x[0][0] == 0);
    CHECK(x[1][0] == 60);
    CHECK(x[2][0] == 60);
    CHECK(x[3][0] == 0);
    CHECK(x[4][0] == 0);
    CHECK(x[5][0] == 60);
    CHECK(x[6][0] == 60);
    CHECK(x[7][0] == 0);
    CHECK(x[0][1] == 0);
    CHECK(x[1][1] == 0);
    CHECK(x[2][1] == 0);
    CHECK(x[3][1] == 0);
    CHECK(x[4][1] == 30);
    CHECK(x[5][1] == 30);
    CHECK(x[6][1] == 30);
    CHECK(x[7][1] == 30);
    CHECK(x[0][2] == 0);
    CHECK(x[1][2] == 0);
    CHECK(x[2][2] == 90);
    CHECK(x[3][2] == 90);
    CHECK(x[4][2] == 0);
    CHECK(x[5][2] == 0);
    CHECK(x[6][2] == 90);
    CHECK(x[7][2] == 90);
}

TEST_CASE("Test Prostopadloscian sprawdzanie długości 1")
{
    Prostopadloscian x = Prostopadloscian();
    Prostopadloscian y = Prostopadloscian();
    Wektor3D poczatek;
    double kat = 45, radianX, radianY, radianZ;
    poczatek = Wektor3D();
    x = Prostopadloscian(poczatek, 100, 200, 70);
    y = Prostopadloscian(poczatek, 300, 400, 80);
    Macierz3x3 obrotX = Macierz3x3();
    Macierz3x3 obrotY = Macierz3x3();
    Macierz3x3 obrotZ = Macierz3x3();

    radianX = StopienNaRadianX(kat);
    Oblicz_Macierz_ObrotuX(radianX, obrotX);

    radianY = StopienNaRadianY(kat);
    Oblicz_Macierz_ObrotuY(radianY, obrotY);

    radianZ = StopienNaRadianZ(kat);
    Oblicz_Macierz_ObrotuZ(radianZ, obrotZ);
    for (int i = 0; i < 6; ++i)
    {
        x = x * obrotX;
        x = x * obrotY;
        x = x * obrotZ;
    }
    for (long int j = 0; j < 360000; ++j)
    {
        y = y * obrotX;
        y = y * obrotY;
        y = y * obrotZ;
    }
    x.dlugosc();
    y.dlugosc();
}
TEST_CASE("Test macierz razy macierz 1")
{
    Macierz3x3 x, y, z, t;
    x = Macierz3x3();
    y = Macierz3x3();
    z = Macierz3x3();
    t = Macierz3x3();
    double tabx[3][3] = {{1, 2, 2}, {3, 4, 5}, {3, 4, 5}}, taby[3][3] = {{2, 3, 8}, {4, 7, 9}, {6, 7, 8}}, tabz[3][3] = {{22, 31, 42}, {52, 72, 100}, {52, 72, 100}};

    x = Macierz3x3(tabx);
    y = Macierz3x3(taby);
    z = Macierz3x3(tabz);
    t = x * y;
    std::cout << std::endl
              << t << std::endl;
    CHECK(z == t);
}
TEST_CASE("Test macierzy 4x4 z modyfikacji 1")
{
    Macierz4x4 MacierzT;
    double X = 45, Y = 30, Z = 60;
    Wektor3D Wek = {30, 40, 50};
    Oblicz_Macierz4x4(X, Y, Z, Wek, MacierzT);
    std::cout << MacierzT;
    std::cout << std::endl;
}

TEST_CASE("Test macierzy 4x4 z modyfikacji 2")
{
    Macierz4x4 MacierzT;
    double X = 48, Y = 37, Z = 63;
    Wektor3D Wek = {30, 40, 50};
    Oblicz_Macierz4x4(X, Y, Z, Wek, MacierzT);
    std::cout << MacierzT;
}
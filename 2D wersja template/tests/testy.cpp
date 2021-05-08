#include "../tests/doctest/doctest.h"
#include "Prostokat2.hh"
TEST_CASE("test Wektor2D konstruktor 1")
{
  Wektor2D x;
  x = Wektor2D();

  CHECK(x[0] == 0);
  CHECK(x[1] == 0);
}
TEST_CASE("test Wektor2D konstrunktor 2")
{
  Wektor2D x;
  x = Wektor2D({1, 2});

  CHECK(x[0] == 1);
  CHECK(x[1] == 2);
}
TEST_CASE("test Wektor2D Suma 1")
{
  Wektor2D x, y, z;
  x = Wektor2D({1.0, 2.0});
  y = Wektor2D({3.0, 4.0});
  z = Wektor2D({4.0, 6.0});

  CHECK(x + y == z);
}

TEST_CASE("test Wektor2D Suma 2")
{
  Wektor2D x, y, z;
  x = Wektor2D({6, 6});
  y = Wektor2D({2, -3});
  z = Wektor2D({8, 3});
  CHECK(x + y == z);
}
TEST_CASE("test Wektor2D Suma 3")
{
  Wektor2D x, y, z;
  x = Wektor2D({6, 6});
  y = Wektor2D({0, 0});
  z = Wektor2D({6, 6});
  CHECK(x + y == z);
}
TEST_CASE("test Wektor2D Suma 4")
{
  Wektor2D x, y, z;
  x = Wektor2D({6, 6});
  y = Wektor2D({0.0, 0.0});
  z = Wektor2D({6, 6});
  CHECK(x + y == z);
}
TEST_CASE("test Wektor2D Suma 5")
{
  Wektor2D x, y, z;
  x = Wektor2D({6, 6});
  y = Wektor2D({0.00000000001, 0.00000000001});
  z = Wektor2D({6, 6});
  CHECK(x + y == z);
}
TEST_CASE("test Wektor2D Suma 6")
{
  Wektor2D x, y, z;
  x = Wektor2D({6, 6});
  y = Wektor2D({0.00000000009, 0.00000000009});
  z = Wektor2D({6, 6});
  CHECK(x + y == z);
}
TEST_CASE("test Wektor2D Różnica 1")
{
  Wektor2D x, y, z;
  x = Wektor2D({1, 1});
  y = Wektor2D({1, -3});
  z = Wektor2D({0, 4});
  CHECK(x - y == z);
}
TEST_CASE("test Wektor2D Różnica 2")
{
  Wektor2D x, y, z;
  x = Wektor2D({5, 6});
  y = Wektor2D({2, 3});
  z = Wektor2D({3, 3});
  CHECK(x - y == z);
}
TEST_CASE("test Wektor2D Różnica 3")
{
  Wektor2D x, y, z;
  x = Wektor2D({2, 2});
  y = Wektor2D({0, 0});
  z = Wektor2D({2, 2});
  CHECK(x - y == z);
}
TEST_CASE("test Wektor2D Różnica 4")
{
  Wektor2D x, y, z;
  x = Wektor2D({1, 1});
  y = Wektor2D({0.0, 0.0});
  z = Wektor2D({1, 1});
  CHECK(x - y == z);
}

TEST_CASE("test Wektor2D Różnica 5")
{
  Wektor2D x, y, z;
  x = Wektor2D({6, 6});
  y = Wektor2D({0.00000000001, 0.00000000001});
  z = Wektor2D({6, 6});
  CHECK(x - y == z);
}
TEST_CASE("test Wektor2D Różnica 6")
{
  Wektor2D x, y, z;
  x = Wektor2D({6, 6});
  y = Wektor2D({0.00000000009, 0.00000000009});
  z = Wektor2D({6, 6});
  CHECK(x - y == z);
}
TEST_CASE("test operatora [] 1")
{
  Wektor2D x, y, z;
  x = Wektor2D({6, 7});
  y = Wektor2D({8, 9});
  z = Wektor2D({16, 126});
  double a, b, c, d, e, f;
  a = 6;
  b = 7;
  c = 8;
  d = 9;
  e = 16;
  f = 126;

  CHECK(a == x[0]);
  CHECK(b == x[1]);
  CHECK(c == y[0]);
  CHECK(d == y[1]);
  CHECK(e == z[0]);
  CHECK(f == z[1]);
}
TEST_CASE("test dzielenie Wektor2D 1")
{
  Wektor2D x, wynik;
  double dzielnik = 3;
  x = Wektor2D({6, 9});
  wynik = x / dzielnik;
  CHECK(wynik[0] == 2);
  CHECK(wynik[1] == 3);
}
TEST_CASE("test dzielenie Wektor2D 2")
{
  Wektor2D x, wynik;
  double dzielnik = 3;
  x = Wektor2D({2, 2});
  wynik = x / dzielnik;
  CHECK(wynik[0] == 0.666666666666666667);
  CHECK(wynik[1] == 0.666666666666666667);
}
TEST_CASE("test dzielenie Wektor2D 3")
{
  Wektor2D x;
  double dzielnik = 0;
  x = Wektor2D({2, 2});
  WARN_THROWS(x / dzielnik);
}
TEST_CASE("test mnozenie Wektor2D 1")
{
  Wektor2D x, wynik;
  double mnozenie = 3;
  x = Wektor2D({6, 9});
  wynik = x * mnozenie;
  CHECK(wynik[0] == 18);
  CHECK(wynik[1] == 27);
}
TEST_CASE("test mnozenie Wektor2D 2")
{
  Wektor2D x, wynik;
  double mnozenie = 0;
  x = Wektor2D({6, 9});
  wynik = x * mnozenie;
  CHECK(wynik[0] == 0);
  CHECK(wynik[1] == 0);
}
TEST_CASE("test wyświetlanie Wektor2D standard")
{
  Wektor2D x;
  x = Wektor2D({6, 7});
  std::ostringstream out;
  out << x;
  std::cout << out.str();
  CHECK("6 7" == out.str());
}

TEST_CASE("test wczytywanie Wektor2D standard")
{
  Wektor2D x;

  std::istringstream in("21 37");
  in >> x;
  std::ostringstream out;
  out << x;
  std::cout << out.str() << std::endl;
  CHECK("21 37" == out.str());
}
/*!
 * 
 * Macierz
 */

TEST_CASE("Test martix konstruktor 1")
{
  Macierz2D x;
  x = Macierz2D();
  CHECK(x(0, 0) == 0);
  CHECK(x(0, 1) == 0);
  CHECK(x(1, 0) == 0);
  CHECK(x(1, 1) == 0);
}
TEST_CASE("Test martix konstruktor 2")
{
  Macierz2D x;
  double tab[SIZE][SIZE] = {{1, 2}, {3, 4}};
  x = Macierz2D(tab);
  CHECK(x(0, 0) == 1);
  CHECK(x(0, 1) == 2);
  CHECK(x(1, 0) == 3);
  CHECK(x(1, 1) == 4);
}
// TEST_CASE("test mnozenie macierz razy Wektor2D 1")
// {
//   Wektor2D x, wynik;
//   Macierz2D obrot = Macierz2D();
//   obrot.przypisz_stopnie(90);
//   obrot.StopienNaRadian();
//   obrot.Oblicz_Macierz_Obrotu();
//   x = Wektor2D({0, 2});
//   x = obrot * x;
//   wynik = Wektor2D({-2, 0});
//   CHECK(wynik == x);
// }
// TEST_CASE("test mnozenie macierz razy Wektor2D 2")
// {
//   Wektor2D x, wynik;
//   Macierz2D obrot = Macierz2D();
//   obrot.przypisz_stopnie(45);
//   obrot.StopienNaRadian();
//   obrot.Oblicz_Macierz_Obrotu();
//   x = Wektor2D({2, 0});
//   x = obrot * x;
//   wynik = Wektor2D({sqrt(2), sqrt(2)});
//   CHECK(wynik == x);
// }
TEST_CASE("Test martix dodawanie 1")
{
  Macierz2D a, b, c, d, e, f;
  double tab0[SIZE][SIZE] = {{1, 2}, {3, 4}};
  double tab1[SIZE][SIZE] = {{5, 6}, {7, 8}};
  double tab2[SIZE][SIZE] = {{9, 10}, {11, 12}};
  double tab3[SIZE][SIZE] = {{13, 14}, {15, 16}};
  double tab4[SIZE][SIZE] = {{6, 8}, {10, 12}};
  double tab5[SIZE][SIZE] = {{22, 24}, {26, 28}};
  a = Macierz2D(tab0);
  b = Macierz2D(tab1);
  c = Macierz2D(tab2);
  d = Macierz2D(tab3);
  e = Macierz2D(tab4);
  f = Macierz2D(tab5);
  CHECK(a + b == e);
  CHECK(c + d == f);
}
TEST_CASE("Test martix dodawanie 2")
{
  Macierz2D a, b, c, d, e, f, g, h, i;
  double tab0[SIZE][SIZE] = {{1, 2}, {3, 4}};
  double tab1[SIZE][SIZE] = {{0.00000000001, 0.00000000001}, {0.00000000001, 0.00000000001}};
  double tab2[SIZE][SIZE] = {{9, 10}, {11, 12}};
  double tab3[SIZE][SIZE] = {{0.000000000001, 0.000000000001}, {0.000000000001, 0.000000000001}};
  double tab4[SIZE][SIZE] = {{5, 6}, {7, 8}};
  double tab5[SIZE][SIZE] = {{0.000000000009, 0.000000000009}, {0.000000000009, 0.000000000009}};
  double tab6[SIZE][SIZE] = {{1, 2}, {3, 4}};
  double tab7[SIZE][SIZE] = {{9, 10}, {11, 12}};
  double tab8[SIZE][SIZE] = {{5, 6}, {7, 8}};
  a = Macierz2D(tab0);
  b = Macierz2D(tab1);
  c = Macierz2D(tab2);
  d = Macierz2D(tab3);
  e = Macierz2D(tab4);
  f = Macierz2D(tab5);
  g = Macierz2D(tab6);
  h = Macierz2D(tab7);
  i = Macierz2D(tab8);
  CHECK(a + b == g);
  CHECK(c + d == h);
  CHECK(e + f == i);
}
TEST_CASE("test operatora () 1")
{
  Macierz2D x, y, z;
  double tab1[2][2] = {{1, 2}, {3, 4}}, tab2[2][2] = {{5, 6}, {7, 8}}, tab3[2][2] = {{9, 10}, {11, 12}};
  x = Macierz2D(tab1);
  y = Macierz2D(tab2);
  z = Macierz2D(tab3);
  double a, b, c, d, e, f, g, h, i, j, k, l;
  a = 1;
  b = 2;
  c = 3;
  d = 4;
  e = 5;
  f = 6;
  g = 7;
  h = 8;
  i = 9;
  j = 10;
  k = 11;
  l = 12;
  CHECK(a == x(0, 0));
  CHECK(b == x(0, 1));
  CHECK(c == x(1, 0));
  CHECK(d == x(1, 1));
  CHECK(e == y(0, 0));
  CHECK(f == y(0, 1));
  CHECK(g == y(1, 0));
  CHECK(h == y(1, 1));
  CHECK(i == z(0, 0));
  CHECK(j == z(0, 1));
  CHECK(k == z(1, 0));
  CHECK(l == z(1, 1));
}
TEST_CASE("Twst tworzenie macierzy obrotu 1")
{
  double kat = 45, radian;
  Macierz2D obrot;
  obrot = Macierz2D();
  radian = StopienNaRadian(kat);
  Oblicz_Macierz_Obrotu(radian, obrot);
  CHECK(obrot(0, 0) == cos(M_PI / 4));
  CHECK(obrot(0, 1) == -sin(M_PI / 4));
  CHECK(obrot(1, 0) == sin(M_PI / 4));
  CHECK(obrot(1, 1) == cos(M_PI / 4));
}
/*!
 * Prostokat
 * 
 */
TEST_CASE("Test prostokat konstruktor 1")
{
  Prostokat x;
  x = Prostokat();
  CHECK(x[0][0] == 0);
  CHECK(x[1][0] == 0);
  CHECK(x[2][0] == 0);
  CHECK(x[3][0] == 0);
  CHECK(x[0][1] == 0);
  CHECK(x[1][1] == 0);
  CHECK(x[2][1] == 0);
  CHECK(x[3][1] == 0);
}
TEST_CASE("Test prostokat konstruktor 2")
{
  Prostokat x = Prostokat();
  Wektor2D poczatek = Wektor2D({2, 2});
  x = Prostokat(poczatek, 30, 60);
  CHECK(x[0][0] == 2);
  CHECK(x[1][0] == 2);
  CHECK(x[2][0] == 62);
  CHECK(x[3][0] == 62);
  CHECK(x[0][1] == 2);
  CHECK(x[1][1] == 32);
  CHECK(x[2][1] == 32);
  CHECK(x[3][1] == 2);
}
TEST_CASE("test prostokat [] 1")
{
  Prostokat x = Prostokat();
  Wektor2D poczatek = Wektor2D({0, 0});
  x = Prostokat(poczatek, 30, 60);
  std::ostringstream out0;
  out0 << x[0];
  std::cout << out0.str() << std::endl;
  CHECK("0 0" == out0.str());
  std::ostringstream out1;
  out1 << x[1];
  std::cout << out1.str() << std::endl;
  CHECK("0 30" == out1.str());
  std::ostringstream out2;
  out2 << x[2];
  std::cout << out2.str() << std::endl;
  CHECK("60 30" == out2.str());
  std::ostringstream out3;
  out3 << x[3];
  std::cout << out3.str() << std::endl;
  CHECK("60 0" == out3.str());
}
TEST_CASE("Test prostokat translacja 1")
{
  Prostokat x = Prostokat();
  Wektor2D translacja = Wektor2D();
  Wektor2D poczatek = Wektor2D({2, 2});
  x = Prostokat(poczatek, 30, 60);
  translacja = Wektor2D({2, 2});
  x = x + translacja;
  CHECK(x[0][0] == 4);
  CHECK(x[1][0] == 4);
  CHECK(x[2][0] == 64);
  CHECK(x[3][0] == 64);
  CHECK(x[0][1] == 4);
  CHECK(x[1][1] == 34);
  CHECK(x[2][1] == 34);
  CHECK(x[3][1] == 4);
}
TEST_CASE("Test prostokat translacja 2")
{
  Prostokat x = Prostokat();
  Wektor2D translacja = Wektor2D();
  Wektor2D poczatek = Wektor2D({2, 2});
  x = Prostokat(poczatek, 30, 60);
  translacja = Wektor2D({-2, -2});
  x = x + translacja;
  CHECK(x[0][0] == 0);
  CHECK(x[1][0] == 0);
  CHECK(x[2][0] == 60);
  CHECK(x[3][0] == 60);
  CHECK(x[0][1] == 0);
  CHECK(x[1][1] == 30);
  CHECK(x[2][1] == 30);
  CHECK(x[3][1] == 0);
}

TEST_CASE("Test prostokat sprawdzanie długości 1")
{
  Prostokat x = Prostokat();
  Prostokat y = Prostokat();
  Wektor2D poczatek;
  double kat = 45, radian;
  poczatek = Wektor2D({0, 0});
  x = Prostokat(poczatek, 100, 200);
  y = Prostokat(poczatek, 300, 400);
  Macierz2D obrot = Macierz2D();
  radian = StopienNaRadian(kat);
  Oblicz_Macierz_Obrotu(radian, obrot);
  for (int i = 0; i < 360; ++i)
  {
    x = x * obrot;
  }
  for (long int j = 0; j < 360000; ++j)
  {
    y = y * obrot;
  }
  x.dlugosc();
  y.dlugosc();
}
TEST_CASE("Test macierz razy macierz 1")
{
  Macierz2D x, y, z, t;
  x = Macierz2D();
  y = Macierz2D();
  z = Macierz2D();
  t = Macierz2D();
  double tabx[2][2] = {{1, 2}, {3, 4}}, taby[2][2] = {{2, 3}, {4, 7}}, tabz[2][2] = {{10, 17}, {22, 37}};

  x = Macierz2D(tabx);
  y = Macierz2D(taby);
  z = Macierz2D(tabz);
  t = x * y;
  std::cout << t << std::endl;
  CHECK(z == t);
}
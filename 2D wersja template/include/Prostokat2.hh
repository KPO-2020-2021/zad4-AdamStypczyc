#ifndef PROSTOKAT2_HH
#define PROSTOKAT2_HH
#include <iomanip>
#include "Macierz2d.hh"
#include "Wektor2d.hh"
#include "size.hh"

class Prostokat
{
private:
    Wektor2D wspol[4]; //prostokąt jako tablica 4 wektorów

public:
    Prostokat();                                            //konstruktor bezparametryczny
    Prostokat(Wektor2D poczatek, double h = 0, double w = 0); //konstruktor parametryczny określający prostokąt poprzez podaną jego szerokość i wysokość
    Wektor2D &operator[](int i);                              //operator indeksowanie set
    const Wektor2D operator[](int i) const;                   //operator indeksowanie get
    Prostokat operator+(const Wektor2D translacja);           //operator dodawania
    void dlugosc();                                         //sprawdzanie długości boków po obrocie
    Prostokat &operator*(Macierz2D Macierz_obrotu);            //mnożenie prostokąt razy macierz
};
Prostokat::Prostokat()
{
    for (int i = 0; i < 2 * SIZE; i++)
    {
        wspol[i] = Wektor2D();
    }
}
Prostokat::Prostokat(Wektor2D poczatek, double h, double w)
{
    for (int i = 0; i < 2 * SIZE; i++)
    {
        wspol[i] = poczatek;
    }
    wspol[1][1] += h;
    wspol[2][0] += w;
    wspol[2][1] += h;
    wspol[3][0] += w;
}
Wektor2D &Prostokat::operator[](int i)
{
    return wspol[i];
}
const Wektor2D Prostokat::operator[](int i) const
{
    return wspol[i];
}
Prostokat Prostokat::operator+(const Wektor2D translacja)
{
    for (int i = 0; i < 2 * SIZE; i++)
    {
        wspol[i] = wspol[i] + translacja;
    }
    return *this;
}
void Prostokat::dlugosc()
{
    double Wek0[2], Wek1[2], Wek2[2], Wek3[2]; //wekotry, dzięki którym poprzez licznie długości wektora są obliczane długości boków prostokąta
    double Bok1, Bok2, Bok3, Bok0;             // boki prostokata
    Wek0[0] = wspol[0][0] - wspol[1][0];       //x        wektory obliczane są ze wzorów matematycznych
    Wek0[1] = wspol[0][1] - wspol[1][1];       //y

    Wek1[0] = wspol[1][0] - wspol[2][0]; //x
    Wek1[1] = wspol[1][1] - wspol[2][1]; //y

    Wek2[0] = wspol[2][0] - wspol[3][0]; //x
    Wek2[1] = wspol[2][1] - wspol[3][1]; //y

    Wek3[0] = wspol[3][0] - wspol[0][0]; //x
    Wek3[1] = wspol[3][1] - wspol[0][1]; //y

    Bok0 = sqrt(pow(Wek0[0], 2) + pow(Wek0[1], 2)); //długości obliczone ze wzoru
    Bok1 = sqrt(pow(Wek1[0], 2) + pow(Wek1[1], 2));
    Bok2 = sqrt(pow(Wek2[0], 2) + pow(Wek2[1], 2));
    Bok3 = sqrt(pow(Wek3[0], 2) + pow(Wek3[1], 2));
    std::cout << std::endl;
    if (std::abs(Bok0 - Bok2) <= MIN_DIFF && std::abs(Bok1 - Bok3) <= MIN_DIFF) //jeżeli różnica długości boków mniejsza niż MIN_DIFF to wszystko w porządku
    {
        std::cout << ":) Naprzeciwległe boki są sobie równe, a ich długości wynoszą: " << std::endl;
    }
    else
    {
        std::cout << ":( Naprzeciwległe boki nie są sobie równe, a ich długości wynoszą: " << std::endl;
    }
    std::cout << std::fixed << std::setprecision(10) << Bok0 << std::endl;
    std::cout << std::fixed << std::setprecision(10) << Bok1 << std::endl;
    std::cout << std::fixed << std::setprecision(10) << Bok2 << std::endl;
    std::cout << std::fixed << std::setprecision(10) << Bok3 << std::endl;
}
Prostokat &Prostokat::operator*(Macierz2D Macierz_obrotu)
{
    for (int i = 0; i < 2 * SIZE; i++)
    {
        double _x = wspol[i][0]; //przypisujemy do zmiennych pomocniczych, żeby nie zmienić przypadkowo wartości i nie operować na błędnej wartości
        double _y = wspol[i][1];
        wspol[i][0] = _x * Macierz_obrotu(0, 0) + _y * Macierz_obrotu(0, 1);
        wspol[i][1] = _x * Macierz_obrotu(1, 0) + _y * Macierz_obrotu(1, 1);
    }
    return *this;
}
std::ostream &operator<<(std::ostream &Strm, const Prostokat &Pr);
std::istream &operator>>(std::istream &Strm, const Prostokat &Pr);

std::ostream &operator<<(std::ostream &Strm, const Prostokat &Pr)
{
    for (int i = 0; i < 2 * SIZE; i++)
    {
        Strm << std::setw(20) << std::fixed << std::setprecision(10) << Pr[i] << std::endl;
    }
    Strm << std::setw(20) << std::fixed << std::setprecision(10) << Pr[0] << std::endl;
    return Strm;
}

std::istream &operator>>(std::istream &Strm, const Prostokat &Pr)
{
    for (int i = 0; i < 2 * SIZE; ++i)
    {
        Strm >> Pr[i];
    }
    std::cout << std::endl;
    return Strm;
}
#endif

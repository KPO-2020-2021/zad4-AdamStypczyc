#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "wektor.hh"

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
class Macierz
{

private:
    Templ_Typ value[Templ_Rozmiar][Templ_Rozmiar]; // Wartosci macierzy

public:
    Macierz(Templ_Typ tmp[Templ_Rozmiar][Templ_Rozmiar]); // Konstruktor klasy

    Macierz(); // Konstruktor klasy

    Macierz operator+(Macierz tmp);
    Macierz operator-(Macierz tmp);
    Macierz operator*(Macierz tmp);

    Templ_Typ &operator()(unsigned int row, unsigned int column);

    const Templ_Typ &operator()(unsigned int row, unsigned int column) const;

    bool operator==(const Macierz tmp) const;
};
template <typename Templ_Typ, unsigned int Templ_Rozmiar>
Macierz<Templ_Typ, Templ_Rozmiar>::Macierz(Templ_Typ tmp[Templ_Rozmiar][Templ_Rozmiar])
{
    for (unsigned int index = 0; index < Templ_Rozmiar; ++index)
    {
        for (unsigned int j = 0; j < Templ_Rozmiar; ++j)
        {
            value[index][j] = tmp[index][j];
        }
    }
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
Macierz<Templ_Typ, Templ_Rozmiar>::Macierz()
{
    for (unsigned int i = 0; i < Templ_Rozmiar; ++i)
    {
        for (unsigned int j = 0; j < Templ_Rozmiar; ++j)
        {
            value[i][j] = 0;
        }
    }
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
Macierz<Templ_Typ, Templ_Rozmiar> Macierz<Templ_Typ, Templ_Rozmiar>::operator+(Macierz<Templ_Typ, Templ_Rozmiar> tmp)
{
    Macierz result = Macierz();
    for (unsigned int i = 0; i < Templ_Rozmiar; ++i)
    {
        for (unsigned int j = 0; j < Templ_Rozmiar; ++j)
        {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
Macierz<Templ_Typ, Templ_Rozmiar> Macierz<Templ_Typ, Templ_Rozmiar>::operator-(Macierz<Templ_Typ, Templ_Rozmiar> tmp)
{
    Macierz result = Macierz();
    for (unsigned int i = 0; i < Templ_Rozmiar; ++i)
    {
        for (unsigned int j = 0; j < Templ_Rozmiar; ++j)
        {
            result(i, j) = this->value[i][j] - tmp(i, j);
        }
    }
    return result;
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
Macierz<Templ_Typ, Templ_Rozmiar> Macierz<Templ_Typ, Templ_Rozmiar>::operator*(Macierz<Templ_Typ, Templ_Rozmiar> tmp)
{
    Macierz result = Macierz();
    for (unsigned int i = 0; i < Templ_Rozmiar; ++i)
    {
        for (unsigned int j = 0; j < Templ_Rozmiar; ++j)
        {
            for (unsigned int k = 0; k < Templ_Rozmiar; ++k)
            {
                result(i, j) += this->value[i][k] * tmp(k, j);
            }
        }
    }
    return result;
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
Templ_Typ &Macierz<Templ_Typ, Templ_Rozmiar>::operator()(unsigned int row, unsigned int column)
{
    if (row >= Templ_Rozmiar)
    {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0);
    }

    if (column >= Templ_Rozmiar)
    {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0);
    }
    return value[row][column];
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
const Templ_Typ &Macierz<Templ_Typ, Templ_Rozmiar>::operator()(unsigned int row, unsigned int column) const
{
    if (row >= Templ_Rozmiar)
    {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= Templ_Rozmiar)
    {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}


template <typename Templ_Typ, unsigned int Templ_Rozmiar>
bool Macierz<Templ_Typ, Templ_Rozmiar>::operator==(const Macierz<Templ_Typ, Templ_Rozmiar> tmp) const
{
    int liczenie = 0;
    for (unsigned int i = 0; i < Templ_Rozmiar; ++i)
    {
        for (unsigned int j = 0; j < Templ_Rozmiar; ++j)
        {
            if (std::abs(value[i][j] - tmp(i, j)) <= MIN_DIFF)
            {
                ++liczenie;
            }
        }
    }
    if (liczenie == pow(Templ_Rozmiar, 2))
    {
        return true;
    }
    return false;
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
std::istream &operator>>(std::istream &in, Macierz<Templ_Typ, Templ_Rozmiar> &mat)
{
    for (unsigned int i = 0; i < Templ_Rozmiar; ++i)
    {
        for (unsigned int j = 0; j < Templ_Rozmiar; ++j)
        {
            in >> mat(i, j);
        }
    }
    return in;
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
std::ostream &operator<<(std::ostream &out, Macierz<Templ_Typ, Templ_Rozmiar> const &mat)
{
    for (unsigned int i = 0; i < Templ_Rozmiar; ++i)
    {
        for (unsigned int j = 0; j < Templ_Rozmiar; ++j)
        {
            out << "| " << mat(i, j) << " | ";
        }
        std::cout << std::endl;
    }
    return out;
}
#endif
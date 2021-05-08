#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <cassert>
#include <initializer_list>
#define MIN_DIFF 0.0000000001

template <typename Templ_Typ_Wektor, unsigned int Templ_Rozmiar_Wektor>
class Wektor
{
    Templ_Typ_Wektor wektorek[Templ_Rozmiar_Wektor];

public:
    Wektor();
    Wektor(const std::initializer_list<Templ_Typ_Wektor> &ListaWsp);
    Templ_Typ_Wektor operator[](unsigned int Index) const
    {
        assert(Index < Templ_Rozmiar_Wektor);
        return wektorek[Index];
    }
    Templ_Typ_Wektor &operator[](unsigned int Index)
    {
        assert(Index < Templ_Rozmiar_Wektor);
        return wektorek[Index];
    }

    Wektor operator+(const Wektor &v);

    Wektor operator-(const Wektor &v);

    Wektor operator*(const Templ_Typ_Wektor &tmp);

    Wektor operator/(const Templ_Typ_Wektor &tmp);

    bool operator==(const Wektor V) const;
};
template <typename Templ_Typ_Wektor, unsigned int Templ_Rozmiar_Wektor>
Wektor<Templ_Typ_Wektor, Templ_Rozmiar_Wektor>::Wektor()
{
    for (Templ_Typ_Wektor &wektork_i : wektorek)
    {
        wektork_i = 0;
    }
}
template <typename Templ_Typ_Wektor, unsigned int Templ_Rozmiar_Wektor>
Wektor<Templ_Typ_Wektor, Templ_Rozmiar_Wektor>::Wektor(const std::initializer_list<Templ_Typ_Wektor> &ListaWsp) : Wektor()
{
    assert(ListaWsp.size() <= Templ_Rozmiar_Wektor);
    int index = -1;
    for (double wartosc_i : ListaWsp)
    {
        wektorek[++index] = wartosc_i;
    }
}
template <typename Templ_Typ_Wektor, unsigned int Templ_Rozmiar_Wektor>
Wektor<Templ_Typ_Wektor, Templ_Rozmiar_Wektor> Wektor<Templ_Typ_Wektor, Templ_Rozmiar_Wektor>::operator+(const Wektor<Templ_Typ_Wektor, Templ_Rozmiar_Wektor> &v)
{
    Wektor result;
    for (unsigned int i = 0; i < Templ_Rozmiar_Wektor; ++i)
    {
        result[i] = wektorek[i] += v[i];
    }
    return result;
}

template <typename Templ_Typ_Wektor, unsigned int Templ_Rozmiar_Wektor>
Wektor<Templ_Typ_Wektor, Templ_Rozmiar_Wektor> Wektor<Templ_Typ_Wektor, Templ_Rozmiar_Wektor>::operator-(const Wektor<Templ_Typ_Wektor, Templ_Rozmiar_Wektor> &v)
{
    Wektor result;
    for (unsigned int i = 0; i < Templ_Rozmiar_Wektor; ++i)
    {
        result[i] = wektorek[i] -= v[i];
    }
    return result;
}

template <typename Templ_Typ_Wektor, unsigned int Templ_Rozmiar_Wektor>
Wektor<Templ_Typ_Wektor, Templ_Rozmiar_Wektor> Wektor<Templ_Typ_Wektor, Templ_Rozmiar_Wektor>::operator*(const Templ_Typ_Wektor &tmp)
{
    Wektor result;
    for (unsigned int i = 0; i < Templ_Rozmiar_Wektor; ++i)
    {
        result[i] = wektorek[i] *= tmp;
    }
    return result;
}

template <typename Templ_Typ_Wektor, unsigned int Templ_Rozmiar_Wektor>
Wektor<Templ_Typ_Wektor, Templ_Rozmiar_Wektor> Wektor<Templ_Typ_Wektor, Templ_Rozmiar_Wektor>::operator/(const Templ_Typ_Wektor &tmp)
{
    Wektor result;
    if (tmp == 0)
    {
        throw "Pamiętaj cho...o nie dziel przez zero";
    }
    for (unsigned int i = 0; i < Templ_Rozmiar_Wektor; ++i)
    {
        result[i] = wektorek[i] /= tmp;
    }
    return result;
}

template <typename Templ_Typ_Wektor, unsigned int Templ_Rozmiar_Wektor>
bool Wektor<Templ_Typ_Wektor, Templ_Rozmiar_Wektor>::operator==(const Wektor<Templ_Typ_Wektor, Templ_Rozmiar_Wektor> V) const
{
    int liczenie = 0;
    for (unsigned int i = 0; i < Templ_Rozmiar_Wektor; ++i)
    {
        if (std::abs(wektorek[i] - V[i]) <= MIN_DIFF)
        {
            ++liczenie;
        }
    }
    if (liczenie == Templ_Rozmiar_Wektor)
    {
        return true;
    }
    return false;
}

template <typename Templ_Typ_Wektor, unsigned int Templ_Rozmiar_Wektor>
std::ostream &operator<<(std::ostream &out, Wektor<Templ_Typ_Wektor, Templ_Rozmiar_Wektor> const &tmp)
{
    for (unsigned int Index = 0; Index < Templ_Rozmiar_Wektor; ++Index)
    {
        if(Index != Templ_Rozmiar_Wektor -1)
        {
            out << tmp[Index] << " ";
        }
        else 
        {
            out << tmp[Index];
        }
    }
    return out;
}

template <typename Templ_Typ_Wektor, unsigned int Templ_Rozmiar_Wektor>
std::istream &operator>>(std::istream &in, Wektor<Templ_Typ_Wektor, Templ_Rozmiar_Wektor> &tmp)
{
    for (unsigned int index = 0; index < Templ_Rozmiar_Wektor; ++index)
    {
        in >> tmp[index];
    }
    std::cout << std::endl;
    return in;
}
#endif
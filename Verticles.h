#pragma once
#include "Lista.h"

class krawedz;
class wierzcholek
{
public:
    lista<krawedz*> krawedzie;    // lista sasiadow o konkretuzacji typu wierzcholek
    int m_index;
    int kolor;
    ~wierzcholek();
    int get_index();
};

wierzcholek::~wierzcholek()
{
    for (node<krawedz*>* aktualny = krawedzie.get_first(); aktualny; aktualny = aktualny->get_next())
    {
        delete aktualny->get_val(); //niszczymy wartosc wezla
    }
}
int wierzcholek::get_index()
{
    return m_index;
}
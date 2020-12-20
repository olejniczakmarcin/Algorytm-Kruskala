#pragma once
#include "Verticles.h"

class krawedz
{  
public:
    wierzcholek* poczatek;
    wierzcholek* koniec;
    int waga;
    krawedz(wierzcholek* p, wierzcholek* k, int v);
    wierzcholek* get_poczatek();
    wierzcholek* get_koniec();
    int get_waga();
};

wierzcholek* krawedz::get_poczatek()
{
    return poczatek;
}
wierzcholek* krawedz::get_koniec()
{
    return koniec;
}
int krawedz::get_waga()
{
    return waga;
}
krawedz::krawedz(wierzcholek* p, wierzcholek* k, int v)
{
    poczatek = p;
    koniec = k;
    waga = v;
}
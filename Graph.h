#pragma once
#include "Vector.h"
#include "Edge.h"

class graf
{
public:
    wektor<wierzcholek*> wierzcholki;     // wektor wierzcholkow
    void dodaj_wierzcholek();
    void dodaj_krawedz(int poczatek, int koniec, int waga);
    void pokoloruj(wierzcholek* w, int kolor);
    void kruskal(wektor<krawedz*>& wynik);
};

void graf::dodaj_wierzcholek()    //dodajemy nowe wierzcholki
{
    wierzcholek* nowy = new wierzcholek;
    nowy->m_index = wierzcholki.size();
    wierzcholki.push_backk(nowy);
}
void graf::dodaj_krawedz(int poczatek, int koniec, int waga) //tworzymy polaczenia miedzy wierzcholkami
{
    wierzcholki[poczatek]->krawedzie.push_backk(new krawedz(wierzcholki[poczatek], wierzcholki[koniec], waga));
    //dodaje do wierzcholka poczatek  nowa krawedz
    wierzcholki[koniec]->krawedzie.push_backk(new krawedz(wierzcholki[koniec], wierzcholki[poczatek], waga));
    // dodajemy do wierzcholka koniec dodajemy nowa krawedz
}
void graf::pokoloruj(wierzcholek* w, int kolor) // koloruje skladowa spojnosci wierzcholka w na podany kolor
{
    int stary_kolor = w->kolor;
    w->kolor = kolor;
    for (node<krawedz*>* aktualny = w->krawedzie.get_first(); aktualny; aktualny = aktualny->get_next())
    {
        krawedz* k = aktualny->get_val();
        if (k->koniec->kolor == stary_kolor)// sprawdzamy czy koniec krawedzi jest w tej samej skladowej spojnosci co wierzcholek w
        {
            pokoloruj(k->koniec, kolor); // rekurencyjnie nadaje kolor koncowi krawedzi
        }
    }
}
void graf::kruskal(wektor<krawedz*>& wynik)
{
    wektor<krawedz*> krawedzie; //delklaracja krawedzi
    for (int i = 0; i < wierzcholki.size(); i++)
    {
        wierzcholek* w = wierzcholki[i];    //przechodzimy forem po wierzcholkach
        w->kolor = i;                      // nadajemy kolor kolejnym wierzcholkom
        for (node<krawedz*>* aktualny = w->krawedzie.get_first(); aktualny; aktualny = aktualny->get_next())
        {
            krawedz* k = aktualny->get_val();
            if (w->m_index < k->koniec->m_index)    //aby uniknac duplikatow bierzemy tylko te krawedzie w kotrych indeks poczatku jest mniejszy niz indeks konca
            {
                krawedzie.push_backk(k);     // dodajemy wektora krawedz k
            }
        }
    }

    //sortowanie krawedzie rosnaco wedlug wag
    bool zamienione = true;
    int n = krawedzie.size();
    while (zamienione)
    {
        zamienione = false;
        for (int i = 1; i < n; i++)
        {
            if (krawedzie[i - 1]->waga > krawedzie[i]->waga)
            {
                zamienione = true;
                std::swap(krawedzie[i - 1], krawedzie[i]);
            }
        }
        n--;
    }
    //tworzymy minimalne drzewo spinajce
    for (int i = 0; i < krawedzie.size() and wynik.size() + 1 < wierzcholki.size(); i++)
    {
        krawedz* k = krawedzie[i];
        if (k->poczatek->kolor != k->koniec->kolor) // sprawdzamy czy nie utworzymy cyklu
        {
            pokoloruj(k->koniec, k->poczatek->kolor);
            wynik.push_backk(k);
        }
    }
}
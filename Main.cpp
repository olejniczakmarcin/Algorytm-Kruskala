#include <iostream>
#include "Graph.h"

int main()
{
    graf g;
    g.dodaj_wierzcholek();
    g.dodaj_wierzcholek();
    g.dodaj_wierzcholek();
    g.dodaj_wierzcholek();
    g.dodaj_wierzcholek();
    g.dodaj_krawedz(0, 1, 3);
    g.dodaj_krawedz(0, 4, 1);
    g.dodaj_krawedz(1, 2, 5);
    g.dodaj_krawedz(1, 4, 4);
    g.dodaj_krawedz(2, 3, 2);
    g.dodaj_krawedz(2, 4, 6);
    g.dodaj_krawedz(3, 4, 7);
    wektor<krawedz*> wynik;
    g.kruskal(wynik);
    for (int i = 0; i < wynik.size(); i++)
    {
        krawedz* k = wynik[i];
        std::cout << k->get_poczatek()->get_index() << " " << k->get_koniec()->get_index() << std::endl;
    }
    return 0;
}
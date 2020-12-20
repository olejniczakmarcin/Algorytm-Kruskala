#pragma once
#include "Node.h"

template<class T>
class lista
{
public:
    node<T>* first;
    node<T>* last;
    int siz; //rozmiar listy
    node<T>* get_first();
    lista();
    void push_backk(const T& v);
    int size();
    void usun(node<T>* n);
};

template<class T> node<T>* lista<T>::get_first()
{
    return first;
}
template<class T> lista<T>::lista() : first(nullptr), last(nullptr), siz(0) {}
template<class T> void lista<T>::push_backk(const T& v)   //metoda dodajaca nowe wezly
{
    node<T>* nowy_wezel = new node<T>(v);
    if (siz == 0)
    {
        first = nowy_wezel;
        last = nowy_wezel;
    }
    else
    {
        nowy_wezel->privius = last;
        last->next = nowy_wezel;
        last = nowy_wezel;
    }
    siz++;
}
template<class T> int lista<T>::size()  //metoda zwracajaca rozmiar listy
{
    return siz;
}
template<class T> void lista<T>::usun(node<T>* n)    //metoda usuwajaca z argumentem podanym jako wezel
{
    if (n->privius)
        n->privius->next = n->next; //nastepnikiem poprzedniego jest nastepnik usuwanego
    else
        first = n->next;  //usuwamy jest 1 wezlem to to jego nastepnik jest 1
    if (n->next)
        n->next->privius = n->privius;   //poprzednikiem nastapnego jest poprzednik usuwanego
    else
        last = n->privius; // usuwany jest ostanim wiece poprzednik jest ostanim
    siz--; //zmniejszamy rozmiar listy
    delete n;   //usuwamy dany wezel
    n = nullptr;
}
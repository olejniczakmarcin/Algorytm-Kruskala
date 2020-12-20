#pragma once
template<class T>
class wektor
{
public:
    T* tablica;  //tablica dowolnego typu
    int siz; //rozmiar wektora
    wektor();
    void push_backk(const T& v);
    T& operator[](int index);
    int size();
};

template<class T> wektor<T>::wektor() :tablica(nullptr), siz(0) {}
template<class T> void wektor<T>::push_backk(const T& v) // metoda dodajaca na koniec wektora
{
    T* nowa_tablica = new T[siz + 1]; //o jeden wiecej element
    if (tablica)
    {
        for (int i = 0; i < siz; i++)
            nowa_tablica[i] = tablica[i];
        delete[] tablica;
        tablica = nullptr;
    }
    nowa_tablica[siz] = v;
    tablica = nowa_tablica;
    siz++;
}
template<class T> T& wektor<T>::operator[](int index)    //przeciazony operator [ ] dla klasy wektor potrzebny do odwolywania sie do obiektu o indexie
{
    return tablica[index];
}
template<class T> int wektor<T>::size()  //metoda zwracajaca rozmiar
{
    return siz;
}
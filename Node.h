#pragma once
template<class T> class lista;
template<class T>
class node
{
public:
    node<T>* next;
    node<T>* privius;
    T val;
    node<T>* get_next();
    T& get_val();
    node(const T& v);
    friend class lista<T>;
};

template<class T> node<T>* node<T>::get_next()  //metoda dostepu do next zwracajaca go
{
    return next;
}
template<class T> T& node<T>::get_val()    //metoda zwracajaca wartosc dowolnego typu
{
    return val;
}
template<class T> node<T>::node(const T& v) : val(v), next(nullptr), privius(nullptr) {}
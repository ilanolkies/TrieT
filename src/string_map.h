#ifndef STRING_MAP_H_
#define STRING_MAP_H_

#include <string>

using namespace std;

template<typename T>
class string_map {
public:
    string_map();
    string_map(const string_map<T>& aCopiar);
    string_map& operator=(const string_map& d);
    ~string_map();
    T &operator[](const string &key);
    int count(const string &key) const;
    const T& at(const string& key) const;
    T& at(const string& key);
    void erase(const string& key);
    int size() const;
    bool empty() const;

private:
    struct Nodo {
        Nodo** siguientes;
        T* definicion;

        Nodo(){
            siguientes = new Nodo*[256];
            definicion = nullptr;
        }
    };

    Nodo* raiz;
    int _size;

    Nodo* copiar(Nodo* valor);
    void limpiar(Nodo* nodo);
};

#include "string_map.hpp"

#endif // STRING_MAP_H_

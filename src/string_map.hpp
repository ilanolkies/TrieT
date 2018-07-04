template <typename T>
string_map<T>::string_map(){
    _size = 0;
    raiz = new Nodo;
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    limpiar(raiz);
    raiz = copiar(d.raiz);
    _size = d.size();
    return *this;
}

template <typename T>
typename string_map<T>::Nodo* string_map<T>::copiar(string_map<T>::Nodo *valor) {
    if(!valor)
        return NULL;

    Nodo *nodo = new Nodo();
    if(valor->definicion)
         nodo->definicion = new T(*valor->definicion);

    for (int i = 0; i < 256; ++i)
        nodo->siguientes[i] = copiar(valor->siguientes[i]);

    return nodo;
}

template <typename T>
void string_map<T>::limpiar(string_map<T>::Nodo *nodo) {
    if(!nodo) return;
    for (int i = 0; i < 256; ++i) {
        limpiar(nodo->siguientes[i]);
    }
    delete nodo->definicion;
    delete nodo->siguientes;
    delete nodo;
}

template <typename T>
string_map<T>::~string_map(){
    limpiar(raiz);
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    Nodo* nodo = raiz;
    for (int i = 0; i < clave.size(); ++i) {
        if(!nodo->siguientes[clave[i]])
            nodo->siguientes[clave[i]] = new Nodo;
        nodo = nodo->siguientes[clave[i]];
    }
    if(!nodo->definicion) {
        nodo->definicion = new T;
        _size++;
    }
    return *nodo->definicion;
}

template <typename T>
int string_map<T>::count(const string& clave) const{
    Nodo* nodo = raiz;
    for (int i = 0; i < clave.size(); ++i) {
        if(!nodo->siguientes[clave[i]])
            return 0;
        nodo = nodo->siguientes[clave[i]];
    }
    return nodo->definicion != nullptr ? 1 : 0;
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    // COMPLETAR
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    // COMPLETAR
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    Nodo* nodo = raiz;
    for (int i = 0; i < clave.size(); ++i) {
        if(!nodo->siguientes[clave[i]])
            return;
        nodo = nodo->siguientes[clave[i]];
    }
    delete nodo->definicion;
    nodo->definicion = nullptr;
}

template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    return raiz == nullptr;
}
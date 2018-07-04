template <typename T>
string_map<T>::string_map(){
    _size = 0;
    raiz = new Nodo;
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    // COMPLETAR
}

template <typename T>
string_map<T>::~string_map(){
    // COMPLETAR
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
        if(nodo == nullptr)
            return 0;
        nodo->siguientes[clave[i]];
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
    // COMPLETAR
}

template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    return raiz == nullptr;
}
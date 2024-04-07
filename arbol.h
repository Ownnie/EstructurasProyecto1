#ifndef ARBOL_H
#define ARBOL_H

#include <string>
#include "nodo.h"

class Arbol
{
private:
    Nodo *raiz;

public:
    Arbol();
    ~Arbol();

    Nodo *getRaiz() const;
    void setRaiz(Nodo *nuevaRaiz);

    void insertarPalabra(const std::string &palabra);
    void inicializarDiccionario(const std::string &nombreArchivo);
    int calcularPuntaje(const std::string &palabra) const;

private:
    Nodo *encontrarNodoPrefijo(const std::string &palabra) const;
};

#endif // ARBOL_H

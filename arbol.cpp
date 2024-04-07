// arbol.cpp
#include "arbol.h"
#include "nodo.h"
#include <fstream>
#include <iostream>

Arbol::Arbol() : raiz(new Nodo('\0')) {}

Arbol::~Arbol()
{
    delete raiz;
}

Nodo *Arbol::getRaiz() const
{
    return raiz;
}

void Arbol::setRaiz(Nodo *nuevaRaiz)
{
    raiz = nuevaRaiz;
}

void Arbol::insertarPalabra(const std::string &palabra)
{
    Nodo *nodoPrefijo = encontrarNodoPrefijo(palabra);
    Nodo *nodoActual = nodoPrefijo;
    size_t i = (nodoPrefijo == nullptr) ? 0 : nodoPrefijo->getLetra() + 1;

    while (i < palabra.size())
    {
        Nodo *nuevoNodo = new Nodo(palabra[i]);
        nodoActual->agregarHijo(nuevoNodo);
        nodoActual = nuevoNodo;
        i++;
    }

    nodoActual->setPalabra(true);
}

void Arbol::inicializarDiccionario(const std::string &nombreArchivo)
{
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open())
    {
        std::cout << "Error: no se pudo abrir el archivo " << nombreArchivo << std::endl;
        return;
    }

    std::string palabra;
    while (archivo >> palabra)
    {
        insertarPalabra(palabra);
    }

    std::cout << "Diccionario inicializado correctamente." << std::endl;
}

int Arbol::calcularPuntaje(const std::string &palabra) const
{
    int puntaje = 0;
    for (char letra : palabra)
    {
        switch (letra)
        {
        case 'E':
        case 'A':
        case 'I':
        case 'O':
        case 'N':
        case 'R':
        case 'T':
        case 'L':
        case 'S':
        case 'U':
            puntaje += 1;
            break;
        case 'D':
        case 'G':
            puntaje += 2;
            break;
        case 'B':
        case 'C':
        case 'M':
        case 'P':
            puntaje += 3;
            break;
        case 'F':
        case 'H':
        case 'V':
        case 'W':
        case 'Y':
            puntaje += 4;
            break;
        case 'K':
            puntaje += 5;
            break;
        case 'J':
        case 'X':
            puntaje += 8;
            break;
        case 'Q':
        case 'Z':
            puntaje += 10;
            break;
        default:
            // Letra inválida
            break;
        }
    }
    return puntaje;
}

Nodo *Arbol::encontrarNodoPrefijo(const std::string &palabra) const
{
    Nodo *nodoActual = raiz;
    size_t i = 0;

    while (i < palabra.size() && nodoActual->getHijo(palabra[i]))
    {
        nodoActual = nodoActual->getHijo(palabra[i]);
        i++;
    }

    return nodoActual;
}

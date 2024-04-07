#include "nodo.h"

Nodo::Nodo(char c) : letra(c), esPalabra(false), numHijos(0) {}

Nodo::~Nodo()
{
    for (Nodo *hijo : hijos)
    {
        delete hijo;
    }
}

char Nodo::getLetra() const
{
    return letra;
}

bool Nodo::esNodoPalabra() const
{
    return esPalabra;
}

int Nodo::getNumHijos() const
{
    return numHijos;
}

Nodo *Nodo::getHijo(char c) const
{
    for (Nodo *hijo : hijos)
    {
        if (hijo->getLetra() == c)
        {
            return hijo;
        }
    }
    return nullptr;
}

void Nodo::setPalabra(bool valor)
{
    esPalabra = valor;
}

void Nodo::agregarHijo(Nodo *hijo)
{
    hijos.push_back(hijo);
    numHijos++;
}

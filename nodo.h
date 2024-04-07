#ifndef NODO_H
#define NODO_H

#include <vector>

class Nodo
{
private:
    char letra;
    bool esPalabra;
    int numHijos;
    std::vector<Nodo *> hijos;

public:
    Nodo(char c);
    ~Nodo();

    char getLetra() const;
    bool esNodoPalabra() const;
    int getNumHijos() const;
    Nodo *getHijo(char c) const;

    void setPalabra(bool valor);
    void agregarHijo(Nodo *hijo);
};

#endif // NODO_H

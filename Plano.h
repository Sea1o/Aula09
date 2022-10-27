#ifndef PLANO_H
#define PLANO_H

#include "Catalogo.h"
#include "Filme.h"

class Plano {
private:
    int quantidadeMaxima;
    Catalogo** catalogos;
    int quantidade;
public:
    Plano(int quantidadeMaxima);
    ~Plano();

    int getQuantidadeMaxima() const;
    Catalogo** getCatalogos() const;
    int getQuantidadeDeCatalogos() const;
    void adicionar(Catalogo* c);

    Filme* getDestaque();
};


#endif // PLANO_H

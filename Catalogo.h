#ifndef CATALOGO_H
#define CATALOGO_H

#include <string>

#include "Filme.h"

class Catalogo {
  private:
    Filme** filmes;
    int quantidadeMaxima;
    int quantidade;

  public:
    Catalogo(int quantidadeMaxima);
    ~Catalogo();

    Filme** getFilmes() const;
    int getQuantidadeFilmes() const;
    int getQuantidadeMaximaFilmes() const;
    Filme* getFilmeMaisVisto();

    bool adicionar(Filme* filme);

};

#endif  // CATALOGO_H

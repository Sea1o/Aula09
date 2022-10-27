#ifndef FILME_H
#define FILME_H

#include <string>
#include <stdexcept>

using namespace std;

class Filme {
  private:
    string nome;
    int duracao;
    int visualizacoes;
  public:
    Filme(string nome, int duracao);
    ~Filme();

    string getNome() const;
    int getDuracao() const;
    int getVisualizacoes() const;
    void assistir(int tempo);

    void imprimir() const;
};

#endif  // FILME_H

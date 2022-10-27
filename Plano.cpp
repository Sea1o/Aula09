#include "Plano.h"
#include "Catalogo.h"
#include "SemVisualizacoes.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Plano::Plano(int quantidadeMaxima) : quantidadeMaxima(quantidadeMaxima), quantidade(0){
    catalogos = new Catalogo*[quantidadeMaxima];
}

Plano::~Plano(){
    delete[] catalogos;
}

int Plano::getQuantidadeMaxima() const {
    return this->quantidadeMaxima;
}

Catalogo** Plano::getCatalogos() const {
    return this->catalogos;
}

int Plano::getQuantidadeDeCatalogos() const {
    return this->quantidade;
}

void Plano::adicionar(Catalogo* c) {
    if (quantidade >= quantidadeMaxima)
        throw new overflow_error("catalogos estourou");
    if (c == NULL)
        throw new invalid_argument("nulo");

    for(int i = 0; i < quantidade; i++){
        if(c == catalogos[i])
            throw new invalid_argument("catalogo ja adicionado");
    }

    catalogos[quantidade++] = c;
}

Filme* Plano::getDestaque(){
    /*Implemente o metodo*/
    int catalogosVazios=0, semVisu=0, i=0;
    Filme* destaque = NULL;
    if(quantidade==0){
            return NULL;
    }
    // for(int i=0;i<quantidade;i++){
    //     if(catalogos[i]->getQuantidadeFilmes()==0){
    //         catalogosVazios++;
    //     }
    // }
    // if(catalogosVazios==quantidade){
    //     return NULL;
    // }

    while(i < this->quantidade){
        try{
            destaque = catalogos[i]->getFilmeMaisVisto();
            break;
        }
        catch(SemVisualizacoes *e){
            delete e;
        }
        i++;
    }

    if(i==quantidade){
        return NULL;
    }

    for(int j=i+1;i<quantidade;i++){
        try{   
            
            if(catalogos[i]->getFilmeMaisVisto()->getVisualizacoes() > destaque->getVisualizacoes()){
                destaque = catalogos[i]->getFilmeMaisVisto();
            }
        }  
        catch(SemVisualizacoes *e){
            semVisu++;
            cout << "Ta com erro" << endl;
            delete e;
        }
    }

    return destaque;
}

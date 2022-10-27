//Faca os includes necessarios
#include "Filme.h"
#include "Catalogo.h"
#include "SemVisualizacoes.h"
#include "Plano.h"
#include <iostream>
using namespace std;

void teste1(){
    /*Implemente conforme o enunciado*/
    try{
        Filme *f1 = new Filme("Filme1",-1);
    }
    catch(invalid_argument *e){
        cout << "Erro: " << e->what() << endl;
        delete e;

    }

    Filme *f2 = new Filme("Matrix",136);

    try{
        f2->assistir(-1);
    }
    catch(invalid_argument *e){
        cout << "Erro: " << e->what() << endl;
        delete e;

    }

    try{
        f2->assistir(137);
    }
    catch(invalid_argument *e){
        cout << "Erro: " << e->what() << endl;
        delete e;

    }

}


void teste2(){
    /*Implemente conforme o enunciado*/
    Filme *f1 = new Filme("Matrix",136);
    Filme *f2 = new Filme("Smurfs",100);
    Catalogo *c1 = new Catalogo(2);
    c1->adicionar(f1);
    c1->adicionar(f2);

    try{
        c1->getFilmeMaisVisto();
    }
    catch(SemVisualizacoes *e){
        cout << "Erro: " << e->what() << endl;
        delete e;
    }
}

void teste3(){
    /*Implemente conforme o enunciado*/
    Plano *p1 = new Plano(2);
    Catalogo *c1 = new Catalogo(2);
    Catalogo *c2 = new Catalogo(2);
    p1->adicionar(c1);
    p1->adicionar(c2);
    Filme *f1 = new Filme("Matrix",136);
    Filme *f2 = new Filme("Smurfs",100);
    Filme *f3 = new Filme("O Regresso",156);
    Filme *f4 = new Filme("Duna",160);
    c1->adicionar(f1);
    c1->adicionar(f2);
    c2->adicionar(f3);
    c2->adicionar(f4);
    p1->getDestaque();
    f1->assistir(136);
    f1->assistir(136);
    f1->assistir(136);
    f2->assistir(99);
    f3->assistir(156);
    f3->assistir(156);
    p1->getDestaque();
    p1->getDestaque()->imprimir();

}

int main(){
    teste3(); //Substitua pelo teste que deseja efetuar
    return 0;
}

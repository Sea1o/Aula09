#ifndef SEMVISUALIZACOES_H
#define SEMVISUALIZACOES_H

#include <stdexcept>
#include <string>

using namespace std;

class SemVisualizacoes : public logic_error {
    public:
        SemVisualizacoes(string mensagem);
        ~SemVisualizacoes();
};

#endif // SEMVISUALIZACOES_H
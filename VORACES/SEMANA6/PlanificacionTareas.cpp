#include<iostream>
#include<algorithm>
#include<array>
#include<vector>
using namespace std;

struct Tarea
{
    int pos;
    int b;
    int d;
};

bool ordenarPorB(const Tarea & A, const Tarea & B) {
    return A.b > B.b;
}

template<size_t Size>
void inicializacion(array<Tarea, Size> & tareas, array<Tarea, Size> & candidatos) {
    
    // ordena las tareas con respecto a su beneficio (b), de mayor a menor
    sort(tareas.begin(), tareas.end(), ordenarPorB);
    
    // en principio los candidatos son todas las tareas
    int i = 0;
    for (const auto& tarea : tareas) {
        candidatos[i++] = tarea;
    }
    

}

// esta funcion indica si el candidato de dicha posicion puede o no ser tomado
bool puedeSerSeleccionado(int pos, vector<int> & candidatosTomados) {
    for(int position : candidatosTomados) {
        if(pos == position) return false; // si ya se encuentra en tomados entonces no podemos seleccionarlo
    }
    return true;
}

template<size_t Size>
Tarea * buscarFactible(int i, array<Tarea, Size> & candidatos, vector<int> & candidatosTomados, bool comp = true) {
    // busca entre los candidatos uno que tenga el tiempo correspondiente a i
    // como esta ordenado por beneficio me dará el de mejor beneficio siempre

    for(Tarea & cand : candidatos) {
        if(!comp) {
            if(cand.d == i && // con esta busqueda se trae los de menor tiempo de ejecucion
                puedeSerSeleccionado(cand.pos, candidatosTomados)
            ) {
                candidatosTomados.push_back(cand.pos); // a esta nuevo candidato es tomado y nunca más lo podemos tomar en cuenta de nuevo
                return &cand; 
            }
        } else {
            if(  cand.d >= i && // con esta busqueda se trae ya para completar, con el mejor beneficio
                puedeSerSeleccionado(cand.pos, candidatosTomados)
            ) {
                candidatosTomados.push_back(cand.pos); // a esta nuevo candidato es tomado y nunca más lo podemos tomar en cuenta de nuevo
                return &cand; 
            }
        }
    }

    return nullptr;
}

// factible
template<size_t Size>
void algoritmo(vector<Tarea> & resultado, array<Tarea, Size> & candidatos, int n) {
    int i = 1;
    bool band = true;
    vector<int> candidatosTomados;


    while (i <= n)
    {
        Tarea * posibleCandidato = buscarFactible(i, candidatos, candidatosTomados, false);
        if(posibleCandidato) { // solo si encuentra, lo agrega al resultado
            if(resultado.size() == 0) // si es el primer elemento a agregar
                resultado.push_back(*posibleCandidato);
            else if(resultado.rbegin()->d <= posibleCandidato->d) // se tiene que seguir un orden progresivo 
                resultado.push_back(*posibleCandidato);
        } 
        i++;
    }

    // si el total de resultados todavia no llega al completar lo que se amerita
    // buscamos el de mejor beneficio, ahora con el parametro d > i
    i = 1;
    if(resultado.size() < resultado.rbegin()->d) {
        while (i <= n)
        {
            if(resultado.size() == resultado.rbegin()->d) break;
            Tarea * posibleCandidato = buscarFactible(i, candidatos, candidatosTomados, true);
            if(posibleCandidato) { // solo si encuentra, lo agrega al resultado
                if(resultado.size() == 0) // si es el primer elemento a agregar
                    resultado.push_back(*posibleCandidato);
                else if(resultado.rbegin()->d <= posibleCandidato->d) // se tiene que seguir un orden progresivo 
                    resultado.push_back(*posibleCandidato);
            } 
            i++;
        }
    }
    
}

int main() {

    const size_t n = 6;
    array<Tarea, n> candidatos;

    // primer ejemplo
    /*
    array<Tarea, n> tareas = {
        Tarea{1, 100, 2},
        Tarea{2, 10, 1},
        Tarea{3, 15, 2},
        Tarea{4, 27, 1}
    };
    */
    
    // segundo ejemplo
    array<Tarea, n> tareas = {
        Tarea{1, 20, 3},
        Tarea{2, 15, 1},
        Tarea{3, 10, 1},
        Tarea{4, 7, 3},
        Tarea{5, 5, 1},
        Tarea{6, 3, 3}
    };
    
    vector<Tarea> resultado; // no sabemos cuanto medirá en si asi que definimos un vector dinamico

    inicializacion(tareas, candidatos);
    algoritmo(resultado, candidatos, n);

    for(Tarea & t : resultado) {
        std::cout<<"pos = "<<t.pos<<" b = "<<t.b<<" d = "<<t.d<<endl;
    }

    return 0;
}
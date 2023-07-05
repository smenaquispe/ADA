#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Tarea
{
    int i;
    int g;
    int d;
};

bool compareBeneficio(Tarea & a, Tarea & b) {
    return a.g > b.g;
}

void buscarTarea(vector<Tarea> & tareas, int t, vector<Tarea> & seleccionados) {
    for(auto & tarea : tareas) {
        // si se encuentra dentro del plazo de tiempo
        if(tarea.d == t) {
            bool band = true;
            for(auto & selec : seleccionados) {
                // que la tareas ya fue seleccionada y realizada
                if(selec.i == tarea.i) {
                    band = false;
                    break;
                }
            }

            // se puede seleccionar
            if(band) {
                seleccionados.push_back(tarea);
                break;
            }
        }
    }
}

// necesito conseguir el del mayor beneficio en el instante t
void completarTareas(vector<Tarea> & tareas) {
    vector<Tarea> seleccionados;
    
    // entonces primero ordenare en mayor a menor beneficio
    sort(tareas.begin(), tareas.end(), compareBeneficio);

    // ahora hallamos por instancia
    for(int t = 0; t < tareas.size(); t++) {
        buscarTarea(tareas, t, seleccionados);
    }

    for(auto & t: seleccionados) {
        cout<<"i: "<<t.i<<" gi: "<<t.g<<" di: "<<t.d<<endl;
    }
}


int main() {

    vector<Tarea> tareas = {
        {1,50,2},
        {2,10,1},
        {3,15,2},
        {4,30,1}
    };

    completarTareas(tareas);

    return 0;
}
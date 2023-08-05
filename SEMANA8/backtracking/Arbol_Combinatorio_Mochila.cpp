#include <iostream>
#include <vector>

using namespace std;

struct Objeto {
    int p;
    int b;
};

vector<Objeto> objetos = {
    {2, 1},
    {3, 2},
    {4, 3},
    {5, 4}
};
int pact = 0;
int bact = 0;

int M = 7; // capacidad de la mochila

void generar(int nivel, vector<int>& s) {
    s[nivel] = 1; // Prueba seleccionando el objeto en la mochila
    pact += objetos[nivel].p;
    bact += objetos[nivel].b;

    // Imprimir información del nivel actual
    cout << "Nivel " << nivel << ": Seleccionando objeto " << nivel << " - Peso actual: " << pact << ", Valor actual: " << bact << endl;
}

void retroceder(int nivel, vector<int>& s) {
    s[nivel] = 0; // Retrocede, el objeto no está en la mochila
    pact -= objetos[nivel].p;
    bact -= objetos[nivel].b;

    // Imprimir información del nivel actual
    cout << "Nivel " << nivel << ": Deseleccionando objeto " << nivel << " - Peso actual: " << pact << ", Valor actual: " << bact << endl;
}

bool solucion(int nivel) {
    return nivel == objetos.size(); // Si hemos alcanzado el último nivel del árbol
}

bool criterio(int nivel) {
    return pact <= M; // Si la suma de los pesos todavía está dentro de la capacidad
}

void backtracking(int nivel, vector<int>& s, int& voa, vector<int>& soa) {
    if (solucion(nivel)) {
        if (bact > voa) {
            voa = bact;
            soa = s;
        }
        return;
    }

    generar(nivel, s);
    if (criterio(nivel)) {
        backtracking(nivel + 1, s, voa, soa);
    }

    retroceder(nivel, s);
    backtracking(nivel + 1, s, voa, soa);
}

int main() {
    vector<int> s(objetos.size(), 0);
    int voa = -10000;
    vector<int> soa;

    backtracking(0, s, voa, soa);

    cout << "Valor maximo en la mochila: " << voa << endl;
    cout << "Objetos seleccionados: ";
    for (int i = 0; i < soa.size(); ++i) {
        if (soa[i] == 1) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}

#include <iostream>

using namespace std;

const int MAX_VERTICES = 100;
const int MAX_CARAS = 100;

struct Vertice {
    float x, y, z;
};

struct Cara {
    int indices[10]; // Máximo 10 vértices por cara
    int cantidad;
};

int main() {
    Vertice vertices[MAX_VERTICES];
    Cara caras[MAX_CARAS];
    int numVertices = 0, numCaras = 0;
    int opcion;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Registrar Vértices\n";
        cout << "2. Registrar Caras\n";
        cout << "3. Imprimir la Figura\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: { // Registrar vértices
                if (numVertices >= MAX_VERTICES) {
                    cout << "Límite de vértices alcanzado.\n";
                    break;
                }
                cout << "Ingrese los vértices (X Y Z), separados por espacios. Ingrese -1 para finalizar.\n";
                while (numVertices < MAX_VERTICES) {
                    float x, y, z;
                    cout << "> ";
                    cin >> x;
                    if (x == -1) break; // Verifica si el usuario quiere salir antes de leer y y z
                    cin >> y >> z;
                    vertices[numVertices++] = {x, y, z};
                }
                break;
            }

            case 2: { // Registrar caras
                if (numCaras >= MAX_CARAS) {
                    cout << "Límite de caras alcanzado.\n";
                    break;
                }
                if (numVertices == 0) {
                    cout << "Debe registrar vértices antes de agregar caras.\n";
                    break;
                }

                cout << "Ingrese los índices de los vértices para cada cara (máximo 10 por cara). Ingrese -1 para finalizar.\n";
                while (numCaras < MAX_CARAS) {
                    int count = 0;
                    int indice;
                    cout << "> ";
                    while (count < 10) {
                        cin >> indice;
                        if (indice == -1) break; // Si encuentra -1, detiene la lectura
                        if (indice >= numVertices || indice < 0) {
                            cout << "Error: Índice fuera de rango.\n";
                            continue;
                        }
                        caras[numCaras].indices[count++] = indice;
                    }

                    if (count == 0) break; // Si no se ingresaron índices válidos, salir
                    caras[numCaras].cantidad = count;
                    numCaras++;
                }
                break;
            }

            case 3: { // Imprimir la figura
                if (numVertices == 0) {
                    cout << "No hay vértices registrados.\n";
                } else {
                    cout << "\nEstructura de Vértices:\n";
                    for (int i = 0; i < numVertices; i++) {
                        cout << "V" << i << ": (" << vertices[i].x << ", " << vertices[i].y << ", " << vertices[i].z << ")\n";
                    }
                }

                if (numCaras == 0) {
                    cout << "No hay caras registradas.\n";
                } else {
                    cout << "\nEstructura de Caras:\n";
                    for (int i = 0; i < numCaras; i++) {
                        cout << "F" << i << ": ";
                        for (int j = 0; j < caras[i].cantidad; j++) {
                            cout << caras[i].indices[j] << " ";
                        }
                        cout << endl;
                    }
                }
                break;
            }

            case 4:
                cout << "Saliendo del programa.\n";
                break;

            default:
                cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 4);

    return 0;
}
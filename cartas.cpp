#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Declaración de matrices y vectores
    vector<vector<string>> matriz = {
        {"1","1","2","2"},
        {"3","3","4","4"},
        {"5","5","6","6"},
        {"7","7","8","8"}
    };
    vector<vector<string>> ciego(4, vector<string>(4, "-"));

    string guardar, guardar1;
    int numero, numero2, contador = 0;

    // Ciclo del juego
    while (contador < 8) {
        // Mostrar la matriz actual
        for (const auto& fila : ciego) {
            for (const auto& elem : fila)
                cout << elem << " ";
            cout << endl;
        }

        cout << "\nIngrese el número de la imagen (1-16): ";
        cin >> numero;
        cout << "Ingrese otro número de la imagen (1-16): ";
        cin >> numero2;

        // Validación de entrada
        while (numero < 1 || numero > 16 || numero2 < 1 || numero2 > 16 || numero == numero2) {
            cout << "Entrada inválida. Ingrese dos números diferentes entre 1 y 16:\n";
            cin >> numero >> numero2;
        }

        // Convertir número 1-16 a coordenadas
        int fila1 = (numero - 1) / 4, col1 = (numero - 1) % 4;
        int fila2 = (numero2 - 1) / 4, col2 = (numero2 - 1) % 4;

        // Mostrar los números seleccionados
        guardar = matriz[fila1][col1];
        guardar1 = matriz[fila2][col2];
        ciego[fila1][col1] = guardar;
        ciego[fila2][col2] = guardar1;

        // Mostrar matriz con los valores visibles temporalmente
        for (const auto& fila : ciego) {
            for (const auto& elem : fila)
                cout << elem << " ";
            cout << endl;
        }

        // Evaluar si son iguales
        if (guardar == guardar1) {
            contador++;
        } else {
            cout << "¡No coinciden!\n";
            ciego[fila1][col1] = "-";
            ciego[fila2][col2] = "-";
        }

        cout << endl;
    }
}

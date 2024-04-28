#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

// Função para encontrar o índice da matriz com a melhor precisão e acurácia combinadas
tuple<int, double, double> best_performance(const vector<vector<int>>& matrices) {
    int best_index = 0;
    double best_accuracy = 0.0;
    double best_precision = 0.0;

    // Loop através de cada matriz para calcular as métricas
    for (int i = 0; i < matrices.size(); ++i) {
        // Definir tp, fp, fn e tn
        int tp = matrices[i][0];
        int fp = matrices[i][1];
        int fn = matrices[i][2];
        int tn = matrices[i][3];

        // Calcular acurácia e precisão
        double accuracy = (double)(tp + tn) / (tp + fp + fn + tn);
        double precision = (double)tp / (tp + fp);

        // Atualizar as melhores métricas se encontradas
        if (accuracy > best_accuracy && precision > best_precision) {
            best_index = i + 1;
            best_accuracy = accuracy;
            best_precision = precision;
        }
    }

    return make_tuple(best_index, best_accuracy, best_precision);
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // Limpar o buffer

    vector<vector<int>> matrices;

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> matrix;
        string value;

        while (getline(ss, value, ',')) {
            matrix.push_back(stoi(value));
        }

        matrices.push_back(matrix);
    }

    // Calcular métricas de precisão e acurácia
    auto [index, accuracy, precision] = best_performance(matrices);

    // Imprimir os resultados
    cout << "Índice: " << index << endl;
    cout << "Acurácia: " << accuracy << endl;
    cout << "Precisão: " << precision << endl;

    return 0;
}

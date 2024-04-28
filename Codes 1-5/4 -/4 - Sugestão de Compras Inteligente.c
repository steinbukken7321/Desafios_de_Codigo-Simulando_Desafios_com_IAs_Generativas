#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Função para sugerir cogumelos com preços mais baixos com base em um cogumelo desejado.
void sugerir_cogumelos(const string &cogumelo_desejado) {
    // Definição do catálogo de cogumelos e preços
    unordered_map<string, int> catalogo = {
        {"Shitake", 10},
        {"Portobello", 8},
        {"Shimeji", 6},
        {"Champignon", 12},
        {"Funghi", 16},
        {"Porcini", 12}
    };

    // Verifica se o cogumelo desejado está no catálogo
    if (catalogo.find(cogumelo_desejado) != catalogo.end()) {
        int valor_desejado = catalogo[cogumelo_desejado];
        vector<pair<string, int>> sugestoes;

        // Procura por cogumelos mais baratos no catálogo
        for (const auto &cogumelo : catalogo) {
            if (cogumelo.second <= valor_desejado && cogumelo.first != cogumelo_desejado) {
                sugestoes.push_back(cogumelo);
                if (sugestoes.size() == 2) {
                    break;
                }
            }
        }

        if (sugestoes.empty()) {
            // Se não houver sugestões, exibe a mensagem indicada
            cout << "Desculpe, não há sugestões disponíveis." << endl;
        } else {
            // Exibe as sugestões de cogumelos com preços mais baixos
            for (const auto &sugestao : sugestoes) {
                cout << sugestao.first << " - Valor: " << sugestao.second << endl;
            }
        }
    } else {
        // Se o cogumelo desejado não estiver no catálogo, exibe uma mensagem de erro
        cout << "Cogumelo não encontrado no catálogo." << endl;
    }
}

int main() {
    // Entrada do usuário
    string cogumelo_desejado;
    getline(cin, cogumelo_desejado);

    // Chamada da função para sugerir cogumelos
    sugerir_cogumelos(cogumelo_desejado);

    return 0;
}

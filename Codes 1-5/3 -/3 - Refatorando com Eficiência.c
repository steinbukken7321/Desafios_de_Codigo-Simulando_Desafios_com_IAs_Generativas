#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>

using namespace std;

// Função para identificar funções em unidades coesas e com responsabilidades únicas.
string identificar_funcoes(const string &texto) {
    return "Separe funções em unidades coesas e com responsabilidades únicas.";
}

// Função para validar e normalizar as entradas para evitar inconsistências.
string entrada_de_dados(const string &texto) {
    return "Valide e normalize as entradas para evitar inconsistências.";
}

// Função para usar nomes descritivos para variáveis e funções.
string nomenclatura_significativa(const string &texto) {
    return "Use nomes descritivos para variáveis e funções.";
}

// Função para processar a entrada e chamar a função correspondente.
string processar_entrada(const string &texto) {
    // Dicionário mapeando textos para funções
    unordered_map<string, function<string(const string&)>> opcoes = {
        {"Dica de boas práticas de refatoração de código, nas funções.", identificar_funcoes},
        {"Dica de boas práticas de refatoração de código, nas entrada de dados.", entrada_de_dados},
        {"Dica de boas práticas de refatoração de código, nomenclaturas.", nomenclatura_significativa}
    };

    // Verifica se o texto está presente nas opções
    auto it = opcoes.find(texto);
    if (it != opcoes.end()) {
        // Chama a função correspondente ao texto e retorna o resultado
        return it->second(texto);
    } else {
        // Retorna uma mensagem de opção inválida se o texto não estiver nas opções
        return "Opção inválida.";
    }
}

// Função principal para o desafio
void desafio() {
    // Solicita uma entrada do usuário
    string entrada;
    getline(cin, entrada);

    // Processa a entrada e obtém a saída
    string saida = processar_entrada(entrada);

    // Exibe a saída
    cout << saida << endl;
}

int main() {
    // Chama a função desafio para executar o programa
    desafio();

    return 0;
}

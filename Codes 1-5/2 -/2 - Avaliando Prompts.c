#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Função para avaliar se o prompt está adequado
string avaliar_prompt(const string &prompt) {
    // Armazena palavras-chave relevantes
    vector<string> palavras_chave = {"inteligência artificial", "sistemas de recomendação online", "exemplos de conversação", "explique conceitos", "dicas de tecnologia"};

    // Verifica se pelo menos uma palavra-chave está presente no prompt.
    for (const string &palavra_chave : palavras_chave) {
        if (prompt.find(palavra_chave) != string::npos) {
            return "O prompt está adequado.";
        }
    }

    // Se nenhuma palavra-chave for encontrada, o prompt não está adequado.
    return "O prompt não está adequado. Inclua palavras-chave relevantes.";
}

int main() {
    // Entrada do usuário
    string prompt_usuario;
    getline(cin, prompt_usuario);

    // Avaliar o prompt do usuário
    string feedback_usuario = avaliar_prompt(prompt_usuario);

    // Exibir feedback
    cout << feedback_usuario << endl;

    return 0;
}

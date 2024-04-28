#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <regex>

using namespace std;

// Função que analisa os sentimentos.
string analyze_sentiment() {
    // Entrada do usuário
    string comentario;
    getline(cin, comentario);

    // Divisão do comentário em palavras.
    vector<string> palavras;
    regex palavra_regex("\\b\\w+\\b");
    auto palavra_begin = sregex_iterator(comentario.begin(), comentario.end(), palavra_regex);
    auto palavra_end = sregex_iterator();

    for (sregex_iterator i = palavra_begin; i != palavra_end; ++i) {
        smatch match = *i;
        palavras.push_back(match.str());
    }

    // Lista de palavras positivas, negativas e neutras para classificação.
    vector<string> positivas = {"bom", "boa", "ótimo", "excelente", "maravilhoso", "gostei", "incrível"};
    vector<string> negativas = {"ruim", "péssimo", "horrível", "terrível", "odeio"};
    vector<string> neutras = {"mas", "deixou", "apesar", "embora"};

    // Contagem de palavras positivas, negativas e neutras
    int count_positivo = count_if(palavras.begin(), palavras.end(), [&](const string &palavra) {
        return find(positivas.begin(), positivas.end(), palavra) != positivas.end();
    });

    int count_negativo = count_if(palavras.begin(), palavras.end(), [&](const string &palavra) {
        return find(negativas.begin(), negativas.end(), palavra) != negativas.end();
    });

    int count_neutro = count_if(palavras.begin(), palavras.end(), [&](const string &palavra) {
        return find(neutras.begin(), neutras.end(), palavra) != neutras.end();
    });

    // Verifica se há mais palavras positivas do que negativas no comentário e se não há palavras neutras.
    // Se essa condição for verdadeira, o comentário é considerado positivo.
    if (count_positivo > count_negativo && count_neutro == 0) {
        return "Positivo";
    }

    // Verifica se há mais palavras negativas do que positivas no comentário e se não há palavras neutras.
    // Se essa condição for verdadeira, o comentário é considerado negativo.
    if (count_negativo > count_positivo && count_neutro == 0) {
        return "Negativo";
    }

    // Verifica se há mais palavras neutras do que positivas e negativas.
    // Se essa condição for verdadeira, o comentário é considerado neutro.
    if (count_neutro > count_positivo && count_negativo == 0) {
        return "Neutro";
    }

    return "Indefinido";
}

int main() {
    // Saída esperada
    string sentimento = analyze_sentiment();
    cout << "Sentimento: " << sentimento << endl;

    return 0;
}
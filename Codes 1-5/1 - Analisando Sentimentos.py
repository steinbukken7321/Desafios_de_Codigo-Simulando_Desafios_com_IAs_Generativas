# Importa o módulo re, que é a biblioteca de expressões regulares do Python. 
import re

# Função que analiza os sentimentos.
def analyze_sentiment():
    # Entrada do usuário
    comentario = input()


    # Divisão do comentário em palavras.
    palavras = re.findall(r'\b\w+\b', comentario.lower())
    
    # Lista de palavras positivas, negativas e neutras para classificação.
    positivas = ["bom", "boa", "ótimo", "excelente", "maravilhoso", "gostei", "incrível"]
    negativas = ["ruim", "péssimo", "horrível", "terrível", "odeio"]
    neutras = ["mas", "deixou", "apesar", "embora"]


    # Contagem de palavras positivas, negativas e neutras
    count_positivo = sum(palavra in positivas for palavra in palavras)
    count_negativo = sum(palavra in negativas for palavra in palavras)
    
    # TODO: Conte quantas palavras neutras estão presentes no comentáriopara classificação.  
    count_neutro = sum(palavra in neutras for palavra in palavras)
    
    # Verifica se há mais palavras positivas do que negativas no comentário e se não há palavras neutras.
    # Se essa condição for verdadeira, o comentário é considerado positivo.
    if count_positivo > count_negativo and count_neutro == 0:
        return "Positivo"
    # TODO: Complete a codição para determinar o sentimento com base na contagem de palavras
    
    # Verifica se há mais palavras negativas do que positivas no comentário e se não há palavras neutras. Se essa condição for verdadeira, o comentário é considerado negativo.
    if count_negativo > count_positivo and count_neutro == 0:
        return "Negativo"
        
    # Verifica se há mais palavras neutras do que positivas e negativas. Se essa condição for verdadeira, o comentário é considerado neutro.
    if count_neutro > count_positivo and count_negativo == 0:
        return "Neutro"    


# Saída esperada
sentimento = analyze_sentiment()
print("Sentimento:", sentimento)
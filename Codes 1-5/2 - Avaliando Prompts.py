# Entrada do usuário
prompt_usuario = input()

# Função para avaliar se o prompt está adequado
def avaliar_prompt(prompt):
    # Armazena palavras-chave relevantes
    palavras_chave = ["inteligência artificial", "sistemas de recomendação online", "exemplos de conversação", "explique conceitos", "dicas de tecnologia" ]

    # Verifica se pelo menos uma palavra-chave está presente no prompt.
    for palavra_chave in palavras_chave:
        if palavra_chave in prompt:
            return "O prompt está adequado."

    # Se nenhuma palavra-chave for encontrada, o prompt não está adequado.
    return "O prompt não está adequado. Inclua palavras-chave relevantes."

# Avaliar o prompt do usuário
feedback_usuario = avaliar_prompt(prompt_usuario)

# Exibir feedback
print(feedback_usuario)
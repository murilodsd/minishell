#!/bin/bash

# Função para imprimir o título do teste
function print_test_title() {
    echo -e "\n\033[1;34mTestando: $1\033[0m"
}

# Testando redirecionamentos malformados
print_test_title "Redirecionamentos Malformados"
echo "Testando redirecionamentos malformados"
./minishell <<< "ls >"          # Esperado: syntax error near unexpected token `newline'
./minishell <<< "ls <"          # Esperado: syntax error near unexpected token `newline'
./minishell <<< "ls >>"         # Esperado: syntax error near unexpected token `newline'
./minishell <<< "ls <<"         # Esperado: syntax error near unexpected token `newline'
./minishell <<< ">"             # Esperado: syntax error near unexpected token `newline'
./minishell <<< "<"             # Esperado: syntax error near unexpected token `newline'
./minishell <<< ">>"            # Esperado: syntax error near unexpected token `newline'
./minishell <<< "<<"            # Esperado: syntax error near unexpected token `newline'

# Teste de redirecionamento incorreto com pipes
print_test_title "Redirecionamento Incorreto com Pipes"
./minishell <<< "ls | wc >"     # Esperadado: syntax error near unexpected token `newline'
./minishell <<< "ls | wc <"     # Esperado: syntax error near unexpected token `newline'
./minishell <<< "ls | wc >>"     # Esperado: syntax error near unexpected token `newline'
./minishell <<< "ls | wc <<"     # Esperado: syntax error near unexpected token `newline'
./minishell <<< "ls | >"     # Esperado: syntax error near unexpected token `newline'
./minishell <<< "ls | <"     # Esperado: syntax error near unexpected token `newline'
./minishell <<< "ls | >>"     # Esperado: syntax error near unexpected token `newline'
./minishell <<< "ls | <<"     # Esperado: syntax error near unexpected token `newline'

# Testando redirecionamentos malformados adicionais
print_test_title "Redirecionamentos Malformados Adicionais"
echo "Testando redirecionamentos malformados adicionais '<'"
./minishell <<< "><"            # Esperado: syntax error near unexpected token `<'
./minishell <<< "<<< test"      # Esperado: syntax error near unexpected token `<'
./minishell <<< "ls >    <"        # Esperado: syntax error near unexpected token `<'

print_test_title "Redirecionamentos Malformados Adicionais"
echo "Testando redirecionamentos malformados adicionais '>'"
./minishell <<< ">>> test"      # Esperado: syntax error near unexpected token `>'
./minishell <<< "ls < >"        # Esperado: syntax error near unexpected token `>'
./minishell <<< "ls > >"        # Esperado: syntax error near unexpected token `>'
./minishell <<< "ls < > wc"     # Esperado: syntax error near unexpected token `>'

# Testando comandos e operadores misturados malformados
print_test_title "Comandos e Operadores Misturados Malformados"
echo "Testando comandos e operadores misturados malformados"
./minishell <<< "ls < | wc"    # Esperado: syntax error near unexpected token `|'
./minishell <<< "ls <| wc"    # Esperado: syntax error near unexpected token `|'
./minishell <<< "echo hello > | wc"   # Esperado: syntax error near unexpected token `|'
./minishell <<< "ls >> | wc"    # Esperado: syntax error near unexpected token `|'
./minishell <<< "ls << | wc"    # Esperado: syntax error near unexpected token `|'

# Testando pipes malformados
print_test_title "Pipes Malformados"
echo "Testando pipes malformados"
./minishell <<< "     | echo hello"     # Esperado: syntax error near unexpected token `|'
./minishell <<< "echo hello | |"   # Esperado: syntax error near unexpected token `|'
./minishell <<< "| echo hello"   # Esperado: syntax error near unexpected token `|'
./minishell <<< "echo hello | | grep hi"  # Esperado: syntax error near unexpected token `|'
./minishell <<< "     |"     # Esperado: syntax error near unexpected token `|'
./minishell <<< "echo || wc" # Esperado: syntax error near unexpected token `|'

# Testando comandos vazios
print_test_title "Comandos Vazios"
echo "Testando comandos vazios"
./minishell <<< "     "      # Esperado: comando ignorados

# Testando aspas não fechadas
print_test_title "Aspas Não Fechadas"
echo "Testando aspas não fechadas"
./minishell <<< "\"echo \"hello\""       # Esperado: syntax error near unexpected token `open quote'
./minishell <<< "'echo 'hello world'"  # Esperado: syntax error near unexpected token `open quote'
./minishell <<< "'echo hello world" # Esperado: syntax error near unexpected token `open quote'
./minishell <<< "\"echo hello world"  # Esperado: syntax error near unexpected token `open quote'

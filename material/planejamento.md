# PLANEJAMENTO

## Configuração Inicial (`src/utils/init_data.c`)
Vamos começar criando uma função que vai configurar tudo que o shell precisa para rodar. Isso inclui:
- Variáveis de ambiente que vamos usar durante toda a execução.
- Outras informações necessárias no funcionamento do minishell, como configuração de arquivo de histórico ou outros ajustes globais.

A função vai configurar tudo que a gente vai precisar nas etapas seguintes, deixando o código bem organizado desde o começo.

---

## Lidando com os Sinais (`src/handle_signals/handle_signals.c`)
Em seguida, vamos configurar os sinais para que o shell se comporte de maneira adequada, igual ao Bash. As ações que vamos precisar são:
- **Ctrl-C**: Vai só criar uma nova linha e mostrar o prompt.
- **Ctrl-D**: Vai fechar o shell.
- **Ctrl-\\**: Não vai fazer nada (fica em "silêncio").

Aqui, a ideia é garantir que o shell se comporte como esperado em modo interativo, sem travar ou causar comportamentos inesperados.

---

## Entrada do Usuário (`src/input/readline.c`)
Para capturar a entrada do usuário, utilizaremos a biblioteca `readline`, que oferece várias funcionalidades úteis para shells interativos:
- `readline(prompt)`: Exibe um prompt personalizado e permite ao usuário digitar comandos com suporte a edição de linha.
- **Histórico**: O comando digitado pode ser adicionado ao histórico com `add_history`, permitindo que o usuário navegue pelos comandos anteriores com as setas do teclado.

Essa etapa garante uma interface interativa mais robusta e funcional.

---

## Verificação de Sintaxe (`src/syntax_check/syntax_check.c`)
Antes de começar a tokenizar a entrada, vamos fazer uma verificação simples de sintaxe para pegar erros evidentes, como:
- **Pipes (`|`)** usados de forma errada (ex.: `| comando`).
- **Redirecionamentos (`>`, `>>`, `<`)** sem o arquivo especificado.

A ideia é garantir que a entrada esteja minimamente correta antes de processar os tokens, o que ajuda a evitar problemas mais complexos nas etapas seguintes.

---

## Tokenização (`src/tokenizer/tokenizer.c`)
Agora, com a entrada validada, vamos quebrá-la em tokens, que são os pedaços principais da nossa linha de comando, como:
- **Comandos** (ex.: `ls`, `echo`).
- **Operadores** (ex.: `|`, `>`).
- **Parâmetros** (ex.: arquivos, argumentos).

Vamos criar uma **linked list de tokens** que representa a entrada em partes separadas. Essa lista será a base para a próxima etapa.

---

## Analisando os Tokens (`src/parser/parser.c`)
Depois de ter a lista de tokens, vamos analisá-los mais profundamente. O parser vai:
- Verificar o contexto de cada token (ex.: se uma string está entre aspas ou não).
- Corrigir a tipagem dos tokens dependendo da ordem e do que aparece antes ou depois.

A ideia é criar uma estrutura mais detalhada e organizada, onde a gente consegue entender melhor cada parte da entrada.

---

## Árvore Binária (`src/binary_tree/binary_tree.c`)
Agora, organizamos tudo em uma **árvore binária**. Nessa árvore, garantimos que os operadores e comandos estejam organizados de forma correta, com a ordem de execução respeitando as prioridades. 

Por exemplo:
- O **pipe (`|`)** tem uma prioridade maior do que rodar um comando simples.
- Os **redirecionamentos (`>`, `<`)** ficam entre os comandos, como no Bash.

A árvore binária nos ajuda a visualizar claramente a ordem das operações, sendo a base para a execução dos comandos.

---

## Executando os Comandos (`src/executer/executer.c`)
Depois que a árvore binária estiver pronta, vamos para a execução. Dependendo do tipo de nó da árvore, o executer vai decidir o que fazer:
- Se for um **comando built-in** (como `cd`, `echo`, `exit`), ele chama a função correspondente diretamente.
- Se for um **comando externo**, ele procura o comando no `PATH` e tenta executá-lo.

Essa parte é onde o shell realmente “faz o trabalho” e executa o que o usuário pediu.

---

## Builtins (`src/builtins/`)
Como os built-ins (como `echo`, `cd`, `exit`) são parte do funcionamento básico do shell, vamos ter uma pasta separada para cada um, com suas próprias funções:
- `src/builtins/echo/echo.c`
- `src/builtins/cd/cd.c`
- `src/builtins/pwd/pwd.c`
- `src/builtins/export/export.c`
- `src/builtins/unset/unset.c`
- `src/builtins/env/env.c`
- `src/builtins/exit/exit.c`

Cada um desses arquivos vai implementar a lógica para o respectivo comando, e vamos chamá-los conforme a necessidade durante a execução.


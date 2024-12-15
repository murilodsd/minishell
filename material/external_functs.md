# FUNÇÕES AUTORIZADAS

## 1. Inicialização do Shell (Leitura e Configuração Inicial)
Essa etapa prepara o shell para operação, configurando variáveis, sinais e recebendo os primeiros comandos.

### Funções Úteis:
- **`readline`**: Captura o comando digitado pelo usuário exibindo um prompt interativo.  
  *Exemplo*: Mostrar `miniminishell>` e aguardar o input do usuário.
- **`add_history`**: Armazena cada comando digitado no histórico, permitindo navegação entre comandos anteriores com as setas.
- **`rl_clear_history`**: Limpa o histórico armazenado, liberando memória usada para armazenar comandos anteriores.  
  *Exemplo*: Usar ao finalizar o shell para evitar vazamentos de memória.
- **`getenv`**: Obtém valores de variáveis de ambiente importantes, como `PATH`, que determina os diretórios onde procurar executáveis.  
  *Exemplo*: Recuperar `PATH` para localizar comandos como `ls`.

---

## 2. Tratamento de Sinais
Configura o shell para lidar adequadamente com sinais como `Ctrl-C`, `Ctrl-D`, e `Ctrl-\`, mantendo a interatividade do terminal.

### Funções Úteis:
- **`signal` / `sigaction`**: Configuram manipuladores de sinais para tratar `SIGINT` (`Ctrl-C`), EOF (`Ctrl-D`) e `SIGQUIT` (`Ctrl-\`).  
  *Exemplo*: Reiniciar o prompt ao pressionar `Ctrl-C` ou encerrar o shell com `Ctrl-D`.
- **`rl_replace_line`**: Substitui a linha atual do prompt por uma nova, limpa.
- **`rl_on_new_line`**: Notifica o sistema de que uma nova linha está sendo iniciada após receber um sinal.
- **`rl_redisplay`**: Atualiza o display do prompt para refletir as mudanças feitas pelos sinais.
- **`sigemptyset` / `sigaddset`**: Configura conjuntos de sinais para bloqueio ou desbloqueio.
- **`kill`**: Envia sinais para processos filhos.  
  *Exemplo*: Finalizar um processo filho ao pressionar `Ctrl-C`.

---

## 3. Tokenização (Divisão da Linha de Comando em Tokens)
Dividir a entrada do usuário em tokens que representem comandos, argumentos, operadores e redirecionamentos.

### Funções Úteis:
- **`read`**: Para leitura direta de entrada, como comandos de scripts ou arquivos.  
  *Exemplo*: Processar comandos de um arquivo de configuração inicial.

---

## 4. Parsing (Análise e Organização dos Tokens)
Organiza os tokens em uma estrutura lógica (como uma árvore binária) para facilitar a execução.

### Funções Úteis:
- **`access`**: Verifica se arquivos associados aos comandos existem e têm permissões necessárias.  
  *Exemplo*: Garantir que `./script.sh` é executável antes de tentar rodá-lo.
- **`stat` / `lstat` / `fstat`**: Obtêm informações detalhadas sobre arquivos, como permissões, tipo de arquivo e timestamps.  
  *Exemplo*: Identificar se um caminho é um arquivo regular ou um link simbólico.

---

## 5. Execução de Comandos Simples (Sem Redirecionamento ou Pipes)
Executa comandos básicos como `ls`, `echo` ou `cd`.

### Funções Úteis:
- **`execve`**: Substitui o processo atual por um programa externo.  
  *Exemplo*: Usado para executar comandos como `ls` ou `cat`.
- **`fork`**: Cria processos filhos para executar comandos enquanto o shell principal permanece ativo.
- **`wait` / `waitpid` / `wait3` / `wait4`**: Sincroniza o processo pai com o término de um processo filho, com `wait3` e `wait4` coletando informações adicionais sobre o uso de recursos.  
  *Exemplo*: Garantir que `sleep 5` termine antes de exibir o prompt novamente.
- **`getcwd`**: Recupera o diretório atual para comandos como `pwd`.
- **`chdir`**: Muda o diretório atual para implementar `cd`.

---

## 6. Redirecionamento de Entrada/Saída
Permite executar comandos como `ls > out.txt` ou `cat < file.txt`.

### Funções Úteis:
- **`open`**: Abre arquivos para leitura ou escrita.  
  *Exemplo*: Criar `out.txt` para armazenar a saída do comando.
- **`dup` / `dup2`**: Substitui descritores de arquivo para redirecionar a entrada ou saída padrão.
- **`close`**: Fecha descritores de arquivo após uso para evitar vazamentos de recursos.
- **`unlink`**: Remove arquivos temporários criados durante o redirecionamento.

---

## 7. Execução de Pipes
Permite executar comandos encadeados, como `ls | grep test`.

### Funções Úteis:
- **`pipe`**: Cria canais de comunicação entre dois processos.  
  *Exemplo*: Encaminha a saída de `ls` para `grep`.
- **`fork`**: Cria processos para cada comando no pipeline.
- **`dup2`**: Redireciona a entrada e saída para usar os lados de leitura/escrita do pipe.
- **`wait` / `waitpid`**: Sincroniza os processos conectados pelo pipeline.

---

## 8. Comandos Internos (Builtins)
Implementa comandos próprios do shell como `cd`, `pwd`, `exit`.

### Funções Úteis:
- **`getcwd`**: Retorna o diretório atual para o comando `pwd`.
- **`chdir`**: Altera o diretório de trabalho para implementar `cd`.
- **`exit`**: Finaliza o processo atual.

---

## 9. Interatividade Avançada (Manipulação do Terminal)
Melhora a experiência do usuário ao interagir com o shell.

### Funções Úteis:
- **`isatty`**: Verifica se a entrada é de um terminal ou de um script.  
  *Exemplo*: Suprimir o prompt ao processar scripts.
- **`tcsetattr` / `tcgetattr`**: Configura modos de entrada, como desativar o `ECHO`.
- **`ioctl`**: Controla dispositivos de entrada/saída, como terminais, para implementar funcionalidade adicional.
- **`ttyname`**: Obtém o nome do terminal associado a um descritor de arquivo.  
  *Exemplo*: Identificar o terminal ativo para exibição de mensagens.
- **`ttyslot`**: Retorna o número da sessão associada ao terminal atual.
- **`opendir` / `readdir` / `closedir`**: Manipulam diretórios, como listar conteúdo para comandos internos de gerenciamento de arquivos.
- **`tgetent` / `tgetflag` / `tgetnum` / `tgetstr` / `tgoto` / `tputs`**: Funções da biblioteca `termcap` usadas para manipulação avançada de terminais, como gerenciamento de capacidades, movimentação do cursor e exibição formatada.  
  *Exemplo*: Configurar o terminal para exibir prompts customizados ou limpar a tela.

---

## 10. Funções Gerais e Utilitárias
As funções abaixo são amplamente úteis e aplicáveis em todas as etapas do shell:

### Funções Úteis:
- **`malloc` / `free`**: Para gerenciar memória dinâmica em todas as partes do programa.
- **`write`**: Para exibir mensagens no terminal diretamente.
- **`printf`**: Para formatação de saída mais detalhada.
- **`perror` / `strerror`**: Para exibição de mensagens de erro de maneira amigável e contextual.


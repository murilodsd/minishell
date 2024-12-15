# Minishell

# Minishell

Minishell is a simple Unix shell implementation that replicates some basic functionalities of a shell environment. It supports command execution, pipes, redirection, environment variables, and more. This project is designed to deepen the understanding of processes, system calls, and inter-process communication in Linux.
This project was developed in collaboration with my course mate [Murilo](https://github.com/murilodsd). 

## Features

- **Prompt**: Displays a prompt when waiting for a new command.
- **Command History**: Implements a working history of commands.
- **Command Execution**: Search and launch executables based on the PATH variable or using relative/absolute paths.
- **Redirection**: Supports `<`, `>`, `>>`, and `<<` for input and output redirection.
- **Pipes**: Supports pipes (`|`) to connect commands.
- **Quoting**: Handles single (`'`) and double (`"`) quotes to prevent interpretation of metacharacters inside the quotes.
- **Environment Variables**: Expands environment variables, such as `$HOME`, and handles `$?` to expand to the exit status of the most recently executed foreground pipeline.
- **Signal Handling**: Implements handling for `Ctrl-C`, `Ctrl-D`, and `Ctrl-\`.
- **Builtins**: Implements the following builtins:
  - `echo -n`
  - `cd` (only with relative or absolute paths)
  - `pwd` (no options)
  - `export` (no options)
  - `unset` (no options)
  - `env` (no options or arguments)
  - `exit` (no options)

## Installation

To install and run Minishell, follow these steps:

1. Clone the repository:

```bash
git clone https://github.com/yourusername/minishell.git

2. Navigate to the project directory and compile the program using make:

```bash
cd minishell
make

## Usage

To run the shell:
```bash
./minishell

### Example

```bash
minishell> `echo Hello, world!`
Hello, world!

```bash
- minishell> `cd /home/user`
- minishell> pwd
- /home/user

```bash
- minishell> ```bash echo $HOME
- /home/user

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

## Getting Started
---------------

### Prerequisites

Ensure that you have the following installed on your system:

-   **GNU Make**

-   **GCC Compiler**

-   **Readline Library**: Download the Readline library and place it in the directory above `minishell`. In the Readline directory, run `./configure` and `make`.

### Installation

1.  Clone the repository:

    ```
    git clone https://github.com/murilodsd/minishell.git
    ```

2.  Navigate to the project directory:

    ```
    cd minishell/minishell
    ```

3.  Build the project using Make:

    ```
    make
    ```

### Usage

After successful compilation, run the Minishell executable:

```
./minishell
```

You can now enter commands as you would in a standard shell.

Built-in Commands
-----------------

Minishell includes the following built-in commands:

-   `**echo**`: Display a line of text. Supports the `-n` option to omit the trailing newline.

-   `**cd**`: Change the current directory. Accepts relative or absolute paths.

-   `**pwd**`: Print the current working directory.

-   `**export**`: Set environment variables.

-   `**unset**`: Unset environment variables.

-   `**env**`: Display the environment variables.

-   `**exit**`: Exit the shell.

Redirections and Pipes
----------------------

-   **Input Redirection (**`**<**`**)**: Redirect input from a file.

-   **Output Redirection (**`**>**`**)**: Redirect output to a file, overwriting the file.

-   **Append Redirection (**`**>>**`**)**: Redirect output to a file, appending to the file.

-   **Pipes (**`**|**`**)**: Pass the output of one command as input to another.

Signal Handling
---------------

Minishell handles the following signals:

-   `**Ctrl+C**`: Interrupt the current command.

-   `**Ctrl+D**`: Exit the shell.

-   `**Ctrl+\**`: Quit the current process.

Environment Variables
---------------------

Minishell supports environment variable expansion using the `$` symbol. For example, `$HOME` will be expanded to the user's home directory.

Logic Behind the Construction
-----------------------------

The development of the **Minishell** project is structured to emulate the basic behavior of a Unix shell while adhering to a modular and organized approach. Below is an outline of the main logical steps and components involved:

### 1\. Parsing the Input

-   **Lexical Analysis**: The input string is split into tokens (commands, arguments, operators like `|`, `>`, `<`, etc.).

-   **Syntax Analysis**: The parser validates the order and structure of the tokens to ensure they form a valid command or pipeline.

-   **Abstract Syntax Tree (AST)**: Tokens are organized into a tree structure to represent the command hierarchy and dependencies, making it easier to execute complex commands.

### 2\. Executing Commands

-   **Built-in Commands**: Commands like `echo`, `cd`, and `export` are implemented directly within the shell. They are executed without creating a new process.

-   **External Commands**: For non-built-in commands, the shell searches the system's `$PATH` environment variable to locate the executable. The `execve` system call is used to run these commands.

### 3\. Handling Redirections

-   **Input Redirection (**`**<**`**)**: The shell redirects standard input (`stdin`) to read from a specified file.

-   **Output Redirection (**`**>**`**)**: Standard output (`stdout`) is redirected to a file, overwriting its content.

-   **Append Redirection (**`**>>**`**)**: Similar to output redirection, but appends to the file instead of overwriting.

-   **Logic**: The file descriptors are manipulated using system calls like `open`, `dup2`, and `close`.

### 4\. Pipelines

-   **Process Chaining**: For commands separated by `|`, the shell creates a pipeline to pass the output of one command as the input of the next.

-   **Implementation**: Pipes are implemented using the `pipe` system call, and multiple processes are managed with `fork` and `execve`.

### 5\. Environment Variables

-   **Storage and Expansion**: Environment variables are stored in a dictionary-like structure. The `$` symbol is used to expand their values during parsing.

-   **Modification**: Built-in commands like `export` and `unset` allow users to modify the environment variables dynamically.

### 6\. Signal Handling

-   **Interactive Shell**: Signals like `SIGINT` (Ctrl+C) and `EOF` (Ctrl+D) are handled gracefully to avoid crashing the shell and provide a smooth user experience.

-   **Child Processes**: Signals are forwarded to child processes when necessary.

### 7\. Error Handling

-   **User Feedback**: Invalid commands, syntax errors, and failed system calls are communicated to the user with appropriate error messages.

-   **Exit Codes**: Each command returns an exit code that reflects its success or failure, as required by Unix standards.

### 8\. Memory Management

-   **Dynamic Allocation**: Memory for tokens, the AST, and environment variables is dynamically allocated during execution.

-   **Cleanup**: Proper memory management ensures no memory leaks occur by freeing all allocated resources before the shell exits.

### 9\. Modularity

-   Each functionality is implemented in a separate module or file, ensuring the code is clean and maintainable.

-   Key components like the parser, executor, and built-ins are independent, making debugging and future extensions easier.

This structured approach ensures that the **Minishell** replicates a Unix shell's core functionalities while maintaining code readability and extensibility.

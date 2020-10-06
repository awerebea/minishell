# minishell
21-School (Ecole42) 'minishell' project. Score .

## Description
This is the first team project of the school course. The goal of this project is to create your own CLI implementation.

**minishell** implements builtins functions:
* `echo` with option ’-n’
* `cd` with only a relative or absolute path
* `pwd` without any options
* `export` without any options
* `unset` without any options
* `env` without any options and any arguments
* `exit` without any options

also it can run any other binary file, in case this file is located in PATH, no need to enter full path.

Commands separator `;`, [`redirections`](https://www.gnu.org/software/bash/manual/html_node/Redirections.html) (`<`, `>`, `>>`), [`pipelines`](https://www.gnu.org/software/bash/manual/html_node/Pipelines.html) (`|`), quotes `'`, `"`, termination [`signals`](https://www.gnu.org/software/libc/manual/html_node/Termination-Signals.html) (`Ctrl+C`, `Ctrl+\`) and EOF (End-of-file) marker (`Ctrl+D`) are also handled "like in **bash**".

## Dependencies:
This project uses my own Libft library with functions from my previous [`Libft`](https://github.com/awerebea/libft) projects as a submodule.
Therefore, to clone the complete project, use the additional `--recursive` flag.
```
git clone --recursive https://github.com/awerebea/minishell.git
```

## Usage:
To build the library and program, at the root of this cloned repository, run:
```
make
```
and then to run the **minishell**, run:
```
./minishell
```
Try using **single-line** commands with bash syntax and enjoy! :wink:

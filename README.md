# PIPEX

This is an attempt to recreate the behavior of unix pipes using C.

## Compilation

```bash
cd src
make
```

## How to use?

There are two ways of running the program:

```bash
./pipex <infile> <command1> <command2> ... <outfile>
./pipex here_doc <LIMITER> <command1> <command2> ... <outfile>
```

There work equally like the following bash command:

```bash
< infile command1 | command2 > outfile
<< LIMITER command1 | command2 >> outfile
```

Examples:

```bash
./pipex pipex_main.c "grep return" "awk '{print \$2}'" outfile
./pipex here_doc EOF "grep hi" "grep bye" "grep jj" outfile
```

A general picture of how data is parsed inside the child processes is illustrated as follows:

<img src="/docs/pipex_child_diagram.jpg" alt="architecture" width="50%">
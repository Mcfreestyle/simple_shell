## **Project: C - Simple Shell**

------------
#### Description

------------

- Creation of the command line interface of the Unix Shell project for Linux systems. This Shell can interpret instructions and perform Syscall.
- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language (the direct predecessor to the C programming language)
- Who is Ken Thompson.
- How does a shell work.
- What is a pid and a ppid.
- How to manipulate the environment of the current process.
- What is the difference between a function and a system call.
- How to create processes.
- What are the three prototypes of main.
- How does the shell use the PATH to find the programs.
- How to execute another program with the execve system call.
- How to suspend the execution of a process until one of its children terminates.
- What is EOF / "end-of-file"?.

------------

#### **Requirements**

------------

- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to

------------
#### **Compilation**

------------
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

------------
#### **Testing**

------------

Your shell should work like this in interactive mode:

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

But also in non-interactive mode:

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

------------

How to use it?
------------
##### **First step:**
###### Clone the shell repository:
------------
[HTTPS] https://github.com/Mcfreestyle/simple_shell.git
[SSH] git@github.com:Mcfreestyle/simple_shell.git

------------
##### **Second step:** 
Run all * .c files from the repository like this :

------------
	 gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

------------
##### **Third step:** 
###### Run the SHELL (executable file) and enjoy!
------------
	 ./hsh

------------
### List of useful commands
------------
- ls - will list all files and directories in current working directory.
- pwd - given you the current working directory.

------------
### Builtins
------------
There are two builtins programmed into the shell. Below is a description and use for each builtin.

- env - The env command is a command that tells the shell program to display all of the environment variables with their values. It is a way to access those values through the shell.

- exit - If you wish to exit out of the shell the user can use the builtin exit.

------------
#### **Authors**
Michael Chambilla - [Github](https://github.com/Mcfreestyle "Github")

Jeshua Cabanillas - [Github](https://github.com/josh-94 "Github") - [Twitter](https://twitter.com/Jeshua_CabanBla "Twitter")

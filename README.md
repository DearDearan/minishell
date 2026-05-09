_This project has been created as part of the 42 curriculum by cboucher and lifranco._

# minishell

## Description

Minishell is a project which the main goal is to make a simple terminal Shell.

A Shell is basically a prompt that can execute commands and make redirections. Examples of Shells are Zsh, fish, or what we use as a reference for ours, bash.

Minishell should display a prompt when waiting for a new command. It also need to have a <ins>**working history**</ins>.

Minishell should launch the right executable, whether you input a **relative**, **absolute** or a **PATH inside an environment variable**.

Minishell should handle single quotes, which prevents the shell from interpreting special chars (Dollar sign for example), double quotes, which should prevent the shell from interpreting special characters ***except*** dollar sign. 

It also **shouldn't** process unclosed quotes or special characters <ins>**not specified by the subject**</ins>.

Minishell should handle redirections, which are :

- ">", which redirect input.
- "<", which redirect output.
- ">>", which redirect output in **append mode**.
- "<<", which should be given a delimiter, then read the input until a line containing the delimiter is seen.

It should also implement pipes, "|". The **output** of each command in the pipeline is connected to the **input** of the next command via a pipe.

It also **HAVE TO** handle expands, which are environment variables ($HOME for example, which should expand to /home/user). Although, Dollar sign and "?" should expand the exit status of the most recently executed foreground pipeline.

Minishell should handle signals of CTRL+C, CTRL+D and CTRL+\

- CTRL+C displays a new prompt on a newline.
- CTRL+D exits the shell **IF** the line is empty.
- CTRL+\ is absolutely fucking useless.

At last, Minishell has to have built-in commands. Those are the followings :

- echo, **with** or **without** the option "-n". -n should erase the newline at the end of the text written.

- cd, **with** or **without** a relative or absolute path.

- pwd with **no** options.

- export with **no** options.

- unset with **no** options.

- env with <ins>**no options or arguments**</ins>.

- exit with **no** options.


### Parsing

The parsing of Minishell is the equivalent of stubbing your toe while stepping on a lego while having a testicular torsion. It's one of the most MISERABLE THING I'VE EVER DONE.

The parsing handles redirections and pipes that are not separated by a space. how ? BY ADDING SPACES	


### Fundamental Concepts

todo

from pipex:CTRL+D sends an End-of-File signal, so it must be taken into account when reading from STDIN.

### Bash Comportements and Other Concepts Covered

- la fonction stat et le principe de tout est fichier + notions inode et autres types de fichiers avec sockets, etc (man 7 inode) Macros associes pour gerer les types de fichiers par exemple.
- les fonctions pour ouverture lecture et fermeture d'un dossier pour recuperer une structure informant sur les contenus d'un dossier.
- A noter que le heredoc de bash bug completement si on met un \n avec ctrl+v+j dans le heredoc. on ne peut plus quitter le heredoc

from pipex:
- In a bash session, we can limit the number of processes with `ulimit -u 547`, useful for certain tests.
- In bash, using `echo $?` retrieves the exit code of the last command executed.
- In bash, `command 2> errors.log` allows us to redirect the error output to errors.log, for example.
- For a bash session, using `unset PATH` clears the PATH environment variable and `export PATH="foe"` sets the PATH environment variable to foe.
- If the PATH environment variable does not exist or is empty, bash will look for the executable in the current directory.
- The /proc folder contains currently running processes, where we can find the open fds associated with each process.
- `env -i command` to remove all environment variables for the following command.
- `pgrep pipex` retrieves the pid corresponding to the pipex program name.
- `-fsanitize=address` in the compilation rules helps identify memory leaks during program execution without needing to use tools like Valgrind.

## Instructions

### Compilation

Use `make` or `make re` to compile the program. To clean generated files use `make clean` or `make fclean`.

### Usage

To use the minishell program, simply run minishell. It will wait for a prompt and you can uses it like bash.

## Technical Choices

On ne gere pas les caracteres speciaux y compris les \n du coups. On les consideres evidemment comme des caracteres a part entieres si ils sont dans les quotes.

On n'executera pas la commande et le child des la premiere redirection invalide

todo

## Improvement Suggestions

from pipex:
One potential improvement could be to check if a folder (relative or absolute) has the permissions to display "no such file or directory" instead of "command not found."
In the bash here_doc, the LIMITER does not contain single quotes or double quotes unless they are encapsulated by the other quotes. This behavior may be potentially necessary for the future minishell project.
In the case where a newline is injected into the LIMITER with CTRL+v+j, I am currently not counting the \n in my here_doc, but it will likely be necessary in minishell, and in that case, I will not use the get_next_line function. However, I thought about safeguarding this case here.

## Resources

1.	[Article by Roslyn Michelle](https://www.rozmichelle.com/pipes-forks-dups/)
2.	[CodeVault's Youtube playlist](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)
3.	Peer-to-peer learning.
4.	man
5.	Web research and AI chat for some notions.

## TODO

1) checker infos du GDOC sur Environmental variables :
J'ai notamment reperer ceci :
export VAR="truc ' bidule"
echo $VAR
------> bash affiche le single quote mais pas minishell
2) gerer les espaces avec ascii entre \t et \r pour tous les endroits ou on doit gerer les espaces
3) verifier que export = ou += ou env ne marche pas avec $?
4) regarder le pdf de correction
5) faire des corrections blanches ? alexandre dispo

## PRISE DE NOTE EN VRAC

- strace pour regarder les commandes de bash

comportements bash:
- chaque commande de bash gere leurs propres infile et outfile et prends en compte les derniers. ainsi chaque commande de pipe peut gerer son propre infile et oufile.
- bash gere le desordre : `< infile echo > outfile hello < infile2 world` va par exemple prendre comme infile : infile2, et va echo hello world dans outfile
- Les infiles et outfiles precedents sont tous testes au niveau des permissions mais sont ignore. le dernier outfile recevra les donnees et les autres seront seulement crees mais reste vide
- COMPORTEMENT BASH : le 17eme heredoc crash et retourne 2 -> bash: maximum here-document count exceeded


fonctions:
getenv : recup une var d'env
access : determmine si un fichier est accessible et ses permissions (a laide du path et du amode RWXF)
stat : retourne une struct pour infos sur un fichier/dossier via son chemin, macros utilisatbles pour savoir si c un fichier, dossier, etc...
fstat : meme chose mais via son fd
lstat : meme chose que stat mais ne suit pas les liens symboliques
isatty : pour eviter de lancer minishell a travers un pipe par exemple
getcwd : recuperer le dossier de travail actuel correspondant au binaire en execution
chdir : change le dossier de travail actuel pour le binaire en execution
opendir, readdir, closedir : ouvre un dossier, lit les fichiers un a un a chaque appel de cette fonction en renvoyant une structure (NE PAS FREE), ferme le dossier
unlink : supprime un fichier
wait3 et wait4 : variantes de wait et waitpid avec une structure qui donne plus d'infos
man 7 signal, man 2 : sigaction, sigemptyset, sigaddset, kill : a voir pour les signaux...

SIGINT = ctrl+C
SIGQUIT = ctrl + \
jai appris quil faut utiliser certaines fonctions dans la gestion des signaux (man 7 signal-safety)



ioctl : permet d'avoir la taille du terminal par exemple et configurer, gerer d'autres trucs avec des requetes et macros par rapport au device/terminal -> peut servir par exemple a injecter un \n dans un readline pour le terminer par exemple. Mais pas conseille dans un signal car la fonction est pas async safe
tcgetattr : Lire la configuration actuelle du terminal
tcsetattr : Modifier la configuration du terminal
tgetent : Charger les infos du terminal depuis la base de données
tgetflag    : Vérifier une capacité booléenne (supporte-t-il X ?)
tgetnum : Récupérer une valeur numérique (nombre de colonnes)
tgetstr : Obtenir une séquence d'échappement (code couleur, déplacement)
tgoto : Convertir des coordonnées en séquence d'échappement
tputs : Envoyer une séquence au terminal

## Travail de Camille, starting minishell lundi 30:

1 semaine : 4 jours de reflexion en commun et prototypage des structures
2 semaine : 1 journee de test comportements bash, 4 jours de code
3 semaine : 2 jours de code, 1 aprem pour apprendre git rebase -i et squash etc
4 semaine : 4 jours de code
5 semaine : 5 gros jours de code
6 semaine : 4 gros jours de debugs


ressources :
https://tiswww.cwru.edu/php/chet/readline/readline.html#index-rl_005fredisplay
https://tiswww.case.edu/php/chet/readline/history.html
https://www.conventionalcommits.org/en/v1.0.0/
https://docs.google.com/document/d/1r0yE7gK12J6lW79mzY8ELyKJEiDqkOeRfXZ6DWSKZVE/


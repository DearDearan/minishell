_This project has been created as part of the 42 curriculum by cboucher and lifranco._

# minishell

## Description

todo

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

- rm avec cd : refaire le prompt ne pas le clean et ajouter les erreurs et le nombres de /.. necessaire pour chaque sousdossier supprime
- global 130
- a corriger > out : exitcode a 1 alors que bash est a 0
- gerer variable glo avec les readline ?? verif exitcode 130 dans prompt ET dans heredoc pour CTRL+C
- faut il specifiquement kill les children avec les signaux ou rien a voir ?
- delete et replace ft_freeall by free strs de split
- renommer certaines variables pour anglicisme (ex: get_tab_size) et eventuellement rendre certaines plus explicites (ex: exit_c)
- leaks
- verifier quon a pas use des fontions interditent conne dprintf par exemple (a la place de ft_dprintf)
- verifier que les erreurs utilise bien ft_dprintf(2,)
- utiliser excel discord 42 chan minishell et testeur ndacun pour tests finaux

## PRISE DE NOTE EN VRAC

- strace pour regarder les commandes de bash

comportements bash:
- chaque commande de bash gere leurs propres infile et outfile et prends en compte les derniers. ainsi chaque commande de pipe peut gerer son propre infile et oufile.
- bash gere le desordre : `< infile echo > outfile hello < infile2 world` va par exemple prendre comme infile : infile2, et va echo hello world dans outfile
- Les infiles et outfiles precedents sont tous testes au niveau des permissions mais sont ignore. le dernier outfile recevra les donnees et les autres seront seulement crees mais reste vide

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



ioctl : permet d'avoir la taille du terminal par exemple et configurer, gerer d'autres trucs avec des requetes et macros par rapport au device/terminal
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
3 semaine : 2 jour de code, 1 aprem pour apprendre git rebase -i et squash etc
4 semaine : 4 jour de code

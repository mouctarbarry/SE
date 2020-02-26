L'archive td4-contents.tar contient les fichiers suivants :
- le fichier README.md, que vous êtes en train de lire ;
- le fichier atlacan.c, source de la bibliothèque de l'exercice 2 que vous
  allez utiliser ;
- le fichier atlacan.h, en-tête de la bibliothèque, décrivant les fonctions
  que vous pourrez utiliser pour répondre à l'exercice demandé.

Vous ne devez pas modifier les fichiers donnés. Votre code doit être écrit dans
un nouveau fichier, qui contient la directive :
#include "atlacan.h"

La compilation du projet se fait à l'aide de la commande suivante, si votre
fichier source personnel s'appelle main.c :
$ gcc main.c atlacan.c

Si vous constatez un quelconque bug dans la bibliothèque atlacan, n'hésitez pas
à envoyer un mail à pro.seb.gougeaud@gmail.com, avec le message d'erreur
affiché, et si possible la ligne de code incriminée (que vous pouvez trouver
en utilisant gdb). Attention, je ne répondrai pas si l'erreur vient de votre
'mauvaise' utilisation de la bibliothèque.

ATTENTION : à la compilation, le message suivant devrait s'afficher :
  In function '\_gen_name':
  atlacan.c: warning: the use of 'tmpnam' is dangerous, better use 'mkstemp'
Il s'agit d'un avertissement de la libc indiquant que la fonction 'tmpnam()' ne
doit pas être utilisée, car dangereuse en environnement multi-processus. J'en
parlerai en introduction de cours à la prochaine séance, mais sachez que dans
notre cas, elle ne l'est pas. N'en tenez donc pas rigueur.
Ex5: pour que si un chaine est rempli dans le zone de memoire, il y aura la caractère de fin. En plus il rend le zone propre.
Ex6: Non, ça signifie que la zone de mémoire est pret à etre reutilisé.

Ex17: Il nous reste les caracteres n'ayant pas affiche dans le buffer, donc mini_exit doit les afficher.

Ex20: Si le nombre de caracteres est egal a lai taille de buffer, '\0' ne sera pas ajoute a la fin de chaine.

Ex22: Strcpy: taille de memoire copiee n'est pas controle. Donc, on risque d'avoir BUFFER OVERFLOW si la taille de la chaine destinee n'est pas assez pour contenir la chaine copiee, via cette faille, les codes executables peuvent etre mettre en notre machine par des attaqueurs.
Solution: mini_strncopy qui prend n comme nombre caractere a copier.

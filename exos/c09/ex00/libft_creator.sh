#!/bin/sh

# Cree les fichiers binaires
gcc -c *.c

# Cree la bibliotheque (qui utilise les fichiers binaires)
ar rc libft.a *.o
***  EX02  ***

## Notions importantes

### I - std::vector && std::deque

a ) Vector

Dans un vector, les éléments sont stockés dans une seule zone mémoire contigue. Son fonctionnement est intéressant :

Imaginons qu'on veut un vector(size) = 4, et qu'on souhaite ajouté un 5ème élément.

- Le vector alloue un nouveau bloc, plus grand (Généralement capacité x 2). On appelle ça l'amortissement.
- Il copie tous les anciens éléments dans ce nouveau bloc.
- Il libère l'ancien bloc.
- Il place le nouvel élément à la suite.

Résultat : Les éléments restent toujours contigus en mémoire, même après réallocation. C'est pour ça que vector peut garantir que l'accès à v[i] est toujours un simple calcul d'adresse (base + i).

b ) Deque

- Dans un deque, les éléments sont rangés par blocs disjoints.
- Le container garde un tableau de pointeurs vers les différents blocs.
- Quand tu accèdes à d[i], il calcule dans quel bloc ça se trouve, et l'offset dans ce bloc.

L'avantage, c'est que Deque évite les recopies massives quand tu grossis.

L'inconvénient, c'est qu'il perd la contiguité -> Moins efficace pour les parcours lourds.

En résumé, dans un vector v[0] et v[1] seront toujours contigus en mémoire. Dans un deque non.

Mais si on dépasse la capacité d'un deque, on ajoute seulement un autre bloc mémoire disjoint. Dans un vector, on réalloue une nouvelle zone mémoire, plus grande, on copie tout le contenu de la précédente dans la nouvelle, et on la libère. Ce qui est bien plus couteux.

### II - Algorithmes et Notation Big O

L'idée de l'exercice est de trier une suite de nombre en utilisant le même algorithme sur deux structures de données différentes (Deque/Vector) pour mesurer l'impact sur le temps de calcul. 

On va donc utiliser l'algo de tri Ford-Johnson, une fusion des algo de tri par insertion et de merge sort. Aussi appelé Merge-Insertion.

b ) Notation Big O

En algorithmie, on utilise la notation Big O pour déterminer la relation entre croissance de consommation de ressource et augmentation de taille de données à traiter. 

Il s'agît donc d'un outil pour comparer et prévoir la conso de ressources d'un algo

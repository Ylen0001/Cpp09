***  EX02  ***

## Notions importantes

## I - std::vector && std::deque

### a ) Vector

Dans un vector, les éléments sont stockés dans une seule zone mémoire contigue. Son fonctionnement est intéressant :

Imaginons qu'on veut un vector(size) = 4, et qu'on souhaite ajouté un 5ème élément.

- Le vector alloue un nouveau bloc, plus grand (Généralement capacité x 2). On appelle ça l'amortissement.
- Il copie tous les anciens éléments dans ce nouveau bloc.
- Il libère l'ancien bloc.
- Il place le nouvel élément à la suite.

Résultat : Les éléments restent toujours contigus en mémoire, même après réallocation. C'est pour ça que vector peut garantir que l'accès à v[i] est toujours un simple calcul d'adresse (base + i).

### b ) Deque

- Dans un deque, les éléments sont rangés par blocs disjoints.
- Le container garde un tableau de pointeurs vers les différents blocs.
- Quand tu accèdes à d[i], il calcule dans quel bloc ça se trouve, et l'offset dans ce bloc.

L'avantage, c'est que Deque évite les recopies massives quand tu grossis.

L'inconvénient, c'est qu'il perd la contiguité -> Moins efficace pour les parcours lourds.

En résumé, dans un vector v[0] et v[1] seront toujours contigus en mémoire. Dans un deque non.

Mais si on dépasse la capacité d'un deque, on ajoute seulement un autre bloc mémoire disjoint. Dans un vector, on réalloue une nouvelle zone mémoire, plus grande, on copie tout le contenu de la précédente dans la nouvelle, et on la libère. Ce qui est bien plus couteux.

## II - Algorithmes et Notation Big O

L'idée de l'exercice est de trier une suite de nombre en utilisant le même algorithme sur deux structures de données différentes (Deque/Vector) pour mesurer l'impact sur le temps de calcul.

On va donc utiliser l'algo de tri Ford-Johnson, une fusion des algo de tri par insertion et de merge sort. Aussi appelé Merge-Insertion.

### a ) Notation Big O

En algorithmie, on utilise la notation Big O pour déterminer la relation entre croissance de consommation de ressource et augmentation de taille de données à traiter.

Il s'agît donc d'un outil pour comparer et prévoir la conso de ressources d'un algo

### b ) Lire la notation

L'insertion list est notée **O(n²)** dans la notation big O. Comment lire ça?

"La complexité est proportionnelle au carré de la taille des données."


* **O(1)** → “temps constant”

  → peu importe combien de données tu as, ça prend le même temps (ex : accéder à `vector[i]`).
* **O(n)** → “linéaire”

  → si tu doubles `n`, le temps double (ex : parcourir un tableau).
* **O(log n)** → “logarithmique”

  → si tu doubles `n`, le temps augmente à peine (ex : recherche dichotomique).
* **O(n log n)** → “quasi-linéaire”

  → typique des bons algorithmes de tri comme quicksort ou mergesort.
* **O(n²)** → “quadratique”

  → très coûteux dès que la taille grandit (ex : tri par insertion ou tri à bulles).



## III - Tri Ford Johnson

Ford Johson est le nom de l'agorithme de tri dit Merge-Insertion. Il est la fusion des algo Merge et Insertion.

### a) Insertion list (Tri par insertion) --> O(n2)


* **Idée** : tu prends les éléments un par un et tu les insères à la bonne place dans une liste déjà triée.
* **Exemple** : imagine que tu ranges des cartes à jouer dans ta main.

  * Tu as déjà 3 cartes triées : `2, 5, 8`.
  * Tu prends un nouveau `6`. Tu le compares aux cartes de ta main et tu l’insères entre `5` et `8`.
* **Complexité** :

  * Dans le pire des cas, tu dois comparer avec toute la main →  **O(n²)** .
  * Avantage : ça marche très bien si ta liste est **courte** ou  **presque triée** .

### b) Merge sort (Tri fusion) --> O(n log n)


* **Idée** : tu découpes ta liste en deux moitiés, tu tries chaque moitié (en récursif), puis tu **fais fusionner** les deux listes triées.
* Exemple : `[7, 3, 9, 1]`

  * Découpe : `[7,3]` et `[9,1]`
  * Trie chaque moitié : `[3,7]` et `[1,9]`
  * Fusionne : `[1,3,7,9]`
* **Complexité** :

  * Toujours  **O(n log n)** , ce qui est très efficace, même pour de grandes listes.
  * Mais il nécessite de la mémoire supplémentaire (pour stocker les morceaux pendant la fusion).


👉 Si on fait une **métaphore vitesse de véhicules** :

* **O(1), O(log n)** → avion supersonique 🚀
* **O(n), O(n log n)** → voiture rapide 🚗
* **O(n²)** → vélo 🚲 (ok si le trajet est court)
* **O(2^n), O(n!)** → marcher à reculons pieds nus sur des Lego 🦶🧱 (impossible sur longue distance)

## IV - Objectifs du projet

- Parser une ligne de commande reçue sous forme de string

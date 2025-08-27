### ***  EX01  ***

### --- Reverse Polish Notation ---

1. En notation classique (infixe) :

* On écrit : `3 + 4 * 2`
* Problème : il faut savoir que `*` est prioritaire à `+`, ou utiliser des parenthèses : `3 + (4 * 2)`.
* Donc → il faut :
  * gérer les **priorités des opérateurs** (`*` et `/` avant `+` et `-`),
  * gérer les  **parenthèses** ,
  * avoir un **analyseur syntaxique** (parser) assez complexe pour comprendre ça.

👉 Pas naturel pour une machine : il faut coder des règles supplémentaires.

2. En notation polonaise inversée (RPN, postfixe) :

* On écrit la même chose : `3 4 2 * +`
* Ici, **l’ordre des symboles suffit** :

  on lit de gauche à droite, et on sait exactement quoi faire → pas besoin de règles de priorité ni de parenthèses.

👉 Pour la machine, c’est **beaucoup plus simple** : une seule pile suffit.

Donc ici, on pile 3, 4, 2. Quand on arrive sur *, on dépile 2 et 4 pour faire 2 * 4 = 8, on repile 8. LIFO is here.

### II - La stack (Container)

Ici, l'intérêt est de manipulation une stack, un type de container LIFO (Last in first Out), puisque dans le RPN dés qu'on croise un operateur, on doit dépiler les deux derniers éléments pour effectuer le calcul !

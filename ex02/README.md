***  EX02  ***

## Notions importantes

### I - Les différents containers


| Usage                            | Choix recommandé                   |
| -------------------------------- | ----------------------------------- |
| Accès rapide par index          | `std::vector`                     |
| Ajout/suppression en tête/queue | `std::deque (double-ended queue)` |
| Ajout/suppression au milieu      | `std::list`                       |
| Structure pile (LIFO)            | `std::stack`                      |

---
### Important à savoir ###

std::stack est un adaptateur de container. Qu'est-ce que quoi?

En gros, c'est une classe qui a dans ses membres protected un std::deque. Alors, pourquoi ne pas juste utiliser un deque plutôt qu'un stack?

Comme vu plus haut, la deque permet de manipuler les données du container sans trop de restrictions, là ou stack oblige un LIFO (Last In, First Out) et câche certaines des méthodes de deque. L'idée de stack, c'est de limiter les manipulations que l'utilisateur peut effectuer sur son container. Donc globalement, un stack, c'est une deque avec quelques règles en plus.

+ de contrôle, + de sécurité.
---
---

### II - Héritage de classes templates (Ici, std::stack)

Ici, il va être question de créer notre classe MutantStack, héritière de std::stack. 

**MutantStack est une classe template**. Pourquoi? Parce qu'on ne veut pas que cette classe soit limitée à un type précis, on veut qu'il soit utilisable pour des int, char, std::string etc...


### III - Redéfinition / Ajout de méthodes pour begin(), end().

Le but principal de l'exercice est d'offrir un template de classe dérivé de std::stack, qui peut utiliser les itérateurs.

On va donc écrire cette barbarie sans nom :

```cpp
// Cette ligne fait peur, mais c'est juste un alias pour écrire le type de retour.

typedef typename std::stack<T>::container_type::iterator iterator;

iterator begin() {return this->c.begin();};
iterator end() {return this->c.end();};
```

Ce qui veut globalement dire :

---
« Donne-moi le type const_iterator du conteneur utilisé par std::stack<T>, et crée un alias que j’appellerai iterator pour l’utiliser plus facilement ensuite. »
---
---
c.begin et c.end ici, signifient qu'on fait appel au begin/end du container de std::stack. Donc on renvoie l'itérateur du std::deque 'c' présent dans la classe std::stack.
---

### IV - Conclusion 

---
> On a donc crée un template de classe, dérivé de std::stack, au sein de laquelle nous avons défini des itérateurs, en réutilisant ceux du container de la classe std::stack, qui est un std::deque, nommé 'c' dans ses attributs protected. 

> On a également vu la synthaxe inhérente a une classe template. 
2 possibilités : 
- Déclarer les protos dans la classe, puis définitions à l'extérieur de la classe, mais toujours dans le .hpp.
- Proto dans la classe, et définitions dans un fichiers .tpp, sans oublier le #include "xxx.tpp".

> Le typedef typename

> 
---

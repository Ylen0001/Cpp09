### ***  EX01  ***

## Notions importantes


### I - Manipulation de containers

L'idée dans cet exercice est de créer une classe Span, constituée d'un vecteur, et d'une taille max.

Methodes :

- addNumber qui permet d'ajouter un nombre au vecteur, on l'utilisera pour remplir ce dernier. Si jamais le vecteur est déjà full, on throw une exception.
- shortestSpan() : renvoie la plus petite distance entre les nombres stockés. Si au nombre n'est stocké, ou un seul, throw une exception.
- longestSpan() : Idem, mais renvoie la plus grande distance.


### II - Implémentation de addNumber 

```cpp
void Span::addNumber(int number)
{
	if(_numbers.size() >= _maxSize)
		throw std::runtime_error("Span is full!");
	_numbers.push_back(number);
}
```

Si on dépasse la taille max, on throw une erreur. Sinon on ajoute la valeur à la fin du tableau avec vector::push_back().


### III - Implémentation de AddRange

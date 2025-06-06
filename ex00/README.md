# *** EX 00 ***

But de l'exercice :

---

> Afficher la valeur d'une certaine quantité de btc à une certaine date, en prenant en paramètre une base de données .csv.

---

## I - Notions clefs

### 1 - Containers

---

Dans std::map on stocke des paires clé-valeur.

- La clé est l'identifiant unique que tu utilises pour retrouver une donnée
- La valeur est la donnée associée à cette clé.

Donc dans notre cas :

- La clé est la date (Une std::string comme "2011-01-01").
- La valeur est l'exchange rate du BTC à cette date (Un double, par exemple "0.30").

La clé te permet donc d'accéder directement à la valeur associé. De plus, les clé sont automatiquement triées à l'insertion. On peut également ajouter, modifier ou supprimer des paires facilement.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

### II - Préparatifs

- Le nom du programme : btc.
- Le programme doit prendre un fichier en argument. (.txt seulement?)
- Pour chaque transaction du input.txt, calculer la valeur de la transaction (prix * quantité) en utilisant la donnée historique la plus proche ou correspondante.
- Gérer les erreurs, dates invalides, quantités invalides, données manquantes.
- Afficher le résultats/erreurs.

### III - Étape du code.

- Créer une fonction loadData, qui va récupérer les infos de la bd data.csv, pour rentrer les infos dans une map.

  - **Ouvre le fichier. ---> std::ifstream(filename, c_str())**
    *std::ifstream permet d'ouvrir le fichier, mais en c++98 la fonction prend un const char* en paramètre, donc on doit convertir la string filename en char* pour qu'elle puisse l'ouvrir.*
  - **Ignore la première ligne (date/valeur), lit ligne par ligne, et sépare la date et l'exchange rate.**
    *On utilise stringstream(line) pour découper chaque ligne*
  - **Lit ligne par ligne, Sépare la date/exchange rate, convertit l'ER en double, et stocke dans une map**
    *Ce qui est intéressant ici, c'est qu'on utilise getline(ss, date, ','), on lit dans le stringstream, et on stock tout ce qui se trouve avant la virgule dans str date, ensuite on refait un getline(ss, priceStr)*
  - Ouvre le fichier input.txt et on refait la même manipulation.

  ---

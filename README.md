# cub3D_napham_vbui

# Projet Cub3D - École 42

## Description
Ce projet a pour but de créer un jeu en 2D en utilisant les concepts de raycasting. L'objectif principal est de gérer une carte et des textures dans un fichier `.cub`, avec des fichiers d'extension `.xpm` pour les textures. Le jeu utilise la bibliothèque **MLX** pour l'affichage graphique.

Le projet se divise en plusieurs parties : parsing du fichier `.cub`, gestion des textures et des couleurs, validation des paramètres, ainsi que la gestion du rendu et du déplacement du joueur.

## Structure du Projet

### Fichiers Parsing

Le parsing est divisé en plusieurs fichiers pour traiter les différentes parties du fichier `.cub`. Voici les principaux fichiers impliqués :

1. **args_checker.c** : 
   - Ce fichier vérifie les arguments passés à l'exécution, notamment si le fichier `.cub` est valide.

2. **file_loader.c** : 
   - Chargement du fichier `.cub` dans un tableau de chaînes de caractères.
   - Fonctionnalités :
     - `count_file_lines` : Compte le nombre de lignes dans le fichier.
     - `load_file_content` : Charge toutes les lignes du fichier dans un tableau.
     - `load_map_file` : Charge le fichier `.cub` et vérifie sa syntaxe (textures, couleurs, carte, etc.).

3. **texture_checker.c** : 
   - Vérifie la validité des textures définies dans le fichier `.cub`.
   - Validation des chemins de fichiers `.xpm` et des textures associées au sol/plafond.

4. **map_boundaries.c** : 
   - Vérifie que la carte est bien entourée de murs (horizontaux et verticaux).
   - Valide que la carte respecte les limites nécessaires pour le bon affichage et la jouabilité.

5. **map_loader.c** : 
   - Chargement de la carte (représentée sous forme de tableau de caractères).
   - Recherche de la première ligne de la carte et enregistrement de la carte avec les bons murs et limites.

6. **map_validator.c** : 
   - Valide la syntaxe de la carte en s'assurant que tous les murs sont présents et que la carte est correctement formée.
   - Vérifie les caractères valides (`0`, `1`, `N`, `S`, `E`, `W`).
   - Vérifie que les espaces ne sont pas adjacents à des zones traversables.

7. **player_position.c** : 
   - Gère la position du joueur sur la carte.
   - Vérifie que le joueur est placé correctement, que sa position n'est pas à proximité de zones vides, et s'assure qu'il n'y a qu'un seul joueur sur la carte.

8. **rgb_parser.c** : 
   - Gère le parsing des couleurs RGB pour le sol et le plafond.
   - Vérifie que les valeurs RGB sont valides et dans la plage correcte (0-255).

### Fichiers supplémentaires

1. **cub3d.h** : 
   - Contient toutes les déclarations des structures utilisées dans le projet (`t_data`, `t_mapinfo`, `t_texinfo`, `t_player`, etc.).
   - Déclare les différentes fonctions du projet ainsi que les macros d'erreur.

2. **utils.c** : 
   - Contient des fonctions utilitaires pour la gestion des erreurs (`display_error_message`, `free_data`), la conversion des couleurs RGB en valeurs hexadécimales, et des fonctions d'affichage d'erreurs détaillées.

3. **main.c** :
   - Point d'entrée du programme. 
   - Initialise les données, charge le fichier `.cub`, valide les textures et les couleurs, puis affiche un message de succès si tout est correct.

## Fonctionnement du Parsing

### 1. **Vérification du Fichier**

Lorsque le fichier `.cub` est passé en argument, il est d'abord vérifié pour s'assurer qu'il est valide et que les chemins des fichiers `.xpm` sont corrects. Si des erreurs sont trouvées, un message d'erreur détaillé est affiché.

### 2. **Chargement du Fichier**

Le fichier `.cub` est chargé ligne par ligne. Les lignes sont stockées dans un tableau et sont ensuite traitées pour extraire les informations nécessaires : textures, couleurs, et la carte elle-même.

### 3. **Validation des Textures et Couleurs**

Les textures doivent être spécifiées dans le fichier `.cub` avec des chemins valides vers des fichiers `.xpm`. Les couleurs du sol et du plafond sont également extraites et converties en valeurs hexadécimales.

### 4. **Validation de la Carte**

La carte est ensuite validée. Il est vérifié qu'elle est entourée de murs et que les caractères dans la carte sont valides (seulement `0`, `1`, et `NSEW` pour le joueur). Les espaces ne doivent pas être adjacents à des zones traversables.

### 5. **Position du Joueur**

Enfin, la position du joueur est déterminée et vérifiée pour s'assurer qu'il n'y a qu'un seul joueur et qu'il est correctement placé sur la carte.

## Commandes


### Exécution
Pour exécuter le programme, passez le chemin vers le fichier `.cub` comme argument :

./cub3d <path/to/map.cub>




## À faire

- Ajouter la gestion de l'affichage avec la bibliothèque **MLX**.
- Implémenter le rendu en 3D avec le raycasting.

---

Si tu as des questions ou des points à clarifier, n'hésite pas à me contacter !

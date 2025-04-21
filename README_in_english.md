# cub3D_napham_vbui

## Cub3D Project - 42 School

### Description
This project aims to create a 2D game using raycasting concepts. The main objective is to manage a map and textures within a `.cub` file, with `.xpm` files for the textures. The game uses the **MLX** library for graphical display.

The project is divided into several parts: parsing the `.cub` file, managing textures and colors, validating parameters, as well as handling rendering and player movement.

---

## Project Structure

### Parsing Files

The parsing is divided into several files to handle different parts of the `.cub` file. Here are the main files involved:

- **args_checker.c**: Checks the execution arguments, mainly whether the `.cub` file is valid.
- **file_loader.c**: Loads the `.cub` file into a string array and validates its syntax (textures, colors, map, etc.).
- **texture_checker.c**: Verifies the validity of textures in the `.cub` file.
- **map_boundaries.c**: Ensures that the map is surrounded by walls both horizontally and vertically.
- **map_loader.c**: Loads the map, processes walls, and ensures it's correctly formed.
- **map_validator.c**: Validates the map’s syntax, ensuring only valid characters (`0`, `1`, `N`, `S`, `E`, `W`).
- **player_position.c**: Handles player positioning on the map.
- **rgb_parser.c**: Manages RGB color parsing for the floor and ceiling.

---

### Additional Files

- **cub3d.h**: Contains all structure declarations (`t_data`, `t_mapinfo`, etc.).
- **utils.c**: Contains utility functions for error handling and memory freeing.
- **main.c**: Entry point of the program, initializing data and loading the `.cub` file.

---

## Parsing Workflow

1. **File Verification**: Checks if the `.cub` file is valid and if the `.xpm` textures are accessible.
2. **File Loading**: Loads the `.cub` file line by line into an array for processing.
3. **Textures and Colors Validation**: Verifies the paths to `.xpm` textures and converts floor/ceiling colors to hex.
4. **Map Validation**: Ensures the map is surrounded by walls and uses valid characters.
5. **Player Position**: Ensures there is only one player and it is placed correctly on the map.

---

### Running the Program

To run the program, pass the path to the `.cub` file as an argument:

```bash
./cub3d <path/to/map.cub>



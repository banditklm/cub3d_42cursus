# 🎮 cub3D

**cub3D** is a simple 3D game engine inspired by early raycasting games like Wolfenstein 3D, built as part of the 42 curriculum. It uses raycasting to render a 3D world from a 2D map.

## Project Structure

- `mandatory/` — Core implementation of the game
- `bonus/` — Enhanced version with extra features (e.g. minimap, animations, mouse handling, sound, etc.)
- `MLX42/` — The graphics library used (needs to be cloned from GitHub)

## Dependencies

This project uses the **MLX42** graphics library, which depends on **GLFW** and **CMake**.

1. Clone the MLX42 Library

Before compiling, you must clone the `MLX42` repo inside your project directory:

```bash
git clone https://github.com/codam-coding-college/MLX42.git
```
2. Install Required Packages
If you don’t have cmake and glfw installed on your machine, you can install them using Homebrew (macOS):
```bash
brew install glfw
brew install cmake
```
⚠️ If you're not using macOS or not using Homebrew, please refer to your system’s package manager or the [MLX42 repo](https://github.com/codam-coding-college/MLX42.git) for proper installation.

3. Build Instructions
To build the project, run:
```bash
make
```
4. Running the Game
Once compiled, launch the game with:

```bash
./cub3D [map_file.cub]
```
Make sure to provide a valid `.cub` map file!

Bonus Features
The bonus version includes:

A dynamic minimap

Mouse movement support

Basic animations

Sound effects

5. To build the bonus version, run:
```bash
make bonus
```

```bash
./cub3D_Bonus [map_file.cub]
```
Make sure to provide a valid `.cub` map file!









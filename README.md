# Wireframe renderer

|   |   |
| :-: | - |
| Topic | Line Drawing Algorithms, Isometric Projection |
| Related | Computer Graphics, Algorithms & Analysis |
| Stack | C |

# Description
A program for macOS that renderes a wireframe model from given 3D coordinates. <br>Draws lines with Bresenham's algorithm.

# Key features
- includes set of test maps in maps/ folder
- when launched shows user controls on the left side of the window
- translate (move) with arrow keys
- zoom with +/-
- rotate around any 3D axis with x y z
- choose the rendered model projection type
- user scan to render model line by line
- Fast! Try it yourself with larger maps like maps/mars.fdf or maps/julia.fdf 

# Getting Started

First, compile the program:<br>

```bash

make

```

Then run the compiled executable with any of the maps from maps/ folder:

```bash

./fdf maps/julia.fdf

```

![julia](https://i.ibb.co/NCtRyLv/wireframe-renderer.png)
![alt text](https://i.ibb.co/QP8sK28/Screenshot-from-2023-01-08-10-55-13.png)

# FdF

![](https://github.com/whoismtrx/42_minitalk/blob/main/gifs/fdf.gif)

## Overview

This project is about creating a simplified graphic `wireframe` (`fils de fer` in French, hence the name of the project) representation of a relief landscape linking various points `(x, y, z)` via segments. The coordinates of this landscape are stored in a file passed as a parameter to the program with extension `.fdf`. The goal is to learn about the basics of `graphic programming`, and in particular how to place points in space, how to join them with segments and how to observe the scene from a particular viewpoint.

## Key Features

The project is written in `C` and uses the `minilibx` library for the graphical part. The program reads the passed file, parse the data, and creates a wireframe representation of the landscape. The user can rotate the landscape in 3D, zoom in and out, and change the color gradient of the landscape.

## Getting Started

To start the project, run the following commands:

```
git clone https://github.com/whoismtrx/42_push_swap.git fdf
cd fdf
make
```

## Usage

```
./fdf maps/42.fdf
```
![](https://github.com/whoismtrx/42_minitalk/blob/main/gifs/42.gif)

```
./fdf maps/julia.fdf
```
![](https://github.com/whoismtrx/42_minitalk/blob/main/gifs/julia.gif)

```
./fdf maps/elem-frac.fdf
```
![](https://github.com/whoismtrx/42_minitalk/blob/main/gifs/fract.gif)

```
./fdf maps/t1.fdf
```
![](https://github.com/whoismtrx/42_minitalk/blob/main/gifs/t1.gif)

## Implementation

FdF is a graphic project that focuses on creating and manipulating maps. The project utilizes the `minilibx` library to render the graphics. The first step is to understand how to use the `minilibx` library, which provides functions for drawing and interacting with graphics.

Once familiar with the library, the next step is to parse data from a file and store it in a 2D array. This data represents the heights of points in the map. With the data prepared, we can start drawing the map.

Drawing the map involves connecting the points using lines. To achieve this, we use `Bresenham's line algorithm`, which calculates the points on a raster to approximate a straight line between two given points.

By default, the map is displayed in `parallel projection`, resembling a 2D map. However, to make it appear more three-dimensional, we apply isometric projection. `Isometric projection` is a method that visually represents three-dimensional objects in two dimensions, commonly used in technical and engineering drawings.

Now that the map is displayed in 3D, we might want to interact with it. To enable interaction, we implement various controls. These controls allow us to `rotate` the map, `zoom` in and out, `scale` the map, and add `different projections`. We can also incorporate additional features such as `color gradients`, the ability to change the `color scheme of the map`, `resetting the map` to its original state, and displaying a help `menu` for user guidance.

Overall, FdF is a project that combines the use of the minilibx library, data parsing, line drawing algorithms, projection techniques, and interactive controls to create and manipulate visually appealing maps.

## Resources

- [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
- [Breseham's Line Algorithm](https://digitalbunker.dev/bresenhams-line-algorithm/)
- [The Bresenham Line Algorithm](https://studylib.net/doc/18611482/the-bresenham-line-algorithm)
- [Isometric Projection](https://pikuma.com/blog/isometric-projection-in-games)
- [Rotation Matrix](https://en.wikipedia.org/wiki/Rotation_matrix)
- [Key Codes]()
![](https://github.com/whoismtrx/42_minitalk/blob/main/gifs/keys.png)
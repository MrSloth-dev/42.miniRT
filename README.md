# miniRT - My First Ray Tracer

A simple ray tracer built in C using the MiniLibX graphics library.

## Overview

This project is an introduction to the beautiful world of ray tracing, allowing the rendering of simple computer-generated images. Ray tracing is a rendering technique that produces a high degree of visual realism by tracing the path of light rays and simulating their interactions with virtual objects.

## Features

- Rendering of basic geometric shapes:
  - Spheres
  - Planes
  - Cylinders
- Light management:
  - Ambient lighting
  - Diffuse lighting
  - Hard shadows
- Camera with adjustable field of view
- Scene description using custom .rt configuration files
- Interactive scene navigation:
  - Move camera with WASD keys
  - Rotate camera with arrow keys
  - Select and modify objects

## Screenshots

[Alt Text](https://github.com/MrSloth-dev/42.miniRT/blob/main/assets/01.png)

## Controls

- **ESC**: Exit program
- **Arrow keys**: Rotate camera
- **W/A/S/D**: Move camera
- **Space/C**: Move camera up/down
- **Mouse click**: Select objects
- **H**: Toggle help menu
- **Z**: Reset camera position

## Installation

```bash
git clone https://github.com/MrSloth-dev/42.miniRT.git miniRT
cd miniRT
make
```

## Quick Demo
```bash
make demo
```

## Usage

```bash
./miniRT scenes/example.rt
```

## Acknowledgments

This project was developed with the help of "The Ray Tracer Challenge" book by Jamis Buck, which provided valuable insights into the mathematics and implementation details of ray tracing.


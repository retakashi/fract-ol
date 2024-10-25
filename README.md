# fract-ol
### Mandelbrot
![gif](https://github.com/retakashi/fract-ol/blob/main/image/Mandelbrot.gif)

### Julia 0.32+0.043
![gif](https://github.com/retakashi/fract-ol/blob/main/image/Julia.gif)

### Mandelber
![Mandelbar image](./image/Mandelbar%20image.png)

## Overview
C and MiniLibX are used to create a program that generates fractal shapes.

## Implementation Environment
- **Programming Language**: C
- **Operating Systems**: macOS
- **Compiler**: Apple Clang 15.0.0 (clang-1500.3.9.4), Target: arm64-apple-darwin23.6.0

## Usage
``` bash
git clone ...
cd fract-ol
make
./fractol <fractol shape> <Julia param>
```
### fractol shape
- Mandelbrot
  
    The Mandelbrot set is the collection of points c that do not diverge in the following iterative function.

    $z_{0} = 0,z_{n+1} = z_{n}^{2} + c$
- Julia
  
    The Julia set is the collection of points c that do not diverge in the following iterative function.

    $z_{n+1} = z_{n}^{2} + c,c = a + bi$

    Please enter the expression for c in the argument of the Julia set. For example:
  
      0.32+0.043
      -0.15652+1.03225
      -0.11+0.67
      0.11031-0.67037
      0.11031-0.67037
- Mandelbar
  
    The Mandelbar set is the collection of points c that do not diverge in the following iterative function.

    $z_{0} = 0,z = (z')^2 + c$

## Features
- B key, G key: The color changes.
- left arrow key, right arrow key: The view moves.
- mouse down, mouse up: The view zooms in and out based on the mouse position.
 

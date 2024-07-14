# Controls
- <kbd>**Esc**</kbd> - Close program
- <kbd>**Q**</kbd> - Increase angle (`Default` shader)
- <kbd>**E**</kbd> - Decrease angle (`Default` shader)
- <kbd>**LMB**</kbd> (Pressed) - Move across the field
- <kbd>**Mouse Wheel**</kbd> - Scale the field

# Description
A program for visualization fractals with coloring and animation. At the moment, Mandelbrot and Julia fractals are supported. Your welcome to add your fractals!

## Command line argument format

`{program name} [-{flag name 1} [flag value]] [-{flag name 2} [flag value]] ...`

If you have not specified the flag and value, then the following default values are provided: `Julia`, `Default`, `Argon.jpg`.

The Mandelbrot set fractal does not support `Animation` and `MousePos` shaders.

### Flags and values

#### Fractal name `-fractal [name]`

Possible values: `Julia`, `Mandelbrot`

#### Visualization shader `-shader [name]`

Possible values: `Default`, `Animation`, `MousePos`

#### Texture coloring `-texture [filename]`

The filename of the texture in the `res/texture` directory

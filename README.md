# Welcome to Fract-ol
This project is the first graphical project in 42's Common Core.
```
# How to use

First :
```{
git clone https://github.com/MrSloth-dev/42-Fractol.git
}```
```
Then you need to Download and configure to your machine the MinilibX (LINUX ONLY)
```{
make mini
}```
Now execute make to compile
```{
make
}```
Usage :
```{
./fractol <name_of_fractal>
}```
Inside there is a menu that you can open if 'h' is presente
### Note: Julia Set need 2 more arguments, the real component and the imaginary. For example : ./fractol julia -0.8 0.156 [^1].

### Makefile Rules
make - Compile so_long files.

make bonus - Compile so_long_bonus files.

make all - Compile mandatory + bonus files.

make clean - Delete all .o (object files) files.

make fclean - Delete all .o (object files) and .a (executable) files.

make re - Use rules fclean + all.
[^1]Please visit the [Wikipedia](https://en.wikipedia.org/wiki/Julia_set)

## How Does it Work?

The program is divided by 4 main parts: TODO: extend the explanation in each point, always in pseudocode and with references
-The analysis of the input
-Creating the environment
-Calculate the iteractions and Render the color
-Handle Events

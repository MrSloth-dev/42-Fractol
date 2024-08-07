# Welcome to Fract-ol
<p align="center">
This project is the first graphical project in 42's Common Core.
<img src="https://media.licdn.com/dms/image/D4D22AQELtQ-J7KlTxQ/feedshare-shrink_2048_1536/0/1718983331045?e=1726099200&v=beta&t=LdY0tMwPj98_X8AGRbzH-dsZe0xfyW-G3gDN-dy0DP8" width="800" height="600" border="10"/>
</p>
  
</p>

# How to use

First :
```
git clone https://github.com/MrSloth-dev/42-Fractol.git
```

Then you need to Download and configure to your machine the MinilibX (LINUX ONLY)
```
make mini
```
Now execute make to compile
```
make
```
Usage :
```
./fractol <name_of_fractal>
```
#### Note: Inside there is a menu that you can open if 'h' is pressed.

#### Note: Julia Set need 2 more arguments, the real component and the imaginary. For example : ./fractol julia -0.8 0.156 .[^1].

## Makefile Rules
```
make - Compile fractol files.

make mini - Download MiniLibX and configure it to the currrent PATH

make clean - Delete all .o (object files) files.

make fclean - Delete all .o (object files) and .a (executable) files.

make re - Use rules fclean + all.

make debug - add -g flag to compilation and rebuild.
```

## How Does it Work?

The program is divided by 4 main parts: TODO: extend the explanation in each point, always in pseudocode and with references
1. The analysis of the input
2. Creating the environment
3. Calculate the iteractions and Render the color
4. Handle Events

[^1]: Please visit the [Wikipedia](https://en.wikipedia.org/wiki/Julia_set)

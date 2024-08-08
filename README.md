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
    1. As stated by the subject [see [here]()], the program must be able to reproduce the Julia Set and Mandelbrot.
        - The usage will be ./fractol <name of the fractal>, but to complete the Julia Set we need to give the arguments of the initial condition.[^2]
        - In my case I did also the Quartic and Newton Fractals.
    2. To accept (float/double) numbers as arguments we need to improve our atoi into an Ascii to (float / double) NOTE: I used double to ensure less error when dealing with small numbers. NOTE: I used double to ensure less error when dealing with small numbers.
2. Creating the environment
    1. Because we are using MiniLibx, we need to take care of creating the display, the window and the image, with mlx_init(), mlx_new_window(), mlx_new_image() respectively.
    2. Because the mlx_putpixel has some issues with performace we need to create a new put pixel directly to out image. We call it my_mlx_put_pixel()
3. Calculate the iteractions and Render the color
    1. For understanding better how the fractals representation is rendered check this video.[Youtube](https://www.youtube.com/watch?v=uc2yok_pLV4)
    2. Now that we understand how to calculate the number of iterations, the Color calculation is easier.
        - The Color is an int represented in Hexadecimal, so 0x000000 is equal to 0 and the color BLACK. and 0xffffff is equal to 16777215 and the color WHITE.
        - It's easier to understand the colors as number if we represent 0x ff ff ff, as 0x is telling us that the number is in hexadecimal the first ff is the RED the second ff is the GREEN and the third is the BLUE, so if you add them we have.... [RGB](https://www.google.com/url?sa=t&source=web&rct=j&opi=89978449&url=https://pt.wikipedia.org/wiki/RGB&ved=2ahUKEwicsKbYxOWHAxWIRqQEHSH-DZYQFnoECBMQAQ&usg=AOvVaw1b0slebKyncPhmU0yrybU8)!
        - So if we have a range of color between BLACK and WHITE and we have max iterations of 100 p.e.
            - We convert the number of iterations inside our range of iteration (0 < iter < max_iter) to a new range of color (BLACK < calculated_number < WHITE)
            - NOTE: To improve the performance of our program the number should be lower, because each pixel will be calculated that number of times
4. Handle Events


[^1]: Please visit the [Wikipedia](https://en.wikipedia.org/wiki/Julia_set)

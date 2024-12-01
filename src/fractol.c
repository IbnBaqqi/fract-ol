/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:22:49 by sabdulba          #+#    #+#             */
/*   Updated: 2024/12/01 21:01:15 by sabdulba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void draw_pixel(t_fractal *frac, int32_t width, int32_t height);

static void draw_frac(t_fractal *frac, int x, int y)
{
	double a;
	double b;
	// int itr_num;
	uint32_t color;
	
	a = scale(y, frac->min, frac->max, 0, frac->width);
	b = scale(x, frac->min, frac->max, 0, frac->height);
	double ca = a;
    double cb = b;
	 // Mandelbrot iteration
    int n = 0;
    while (n < frac->max_iterations) {
        double aa = a * a - b * b;
        double bb = 2 * a * b;
        a = aa + ca;
        b = bb + cb;

        if (a * a + b * b > 16) {
             break;
         }
        n++;
    }
	
	//Brightness mapping
	double bright = scale(n, 0, frac->max_iterations, 0, 1.0);
	bright = sqrt(bright) * 255.0;
	if (n == frac->max_iterations) {
		bright = 0; // Point is in the set
	}

	// Calculate color (grayscale)
	color = (int)bright << 24 | (int)bright << 16 | (int)bright << 8 | 255;
	mlx_put_pixel(frac->img, x, y, color);
}

static void draw_pixel(t_fractal *frac, int32_t width, int32_t height)
{
	int x;
	int	y;

	x = 0;
	while (x < height)
	{
		y = 0;
		while (y < width)
		{
			draw_frac(frac, x, y);
			//mlx_put_pixel(frac->img, y, x, color);
			y++;
		}
		x++;
	}
}

void	fractol_base(t_fractal *frac)
{	
	frac->mlx = mlx_init(WIDTH, HEIGHT, frac->name, false);
	if (!frac->mlx)
		ft_error();
	frac->img = mlx_new_image(frac->mlx, WIDTH, HEIGHT);
	if (!frac->img)
    	exit(EXIT_FAILURE);
	draw_pixel(frac, WIDTH, HEIGHT);
	mlx_image_to_window(frac->mlx, frac->img, 0, 0);
	mlx_loop(frac->mlx);
	mlx_terminate(frac->mlx);
}

int main(int ac, char **av)
{
	t_fractal frac;
	    // Initialize fractal parameters
    frac.min = -3.0;
    frac.max = 3.0;
	frac.max_iterations = 50;
	frac.name = av[1]; //To edit
	if (ac == 2)
	{
		if (!ft_strncmp(av[1], "mandelbrot", 10))
			fractol_base(&frac);
	}
	else if (ac == 4)
	{
		if (ft_strncmp(av[1], "julia", 5))
			fractol_base(&frac);
	}
	else
	{
		ft_putstr_fd(ERROR_MSG, 1);
		exit(EXIT_FAILURE);
	}
	return (0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:22:49 by sabdulba          #+#    #+#             */
/*   Updated: 2024/12/02 21:23:26 by sabdulba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
static void draw_pixel(t_fractal *frac, int32_t width, int32_t height);

//draw the fractol set
static void draw_frac(t_fractal *frac, int x, int y)
{
	double	a;
	double	b;
	int		n;
	uint32_t color;
	
	a = scale(x, frac->min, frac->max, 0, HEIGHT);
	b = scale(y, frac->min, frac->max, 0, WIDTH);
	n = mandelbrot(a, b, frac);
	
	//Brightness mapping
	double bright = scale(n, BLACK, WHITE, 0, frac->max_iterations);
	bright = sqrt(bright) * 255.0;
	if (n == frac->max_iterations) {
		bright = WHITE; // Point is in the set
	}

	// Calculate color (grayscale)
	color = bright;
	//color = (int)bright << 24 | (int)bright << 16 | (int)bright << 8 | 255;
/* 	double t = scale(n, 0, frac->max_iterations, 0, 1.0);
	color = hsv_to_rgb(t * 360.0, 1.0, t);

	if (n == frac->max_iterations) {
		color = 0x000000FF; // Black for points in the set
	} */
	mlx_put_pixel(frac->img, x, y, color);
}

//fractol looping to access each pixel
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

/* void	fractol_base(t_fractal *frac)
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
} */
//Fractol initiation point
int fractol_base(t_fractal *frac)
{
	frac->mlx = mlx_init(WIDTH, HEIGHT, frac->name, false);
    if (!frac->mlx)
        return (EXIT_FAILURE);
	frac->img = mlx_new_image(frac->mlx, WIDTH, HEIGHT);
    if (!frac->img) {
        mlx_terminate(frac->mlx);
        return (EXIT_FAILURE);
    }
	draw_pixel(frac, WIDTH, HEIGHT);
	mlx_image_to_window(frac->mlx, frac->img, 0, 0);
	mlx_loop(frac->mlx);
	mlx_terminate(frac->mlx);
	return (0);
}
int main(int ac, char **av)
{
   	t_fractal frac;
	//frac.width = 800;
    //frac.height = 600;
    frac.min = -3.0;
    frac.max = 3.0;
    frac.max_iterations = 400;
	frac.name = av[1]; //To edit
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
			fractol_base(&frac);
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 5))
			fractol_base(&frac);
	else
	{
		ft_putstr_fd(ERROR_MSG, 1);
		exit(EXIT_FAILURE);
	}
	return (0);
}

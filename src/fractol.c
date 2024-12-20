/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:22:49 by sabdulba          #+#    #+#             */
/*   Updated: 2024/12/04 19:21:10 by sabdulba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//static void draw_pixel(t_fractal *frac, int32_t width, int32_t height);

//draw the fractol set
static void draw_frac(t_fractal *frac, int x, int y)
{
	double	a;
	double	b;
	int		n;
	uint32_t color;
	
	a = scale(x, frac->min, frac->max, 0, frac->height) + frac->xshift;
	b = scale(y, frac->min, frac->max, 0, frac->width) + frac->yshift;
	n = mandelbrot(a, b, frac);
	
	color = scale(n, BLACK, WHITE, 0, frac->max_iterations);
	//bright = sqrt(bright) * 255.0;
	if (n == frac->max_iterations) {
		color = WHITE;
	}
	//color = (int)bright << 24 | (int)bright << 16 | (int)bright << 8 | 255;
	mlx_put_pixel(frac->img, x, y, color);
}

//fractol looping to access each pixel
void draw_pixel(void* param)
{
	t_fractal* frac = (t_fractal*)param;
	int x;
	int	y;

	x = 0;
	while (x < frac->height)
	{
		y = 0;
		while (y < frac->width)
		{
			draw_frac(frac, x, y);
			y++;
		}
		x++;
	}
}

//Fractol initiation point
int fractol_base(t_fractal *frac)
{
	frac->mlx = mlx_init(frac->width, frac->height, frac->name, false);
    if (!frac->mlx)
		return (EXIT_FAILURE);
	frac->img = mlx_new_image(frac->mlx, frac->width, frac->height);
    if (!frac->img) {
        mlx_terminate(frac->mlx);
        return (EXIT_FAILURE);
    }
	draw_pixel(frac);
	mlx_image_to_window(frac->mlx, frac->img, 0, 0);
	mlx_key_hook(frac->mlx, &my_keyhook, frac);
	mlx_scroll_hook(frac->mlx, &my_mousehook, frac);
	mlx_loop_hook(frac->mlx, &draw_pixel, frac);
	mlx_loop(frac->mlx);
	mlx_terminate(frac->mlx);
	return (0);
}
int main(int ac, char **av)
{
   	t_fractal frac;
    frac.min = -3.0;
    frac.max = 3.0;
	frac.width = 800;
	frac.height = 800;
    frac.max_iterations = 200;
	frac.name = av[1]; //To edit
	frac.xshift = 0.0;
	frac.yshift = 0.0;
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

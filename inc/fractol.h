/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:20:39 by sabdulba          #+#    #+#             */
/*   Updated: 2024/12/03 02:11:21 by sabdulba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "color.h"

#include "../lib/libft/inc/libft.h"
#include "../lib/MLX42/include/MLX42/MLX42.h"

#define WIDTH 800
#define HEIGHT 800

#define ERROR_MSG "Available set are:\n\tmandelbrot and julia.\nRun with \"./fractol setname\"\njulia set requires range/cordinate.\n"
#define IMG_ERROR  "Image creation failed\n"



typedef struct s_fractal
{
	char		*name;
	mlx_t		*mlx;
	mlx_image_t	*img;
	double		min;
    double		max;
	int			max_iterations;
	double		xshift;
	double 		yshift;
}	t_fractal;

void		ft_error(void);
double		scale(double num, double min_n, double max_n, double min, double max);
int			mandelbrot(double x, double y, t_fractal *frac);
int			fractol_base(t_fractal *frac); //might change to static later
void		draw_pixel(t_fractal *frac, int32_t width, int32_t height);

//events
void my_keyhook(mlx_key_data_t keydata, void* param);
void my_mousehook(double xdelta, double ydelta, void* param);

# endif
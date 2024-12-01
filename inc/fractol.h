/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:20:39 by sabdulba          #+#    #+#             */
/*   Updated: 2024/12/01 20:17:13 by sabdulba         ###   ########.fr       */
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
//#include "../lib/libft/inc/ft_printf.h" // already added it to libft.h
#include "../lib/MLX42/include/MLX42/MLX42.h"

#define WIDTH 500
#define HEIGHT 500

#define ERROR_MSG "Available set are:\n\tmandelbrot and julia.\nRun with \"./fractol setname\"\njulia set requires range/cordinate.\n"
#define IMG_ERROR  "Image creation failed\n"



typedef struct s_fractal
{
	char		*name;
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			width;			// Image width
    int			height;			// Image height
	double		min;			// Minimum value for fractal range
    double		max;			// Maximum value for fractal range
	int			max_iterations;	// Maximum iterations for fractal calculation
}	t_fractal;

void	ft_error(void);
//scale the  size of the window to a much size within the fractal set usually -2 to +1
double	scale(double num, double min_n, double max_n, double min, double max);
int		mandelbrot(double x, double y, t_fractal *frac);
void	fractol_base(t_fractal *frac); //might change to static later

# endif
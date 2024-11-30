/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:20:39 by sabdulba          #+#    #+#             */
/*   Updated: 2024/11/30 15:52:55 by sabdulba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "color.h"

#include "../lib/libft/inc/libft.h"
//#include "../lib/libft/inc/ft_printf.h" // already added it to libft.h
#include "../lib/MLX42/include/MLX42/MLX42.h"

#define WIDTH 500
#define HEIGHT 500

void	ft_error(void);

typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_fractal;

# endif
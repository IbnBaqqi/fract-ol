/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:46:30 by sabdulba          #+#    #+#             */
/*   Updated: 2024/12/02 23:44:50 by sabdulba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_fractal* frac = (t_fractal*)param;
	
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		frac->xshift += 0.5;
	draw_pixel(frac, WIDTH, HEIGHT);
    mlx_image_to_window(frac->mlx, frac->img, 0, 0);
}
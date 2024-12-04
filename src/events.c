/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:46:30 by sabdulba          #+#    #+#             */
/*   Updated: 2024/12/04 19:20:38 by sabdulba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_fractal* frac = (t_fractal*)param;
	
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		frac->xshift += 0.1;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		frac->xshift -= 0.1;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		frac->yshift += 0.1;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		frac->yshift -= 0.1;
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
    	printf("Exiting program.\n");
    	mlx_close_window(frac->mlx);
	}
	//draw_pixel(frac);
    //mlx_image_to_window(frac->mlx, frac->img, 0, 0);
}

void my_mousehook(double xdelta, double ydelta, void* param)
{
    if (param == NULL) // Safety check
		return;
	(void)xdelta;
    t_fractal* frac = (t_fractal*)param;

    if (ydelta > 0) // Scroll up (zoom in)
    {
		frac->min *= 0.9; // Decrease range to zoom in
		frac->max *= 0.9;
		//printf("Zoomed in: min = %f, max = %f\n", frac->min, frac->max);
    }
    else if (ydelta < 0) // Scroll down (zoom out)
    {
		frac->min /= 0.9; // Increase range to zoom out
		frac->max /= 0.9;
		//printf("Zoomed out: min = %f, max = %f\n", frac->min, frac->max);
    }
	// Redraw the fractal after zooming
	//draw_pixel(frac);
	//mlx_image_to_window(frac->mlx, frac->img, 0, 0);
}

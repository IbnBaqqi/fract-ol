/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:22:49 by sabdulba          #+#    #+#             */
/*   Updated: 2024/11/25 22:23:40 by sabdulba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
// Written by Bruh

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define WIDTH 1000
#define HEIGHT 1000

static void draw_pixel_vert(int x, int y, mlx_image_t* img, uint32_t color);
static void draw_pixel_hort(int x, int y, mlx_image_t* img, uint32_t color);

// int32_t	main(void)
// {

// 	// MLX allows you to define its core behaviour before startup.
// 	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
// 	if (!mlx)
// 		return 0;

// 	// Create and display the image.
// 	mlx_image_t* img = mlx_new_image(mlx, 1000, 1000);
// 	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
// 		return 0;
// 	int i = 0, y = 0;
// 	while ((i < 100))
//   	{
// 		mlx_put_pixel(img, i, y, 255);
// 		i++;
// 		y++;
//   	}
// 	//mlx_put_pixel(img, 0, 0, 0xFF000000);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }
int main(void)
{
  mlx_t	*mlx;
  mlx_image_t* img;
  //int	window;
  //int i = 0;
  int y = 0;
  int x = 500;
  mlx = mlx_init(1000, 1000, "fract-ol", true);
  if (!mlx)
  	ft_error();
  //window = mlx_new_window(mlx, 1000, 1000, "Title");
  img = mlx_new_image(mlx, 1000, 1000);
  if (!img)
  	ft_error();
  mlx_image_to_window(mlx, img, 0, 0);
  draw_pixel_vert(x, y, img, 255);
  draw_pixel_hort(0, 500, img, 255);
  mlx_loop(mlx);
  mlx_terminate(mlx);
  return (0);
}

static void draw_pixel_vert(int x, int y, mlx_image_t* img, uint32_t color)
{
	int i = 0;
	
	while (i < 1000)
	{
		mlx_put_pixel(img, x, y, color);
		i++;
		y++;
	}
}
static void draw_pixel_hort(int x, int y, mlx_image_t* img, uint32_t color)
{
	int i = 0;
	// int x1;
	// int y1;
	// x = 500;
	// y = 0;
	while (i < 1000)
	{
		mlx_put_pixel(img, x, y, color);
		i++;
		x++;
	}
}
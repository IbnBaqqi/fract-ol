/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:22:49 by sabdulba          #+#    #+#             */
/*   Updated: 2024/11/23 20:08:15 by sabdulba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int main(void)
{
  mlx_t	*mlx;
  mlx_image_t* img;
  //int	window;
  
  mlx = mlx_init(500, 500, "fract-ol", true);
  if (!mlx)
  	ft_error();
  //window = mlx_new_window(mlx, 1000, 1000, "Title");
  img = mlx_new_image(mlx, 128, 128);
  if (!img)
	ft_error();
  mlx_loop(mlx);
  return (0);
}
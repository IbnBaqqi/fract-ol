/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:22:49 by sabdulba          #+#    #+#             */
/*   Updated: 2024/11/25 12:07:29 by sabdulba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

// int main(void)
// {
//   mlx_t	*mlx;
//   mlx_image_t* img;
//   //int	window;
  
//   mlx = mlx_init(500, 500, "fract-ol", true);
//   if (!mlx)
//   	ft_error();
//   //window = mlx_new_window(mlx, 1000, 1000, "Title");
//   img = mlx_new_image(mlx, 128, 128);
//   if (!img)
//   	ft_error();
//   mlx_image_to_window(mlx, img, 0, 0);
//   mlx_put_pixel(img, 20, 20, 0x00FF0000);
  
//   mlx_loop(mlx);
//   mlx_terminate(mlx);
//   return (0);
// }

#include <stdlib.h>
#include <string.h>

// Bytes Per Pixel. Since each pixel is represented as an integer, it will be four bytes for four channels.
#define BPP sizeof(int32_t)

int32_t	main(void)
{
    mlx_t* mlx = mlx_init(600, 600, "MLX42", true);
    
    if (!mlx) exit(EXIT_FAILURE);

    mlx_image_t* img = mlx_new_image(mlx, 128, 128);

    memset(img->pixels, 255, img->width * img->height * BPP);

    // Draw the image at coordinate (0, 0).
    mlx_image_to_window(mlx, img, 0, 0);
 
    mlx_loop(mlx);
    mlx_terminate(mlx);

    return (EXIT_SUCCESS);
}

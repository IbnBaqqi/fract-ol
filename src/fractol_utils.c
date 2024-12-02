/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:04:00 by sabdulba          #+#    #+#             */
/*   Updated: 2024/12/02 12:48:07 by sabdulba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_error(void)
{
	ft_printf("Error occured");
	//ft_putstr_fd("Error occured", 1);
}

double scale(double nb, double min_n, double max_n, double min, double max)
{
  return ((max_n - min_n) * (nb - min) / (max - min) + min_n);
}
/* uint32_t hsv_to_rgb(double h, double s, double v)
{
    double c = v * s;
    double x = c * (1 - fabs(fmod(h / 60.0, 2) - 1));
    double m = v - c;
    double r, g, b;

    if (h < 60) { r = c; g = x; b = 0; }
    else if (h < 120) { r = x; g = c; b = 0; }
    else if (h < 180) { r = 0; g = c; b = x; }
    else if (h < 240) { r = 0; g = x; b = c; }
    else if (h < 300) { r = x; g = 0; b = c; }
    else { r = c; g = 0; b = x; }

    uint8_t red = (uint8_t)((r + m) * 255);
    uint8_t green = (uint8_t)((g + m) * 255);
    uint8_t blue = (uint8_t)((b + m) * 255);

    return (red << 24) | (green << 16) | (blue << 8) | 255; // ARGB format
} */

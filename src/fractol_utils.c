/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:04:00 by sabdulba          #+#    #+#             */
/*   Updated: 2024/12/02 21:54:36 by sabdulba         ###   ########.fr       */
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

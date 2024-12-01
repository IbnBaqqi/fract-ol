/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:04:00 by sabdulba          #+#    #+#             */
/*   Updated: 2024/12/01 18:28:19 by sabdulba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_error(void)
{
	ft_printf("Error occured");
	//ft_putstr_fd("Error occured", 1);
}
//n - new, o - old
double scale(double nb, double min_n, double max_n, double o_min, double o_max)
{
  return ((max_n - min_n) * (nb - o_min) / (o_max - o_min) + min_n);
}

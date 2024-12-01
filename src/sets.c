/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:07:00 by sabdulba          #+#    #+#             */
/*   Updated: 2024/12/01 19:50:50 by sabdulba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

//real = a^2 - b^2
//complex = 2ab(i)
//f(z) = z^2 + C ...where c is (a + bi) also (x + yi)
//x .. constant real in the plane
//y .. constant imaginary in the plane
//returns n (numbers of iteration)
int	mandelbrot(double x, double y, t_fractal *frac)
{
    double	a;
    double	b;
	double	real;
	double	complex;
    int		n;

	n = 0;
	a = x;
	b = y;
    while (n < frac->max_iterations) {
        real = a * a - b * b;
        complex = 2 * a * b;
        a = real + x;
        b = complex + y;

        if (a * a + b * b > 16)
            break;
        n++;
    }
    return (n);
}

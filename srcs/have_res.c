/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_res.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:19:21 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/24 15:27:29 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		exch(double *a, double *b)
{
	double buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
}

int			have_res(double num[3], double *t, double *t1)
{
	double disc;
	double k;

	disc = pow(num[1], 2) - 4 * num[0] * num[2];
	if (disc < 0)
		return (0);
	else if (disc == 0)
	{
		*t = -0.5 * num[1] / num[0];
		*t1 = -0.5 * num[1] / num[0];
	}
	else
	{
		if (num[1] > 0)
			k = -1 * (num[1] + sqrt(disc)) / 2;
		else
			k = -1 * (num[1] - sqrt(disc)) / 2;
		*t = k / num[0];
		*t1 = num[2] / k;
	}
	if (*t > *t1)
		exch(t, t1);
	return (1);
}

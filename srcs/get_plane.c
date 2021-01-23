/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:14:06 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/23 19:20:29 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	calc_pl(t_par *par, t_coord d, t_coord n)
{
	par->a = n.x;
	par->b = n.y;
	par->c = n.z;
	par->d = -(n.x * d.x + n.y * d.y + n.z * d.z);
}

int		is_in_plane(t_par par, t_coord d)
{
	if ((par.a * d.x + par.b * d.y + par.c * d.z + par.d) == 0)
		return (1);
	return (0);
}

t_coord	get_proec(t_coord d, t_coord dp, t_coord *n, double *dist)
{
	t_coord	cs;

	cs = dots_to_vec(d, dp);
	if (vec_scal_vec(cs, *n) < 0)
		*n = vec_mult_scal(*n, -1);
	vec_norm(n);
	*dist = vec_scal_vec(cs, *n);
	return (vec_sum(d, vec_mult_scal(*n, *dist)));
}

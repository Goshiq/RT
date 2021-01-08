/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_vector_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 08:46:24 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/07 14:53:34 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_coord	dots_to_vec(t_coord a, t_coord b)
{
	t_coord	ans;

	ans.x = b.x - a.x;
	ans.y = b.y - a.y;
	ans.z = b.z - a.z;
	return (ans);
}

void	vec_norm(t_coord *v)
{
	*v = vec_div_scal(*v, vec_len(*v));	
}

t_coord	vec_mult_vec(t_coord v1, t_coord v2)
{
	t_coord	ans;

	ans.x = v1.y * v2.z - v1.z * v2.y;
	ans.y = v1.z * v2.x - v1.x * v2.z;
	ans.z = v1.x * v2.y - v1.y * v2.x;
	return (ans);
}

double	vec_scal_vec(t_coord v1, t_coord v2)
{
	double	ans;

	ans = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (ans);
}

t_coord	pnts_to_vec(double x, double y, double z)
{
	t_coord	ans;

	ans.x = x;
	ans.y = y;
	ans.z = z;
	return (ans);
}

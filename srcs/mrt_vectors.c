/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_vectors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 08:46:24 by jmogo             #+#    #+#             */
/*   Updated: 2020/12/23 11:18:31 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vec_len(t_coord v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}

t_coord	vec_mult_scal(t_coord v, double d)
{
	t_coord	ans;

	ans.x = v.x * d;
	ans.y = v.y * d;
	ans.z = v.z * d;
	return (ans);
}

t_coord	vec_div_scal(t_coord v, double d)
{
	t_coord	ans;

	ans.x = v.x / d;
	ans.y = v.y / d;
	ans.z = v.z / d;
	return (ans);
}

t_coord	vec_sum(t_coord v1, t_coord v2)
{
	t_coord	ans;

	ans.x = v1.x + v2.x;
	ans.y = v1.y + v2.y;
	ans.z = v1.z + v2.z;
	return (ans);
}

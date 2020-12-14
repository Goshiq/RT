/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_orient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 09:01:39 by jmogo             #+#    #+#             */
/*   Updated: 2020/12/08 10:14:06 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_orient(t_coord *c, char *s)
{
	char	**sp;
	float	f;

	if (!(sp = ft_split(s, ',')))
		return (-1);
	if (!sp[0] || !sp[1] || !sp[2] || sp[3])
		return (-1);
	f = ft_atof(sp[0]);
	if (f < -1 || f > 1)
		return (-1);
	c->x = f;
	f = ft_atof(sp[1]);
	if (f < -1 || f > 1)
		return (-1);
	c->y = f;
	f = ft_atof(sp[2]);
	if (f < -1 || f > 1)
		return (-1);
	c->z = f;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_orient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 09:01:39 by jmogo             #+#    #+#             */
/*   Updated: 2020/12/29 23:08:20 by jmogo            ###   ########.fr       */
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
		return (free_split(sp));
	f = ft_atof(sp[0]);
	c->x = f;
	f = ft_atof(sp[1]);
	c->y = f;
	f = ft_atof(sp[2]);
	free_split(sp);
	c->z = f;
	if (vec_len(*c) != 1)
	{
		ft_putstr("Warning: orientation vector [");
		ft_putstr(s);
		ft_putstr("] was non-normalized!\n");
		vec_norm(c);
	}
	return (0);
}

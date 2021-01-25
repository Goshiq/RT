/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_coord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:33:56 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/25 19:40:44 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_coord(t_coord *c, char *s, t_scene **t)
{
	char	**sp;

	if (!(sp = ft_split(s, ',')))
		return (-1);
	if (!sp[0] || !sp[1] || !sp[2] || sp[3])
		return (free_split(sp));
	c->x = ft_atof(sp[0], t);
	c->y = ft_atof(sp[1], t);
	c->z = ft_atof(sp[2], t);
	free_split(sp);
	return (0);
}

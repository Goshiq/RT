/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_fov.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 10:18:04 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/25 19:50:28 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_fov(int *fov, char *s, t_scene **t)
{
	char	*tmp;

	tmp = s;
	if (check_atoi(s))
		return (-1);
	*fov = ft_atoi(s, t);
	if (*fov < 0 || *fov > 180)
		return (-1);
	return (0);
}

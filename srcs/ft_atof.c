/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 11:54:50 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/25 20:00:18 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_atof(char *s, t_scene **t)
{
	double	ans;
	int		f;
	int		minus;
	char	*dot;

	ans = 0.0;
	minus = 1;
	if (s[0] == '-')
		minus = -1;
	f = ft_atoi(s, t);
	ans += f;
	f = 0;
	dot = ft_strchr(s, '.');
	if (dot && ft_isdigit(*(dot + 1)))
		f = ft_atoi(dot + 1, t);
	if (f)
	{
		if (ans < 0)
			ans -= (f / pow(10, ft_numlen(f)));
		else if (!ans && minus < 0)
			ans -= (f / pow(10, ft_numlen(f)));
		else
			ans += (f / pow(10, ft_numlen(f)));
	}
	return (ans);
}

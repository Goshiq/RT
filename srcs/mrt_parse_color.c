/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:45:12 by jmogo             #+#    #+#             */
/*   Updated: 2020/12/18 11:45:46 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_color(char *s)
{
	int		ans;
	int		tmp;
	char	**clrs;

	if (!(clrs = ft_split(s, ',')))
		return (-1);
	if (!clrs[0] || !clrs[1] || !clrs[2] || ft_strlen(s) > 11)
		return (free_split(clrs));
	tmp = ft_atoi(clrs[0]);
	if (tmp < 0 || tmp > 255)
		return (free_split(clrs));
	ans = tmp << 16;
	tmp = ft_atoi(clrs[1]);
	if (tmp < 0 || tmp > 255)
		return (free_split(clrs));
	ans += tmp << 8;
	tmp = ft_atoi(clrs[2]);
	if (tmp < 0 || tmp > 255)
		return (free_split(clrs));
	ans += tmp;
	if (clrs[3])
		return (free_split(clrs));
	free_split(clrs);
	return (ans);
}

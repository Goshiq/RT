/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:45:12 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/25 19:39:25 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_clr	err_col(char **str)
{
	t_clr	ans;

	ans.r = -1;
	free_split(str);
	return (ans);
}

t_clr	parse_color(char *s, float br, t_scene **t)
{
	t_clr	ans;
	int		tmp;
	char	**clrs;

	ans.r = -1;
	if (!(clrs = ft_split(s, ',')))
		return (ans);
	if (!clrs[0] || !clrs[1] || !clrs[2] || ft_strlen(s) > 11)
		return (err_col(clrs));
	tmp = ft_atoi(clrs[0], t);
	if (tmp < 0 || tmp > 255)
		return (err_col(clrs));
	ans.r = tmp * br;
	tmp = ft_atoi(clrs[1], t);
	if (tmp < 0 || tmp > 255)
		return (err_col(clrs));
	ans.g = tmp * br;
	tmp = ft_atoi(clrs[2], t);
	if (tmp < 0 || tmp > 255)
		return (err_col(clrs));
	ans.b = tmp * br;
	if (clrs[3])
		return (err_col(clrs));
	free_split(clrs);
	return (ans);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_doerr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:25:09 by jmogo             #+#    #+#             */
/*   Updated: 2020/12/09 13:43:12 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mrt_doerr(char *s, char *str, t_scene **t)
{
	(void)t;
	if (s)
	{
		ft_putstr("Error\n");
		ft_putstr(s);
	}
	if (str)
		ft_putstr(str);
	if (!s)
		exit(0);
	exit(-1);
}

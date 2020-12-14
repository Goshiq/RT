/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 12:05:47 by jmogo             #+#    #+#             */
/*   Updated: 2020/12/08 12:31:24 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_strcmp(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (1);
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_putstr(char *s)
{
	if (!s)
		return (1);
	while (*s++)
		ft_putchar(*(s - 1));
	return (0);
}

int		check_atoi(char *s)
{
	while (*s++)
		if (!(ft_isdigit(*(s - 1))))
			return (1);
	return (0);
}

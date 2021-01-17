/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_doerr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:25:09 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/17 15:50:44 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_lst(t_scene **t)
{
	t_lst	*prev;
	t_lst	*tofree;

	prev = (*t)->ptr;
	while (prev->next)
	{
		tofree = prev;
		prev = prev->next;
		free(tofree->ptr);
		free(tofree);
	}
	if (prev)
	{
		free(prev->ptr);
		free(prev);
	}
}

int		mrt_doerr(char *s, char *str, t_scene **t)
{
	if (t)
	{
		close((*t)->fd);
		free_lst(t);
	}
	if (s)
	{
		ft_putstr("Error\n");
		ft_putstr(s);
		if (str)
			ft_putstr(str);
	}
	if (!s)
		exit(0);
	exit(-1);
}

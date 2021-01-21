/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:40:27 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/21 12:02:11 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	conv(int fd, int num, int size)
{
	write(fd, &num, size);
}

void	conv_s(int fd, short num, int size)
{
	write(fd, &num, size);
}

void	fill_bmp(t_scene **t, int fd)
{
	write(fd, "BM", 2);
	conv(fd, 54 + sizeof(int) * (*t)->res->x * (*t)->res->y, sizeof(int));
	conv(fd, 0, sizeof(int));
	conv(fd, 54, sizeof(int));
	conv(fd, 40, sizeof(int));
	conv(fd, (*t)->res->x, sizeof(int));
	conv(fd, -(*t)->res->y, sizeof(int));
	conv_s(fd, 1, sizeof(short));
	conv_s(fd, (short)(*t)->img->bits, sizeof(short));
	conv(fd, 0, sizeof(int));
	conv(fd, (*t)->res->x * (*t)->res->y, sizeof(int));
	conv(fd, 1000, sizeof(int));
	conv(fd, 1000, sizeof(int));
	conv(fd, 0, sizeof(int));
	conv(fd, 0, sizeof(int));
	write(fd, (*t)->img->adr, (*t)->res->x * (*t)->res->y * sizeof(int));
}

void	manage_loop(t_scene **t, int save)
{
	if (!save)
	{
		ft_putstr("Done\n");
		mlx_key_hook((*t)->m_win, &key_hook, t);
		mlx_hook((*t)->m_win, 17, 0, finish_it, t);
		mlx_loop((*t)->m_mlx);
	}
	else
	{
		fill_bmp(t, (*t)->img->fd);
		ft_putstr("Done\n");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:40:27 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/20 16:02:40 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/*
int		fill_bmp(t_scene **t, t_bmp *bmp, int fd)
{
#define BM_INFO_SIZE 40
#define BM_HEAD_SIZE 14
#define RESERVED 0
#define OFFSET 54
#define PLANES 1
#define COMPRESSION 0
#define PIXEL_PER_METER 1000
#define COLOR_TABLE 0

	write(fd, "BM", 2);
	write(fd, &(54 + sizeof(int) * (*t)->res.x * (*t)->res.y), sizeof(int));
	write(fd, &(0), sizeof(int));
	write(fd, &(54), sizeof(int));
	write(fd, &(40), sizeof(int));
	write(fd, &((*t)->res.x), sizeof(int));
	write(fd, -(*t)->res.y, sizeof(int));
	write(fd, 1, sizeof(int));
	write(fd, 24, sizeof(int));
	write(fd, 0, sizeof(int));
	write(fd, (*t)->res.x * (*t)->res.y, sizeof(int));
	write(fd, 1000, sizeof(int));
	write(fd, 1000, sizeof(int));
	write(fd, 0, sizeof(int));
	write(fd, 0, sizeof(int));
	write(fd, , (*t)->rex.x * (*t)->res.y, sizeof(int));
}
*/
void	manage_loop(t_scene **t, int save)
{
	int	fd;

	if (!save)
	{
		ft_putstr("Done\n");
		mlx_key_hook((*t)->m_win, &key_hook, t);
		mlx_hook((*t)->m_win, 17, 0, finish_it, t);
		mlx_loop((*t)->m_mlx);
	}
	else
	{
		if (0 >= (fd = creat(SCREEN, 00644)))
		{
			ft_putstr("Can't create the screenshot: ");
			ft_putstr(SCREEN);
			ft_putstr("\n");
		}
		else
			;
			//fill_bmp(t, fd);
	}
}

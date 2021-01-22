/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:42:57 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/22 21:30:24 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		check_corners(t_coord n, t_coord d, t_coord c1, t_coord c2)
{
	double	ans;

	ans = (d.x - c1.x) * n.x + (d.y - c1.y) * n.y + (d.z - c1.z) * n.z;
	ans *= (c2.x - c1.x) * n.x + (c2.y - c1.y) * n.y + (c2.z - c1.z) * n.z;
	if (ans >= 0)
		return (1);
	return (0);
}

int		in_sq(t_coord p, t_sq *sq)
{
	t_coord	n_pl;

	n_pl = vec_mult_vec(dots_to_vec(sq->corns[0], sq->corns[1]), sq->n_crd);
	if (!check_corners(n_pl, p, sq->corns[0], sq->corns[2]))
		return (0);
	n_pl = vec_mult_vec(dots_to_vec(sq->corns[1], sq->corns[2]), sq->n_crd);
	if (!check_corners(n_pl, p, sq->corns[1], sq->corns[3]))
		return (0);
	n_pl = vec_mult_vec(dots_to_vec(sq->corns[2], sq->corns[3]), sq->n_crd);
	if (!check_corners(n_pl, p, sq->corns[2], sq->corns[0]))
		return (0);
	n_pl = vec_mult_vec(dots_to_vec(sq->corns[3], sq->corns[0]), sq->n_crd);
	if (!check_corners(n_pl, p, sq->corns[3], sq->corns[1]))
		return (0);
	return (1);
}

void	get_corners(t_sq *sq)
{
	double	side;
	t_coord	tmp;
	t_coord	tmp_x;
	t_coord	tmp_y;

	side = sq->side / 2;
	tmp_x = vec_mult_vec(sq->n_crd, pnts_to_vec(0, 0, 1));
	if (tmp_x.x == 0 && tmp_x.y == 0 && tmp_x.z == 0)
		tmp_x = pnts_to_vec(1, 0, 0);
	vec_norm(&tmp_x);
	tmp_y = vec_mult_vec(sq->n_crd, tmp_x);
	vec_norm(&tmp_y);
	tmp = vec_sum(sq->c_crd, vec_mult_scal(tmp_x, -side));
	sq->corns[0] = vec_sum(tmp, vec_mult_scal(tmp_y, -side));
	sq->corns[1] = vec_sum(tmp, vec_mult_scal(tmp_y, side));
	tmp = vec_sum(sq->c_crd, vec_mult_scal(tmp_x, side));
	sq->corns[2] = vec_sum(tmp, vec_mult_scal(tmp_y, side));
	sq->corns[3] = vec_sum(tmp, vec_mult_scal(tmp_y, -side));
}

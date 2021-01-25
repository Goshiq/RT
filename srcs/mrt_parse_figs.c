/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_figs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:41:13 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/25 19:48:52 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_cy(t_scene **t, char **s)
{
	t_cy	*cy;
	float	f;
	t_clr	clr;

	if (!s[1] || !s[2] || !s[3] || !s[4] || !s[5] || s[6])
		mrt_doerr("Wrong input cylinder format:\n", s[1], t);
	mrt_malloc((void **)&cy, CYL, t);
	if (0 > (parse_coord(&(cy->c_crd), s[1], t)))
		mrt_doerr("Wrong cylinder's coordinates format:\n", s[1], t);
	if (0 > (parse_orient(&(cy->n_crd), s[2], t)))
		mrt_doerr("Wrong cylinder's orientation format:\n", s[2], t);
	f = atof(s[3]);
	if (f < 0)
		mrt_doerr("Wrong cylinder's diameter format:\n", s[3], t);
	cy->diam = f;
	f = atof(s[4]);
	if (f < 0)
		mrt_doerr("Wrong cylinder's height format:\n", s[4], t);
	cy->height = f;
	clr = parse_color(s[5], 1, t);
	if (0 > clr.r)
		mrt_doerr("Wrong cylinder color:\n", s[5], t);
	cy->clr = clr;
	cy->top = vec_sum(cy->c_crd, vec_mult_scal(cy->n_crd, f));
	ft_figadd_back(t, cy, CY);
}

void	parse_pl(t_scene **t, char **s)
{
	t_pl	*pl;
	t_clr	clr;

	if (!s[1] || !s[2] || !s[3] || s[4])
		mrt_doerr("Wrong input plane format:\n", s[1], t);
	mrt_malloc((void **)&pl, PLA, t);
	if (0 > (parse_coord(&(pl->c_crd), s[1], t)))
		mrt_doerr("Wrong plane's coordinates format:\n", s[1], t);
	if (0 > (parse_orient(&(pl->n_crd), s[2], t)))
		mrt_doerr("Wrong plane's orientation format:\n", s[2], t);
	clr = parse_color(s[3], 1, t);
	if (0 > clr.r)
		mrt_doerr("Wrong plane color:\n", s[3], t);
	pl->clr = clr;
	ft_figadd_back(t, pl, PL);
}

void	parse_sp(t_scene **t, char **s)
{
	t_sp	*sp;
	float	f;
	t_clr	clr;

	if (!s[1] || !s[2] || !s[3] || s[4])
		mrt_doerr("Wrong input sphere format:\n", s[1], t);
	mrt_malloc((void **)&sp, SPH, t);
	if (0 > (parse_coord(&(sp->c_crd), s[1], t)))
		mrt_doerr("Wrong sphere's coordinates format:\n", s[1], t);
	f = atof(s[2]);
	if (f < 0)
		mrt_doerr("Wrong sphere's diameter format:\n", s[2], t);
	sp->diam = f;
	clr = parse_color(s[3], 1, t);
	if (0 > clr.r)
		mrt_doerr("Wrong sphere color:\n", s[3], t);
	sp->clr = clr;
	ft_figadd_back(t, sp, SP);
}

void	parse_sq(t_scene **t, char **s)
{
	t_sq	*sq;
	float	f;
	t_clr	clr;

	if (!s[1] || !s[2] || !s[3] || !s[4] || s[5])
		mrt_doerr("Wrong input square format:\n", s[1], t);
	mrt_malloc((void **)&sq, SQU, t);
	if (0 > (parse_coord(&(sq->c_crd), s[1], t)))
		mrt_doerr("Wrong square's coordinates format:\n", s[1], t);
	if (0 > (parse_orient(&(sq->n_crd), s[2], t)))
		mrt_doerr("Wrong square's orientation format:\n", s[2], t);
	f = atof(s[3]);
	if (f < 0)
		mrt_doerr("Wrong square's side format:\n", s[3], t);
	sq->side = f;
	clr = parse_color(s[4], 1, t);
	if (0 > clr.r)
		mrt_doerr("Wrong square color:\n", s[4], t);
	sq->clr = clr;
	get_corners(sq);
	ft_figadd_back(t, sq, SQ);
}

void	parse_tr(t_scene **t, char **s)
{
	t_tr	*tr;
	t_clr	clr;

	if (!s[1] || !s[2] || !s[3] || !s[4] || s[5])
		mrt_doerr("Wrong input triangle format:\n", s[1], t);
	mrt_malloc((void **)&tr, TRI, t);
	if (0 > (parse_coord(&(tr->c_crd), s[1], t)))
		mrt_doerr("Wrong triangle's coordinate format:\n", s[1], t);
	if (0 > (parse_coord(&(tr->s_crd), s[2], t)))
		mrt_doerr("Wrong triangle's coordinate format:\n", s[2], t);
	if (0 > (parse_coord(&(tr->t_crd), s[3], t)))
		mrt_doerr("Wrong triangle's coordinate format:\n", s[3], t);
	clr = parse_color(s[4], 1, t);
	if (0 > clr.r)
		mrt_doerr("Wrong triangle color:\n", s[4], t);
	tr->clr = clr;
	tr->n_crd = find_n_tr(tr);
	ft_figadd_back(t, tr, TR);
}

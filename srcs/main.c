/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 12:19:51 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/22 11:29:33 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		check_figs(char *s, t_type *type)
{
	if (!ft_strcmp(s, "cy"))
		*type = CY;
	else if (!ft_strcmp(s, "sp"))
		*type = SP;
	else if (!ft_strcmp(s, "tr"))
		*type = TR;
	else if (!ft_strcmp(s, "pl"))
		*type = PL;
	else if (!ft_strcmp(s, "sq"))
		*type = SQ;
	else
		return (0);
	return (1);
}

void	malloc_scene(t_scene **t)
{
	mrt_malloc((void **)t, SC, t);
	mrt_malloc((void **)&((*t)->res), RES, t);
	mrt_malloc((void **)&((*t)->figs), FIGS, t);
	mrt_malloc((void **)&((*t)->cams), CAMS, t);
	mrt_malloc((void **)&((*t)->lghts), LGHTS, t);
	mrt_malloc((void **)&((*t)->alght), LGHTS, t);
}

int		fill_struct(char *s, t_scene **t)
{
	char	**splitted;
	t_type	type;

	type = DEF;
	if (!(splitted = ft_split(s, ' ')))
		return (-1);
	if (!splitted[0])
		return (0);
	if (!(ft_strcmp(splitted[0], "R")))
		set_res(t, splitted);
	else if (!(ft_strcmp(splitted[0], "A")))
		set_alght(t, splitted);
	else if (!(ft_strcmp(splitted[0], "c")))
		add_cam(t, splitted);
	else if (!(ft_strcmp(splitted[0], "l")))
		add_lght(t, splitted);
	else if (check_figs(splitted[0], &type))
		add_fig(t, splitted, type);
	else
		mrt_doerr("Wrong type identifier:\n", s, t);
	free_split(splitted);
	return (0);
}

int		mrt_parse_scene(char *s, int save)
{
	int		fd;
	char	*line;
	int		check;
	t_scene	*sc;

	malloc_scene(&sc);
	if (!(fd = open(s, O_RDONLY)))
		mrt_doerr("Can't open the sc file:\n", s, 0x0);
	sc->fd = fd;
	while ((check = get_next_line(fd, &line)))
	{
		if (check < 0)
			mrt_doerr("Can't read the sc file:\n", s, 0x0);
		if (fill_struct(line, &sc))
			mrt_doerr("Invalid sc file:\n", s, &sc);
		free(line);
	}
	validate_scene(sc);
	init_win_img(sc, save);
	mrt_paint(&sc, save);
	mrt_doerr(0x0, 0x0, &sc);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 2 && !check_file(argv[1]))
		return (mrt_parse_scene(argv[1], 0));
	else if (argc == 3 && !check_file(argv[1]) && !ft_strcmp(argv[2], "--save"))
		return (mrt_parse_scene(argv[1], 1));
	mrt_doerr("Incorrect arguments\n", 0x0, 0x0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 12:19:51 by jmogo             #+#    #+#             */
/*   Updated: 2020/12/23 07:52:45 by jmogo            ###   ########.fr       */
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

void	init_scene(t_scene **t)
{
	mrt_malloc((void **)t, SC, t);
	mrt_malloc((void **)&((*t)->res), RES, t);
	mrt_malloc((void **)&((*t)->figs), FIGS, t);
	mrt_malloc((void **)&((*t)->cams), CAMS, t);
	mrt_malloc((void **)&((*t)->lghts), LGHTS, t);
	mrt_malloc((void **)&((*t)->alght), LGHTS, t);
	(*t)->m_mlx = mlx_init();
	init_res(&((*t)->res));
	init_alght(&((*t)->alght));
	init_cams(&((*t)->cams));
	init_lghts(&((*t)->lghts));
	init_figs(&((*t)->figs));
}

int		fill_struct(char *s, t_scene **t)
{
	char	**splitted;
	int		ans;
	t_type	type;

	ans = 0;
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
	return (ans);
}

int		mrt_parse_scene(char *s)
{
	int		fd;
	char	*line;
	int		check;
	t_scene	*scene;

	init_scene(&scene);
	if (!(fd = open(s, O_RDONLY)))
		mrt_doerr("Can't open the scene file:\n", s, 0x0);
	while ((check = get_next_line(fd, &line)))
	{
		if (check < 0)
			mrt_doerr("Can't read the scene file:\n", s, 0x0);
		if (fill_struct(line, &scene))
			mrt_doerr("Invalid scene file:\n", s, &scene);
		free(line);
	}
	close(fd);
	mrt_paint(&scene);
	mrt_doerr(0x0, 0x0, &scene);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		return (mrt_parse_scene(argv[1]));
	else if (argc == 3 && !ft_strcmp(argv[2], "--save"))
		return (mrt_saveimg(argv[1]));
	mrt_doerr("Wrong number of arguments\n", 0x0, 0x0);
	return (0);
}

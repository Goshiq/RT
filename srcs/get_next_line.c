/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:16:18 by jmogo             #+#    #+#             */
/*   Updated: 2020/12/07 13:25:02 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	ft_spec(char **arr, char *npos, char **line)
{
	char	*tmp;

	tmp = *arr;
	*npos = '\0';
	*line = ft_strdup(*arr);
	*arr = ft_strdup((npos + 1));
	free(tmp);
	return (1);
}

static int	ft_do_arr(char **arr, char **line, size_t got)
{
	char	*npos;

	if (!got && !(*arr))
	{
		*line = ft_strdup("");
		return (0);
	}
	if (got < 0)
		return (free_str(*arr, 0x0));
	if ((npos = ft_strchr(*arr, '\n')))
		return (ft_spec(arr, npos, line));
	else if ((npos = ft_strchr(*arr, '\0')))
	{
		*line = ft_strdup(*arr);
		free(*arr);
		*arr = 0x0;
	}
	return (0);
}

static int	check(int fd, char **line, char **s)
{
	int	got;

	if (fd < 0 || fd > 1025 || !line)
		return (1);
	if (0x0 == (*s = malloc(sizeof(char) * (2))))
		return (1);
	got = read(fd, *s, 0);
	if (got < 0)
		return (free_str(*s, 0x0));
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*arr[1025];
	char		*str;
	int			got;

	str = 0x0;
	if (check(fd, line, &str))
		return (-1);
	while (0 < (got = read(fd, str, 1)))
	{
		str[got] = '\0';
		if (!(arr[fd] = ft_strjoin(arr[fd], str)))
			return (free_str(arr[fd], str));
		if ((ft_strchr(arr[fd], '\n')))
			break ;
	}
	free(str);
	str = 0x0;
	return (ft_do_arr(&arr[fd], line, got));
}

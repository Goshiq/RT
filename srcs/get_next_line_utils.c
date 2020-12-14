/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:16:02 by jmogo             #+#    #+#             */
/*   Updated: 2020/12/06 12:51:27 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

size_t	ft_strlen(char *str)
{
	size_t	ans;

	ans = 0;
	while (*(str + ans))
		ans++;
	return (ans);
}

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0x0);
	while (*(s + i))
	{
		if (*(s + i) == c)
			return (s + i);
		i++;
	}
	if (c == '\0')
		return (s + i);
	return (0x0);
}

char	*ft_strdup(char *s)
{
	size_t	len;
	size_t	i;
	char	*ans;

	i = 0;
	if (!s)
		return (0x0);
	len = ft_strlen(s);
	if (!(ans = malloc(sizeof(char) * (len + 1))))
		return (0x0);
	*(ans + len) = '\0';
	while (i < len)
	{
		*(ans + i) = *(s + i);
		i++;
	}
	return (ans);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ans;
	char	*tmp;
	char	*tmp_ans;
	size_t	len;

	if (!s1)
		return ((ans = ft_strdup(s2)));
	if (!s2)
		return ((ans = ft_strdup(s1)));
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(ans = malloc(sizeof(char) * (len + 1))))
		return (0x0);
	*(ans + len) = '\0';
	tmp_ans = ans;
	tmp = s1;
	while (*(tmp++))
		*(ans++) = *(tmp - 1);
	free(s1);
	tmp = s2;
	while (*(tmp++))
		*(ans++) = *(tmp - 1);
	return (tmp_ans);
}

int		free_str(char *str, char *arr)
{
	if (str)
		free(str);
	if (arr)
		free(arr);
	return (-1);
}

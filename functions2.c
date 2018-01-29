/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpene <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 09:44:12 by cpene             #+#    #+#             */
/*   Updated: 2017/09/06 21:08:00 by cpene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	*ft_append(char *s1, char *s2)
{
	char	*result;
	int		len;
	int		i;

	len = ft_strlen(s1);
	result = (char*)malloc(sizeof(char) * (len + 2));
	i = 0;
	while (i < len)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = s2[0];
	result[i + 1] = '\0';
	return (result);
}

char	**init_mat(int lines)
{
	char	*buf;
	char	**result;
	int		ret;
	int		i;

	result = malloc(sizeof(char*) * (lines + 1));
	buf = malloc(sizeof(char) * 2);
	i = 0;
	result[i] = malloc(sizeof(char));
	while ((ret = read(0, buf, 1)))
	{
		if (i == lines)
		{
			while (ret)
				ret = read(0, buf, 1);
			return (NULL);
		}
		else if (buf[0] == '\n')
			result[++i] = malloc(sizeof(char));
		else
			result[i] = ft_append(result[i], buf);
	}
	result[i] = NULL;
	return (result);
}

char	*init_legend(void)
{
	char	*buf;
	char	*result;
	int		ret;

	result = NULL;
	buf = (char*)malloc(sizeof(char) * 2);
	result = (char*)malloc(sizeof(char) * 16);
	ret = read(0, buf, 1);
	if (buf[0] < '0' || buf[0] > '9')
	{
		while (ret)
			ret = read(0, buf, 1);
		return (NULL);
	}
	while (buf[0] != '\n')
	{
		result = ft_append(result, buf);
		ret = read(0, buf, 1);
	}
	return (result);
}

char	**init_mat_2(int lines, char *str)
{
	char	*buf;
	char	**result;
	int		ret;
	int		i;
	int		fd;

	result = malloc(sizeof(char*) * (lines + 1));
	buf = malloc(sizeof(char) * 2);
	i = 0;
	result[i] = malloc(sizeof(char));
	fd = open(str, O_RDONLY);
	ret = read(fd, buf, 1);
	while (buf[0] != '\n' && ret)
		ret = read(fd, buf, 1);
	if (buf[0] != '\n')
		return (NULL);
	while ((ret = read(fd, buf, 1)))
		if (i == lines)
			return (aux(ret, fd, buf));
		else if (buf[0] == '\n')
			result[++i] = malloc(sizeof(char));
		else
			result[i] = ft_append(result[i], buf);
	result[i] = NULL;
	return (result);
}

char	*init_legend_2(char *str)
{
	char	*buf;
	char	*result;
	int		ret;
	int		fd;

	result = NULL;
	buf = (char*)malloc(sizeof(char) * 2);
	result = (char*)malloc(sizeof(char) * 16);
	fd = open(str, O_RDONLY);
	ret = read(fd, buf, 1);
	if (buf[0] < '0' || buf[0] > '9')
	{
		while (ret)
			ret = read(fd, buf, 1);
		return (NULL);
	}
	while (buf[0] != '\n' && ret)
	{
		result = ft_append(result, buf);
		ret = read(fd, buf, 1);
	}
	if (buf[0] != '\n')
		return (NULL);
	close(fd);
	return (result);
}

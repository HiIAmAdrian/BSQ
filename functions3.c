/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpene <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 12:00:20 by cpene             #+#    #+#             */
/*   Updated: 2017/09/06 12:05:35 by cpene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	**aux(int ret, int fd, char *buf)
{
	while (ret)
		ret = read(fd, buf, 1);
	close(fd);
	return (NULL);
}

int		**d_init(char **mat, int *dim)
{
	int	**result;
	int	i;
	int	j;

	result = NULL;
	result = malloc(sizeof(int*) * (dim[0]));
	i = 0;
	while (mat[i])
	{
		j = 0;
		result[i] = malloc(sizeof(int) * (dim[1]));
		while (mat[i][j])
		{
			result[i][j] = 0;
			j++;
		}
		i++;
	}
	return (result);
}

int		minm(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

int		f_min(int **d, int i, int j)
{
	if (i == 0 || j == 0)
		return (0);
	else
		return (minm(d[i][j - 1], d[i - 1][j], d[i - 1][j - 1]));
}

int		function2(int **d, char **mat, int *dim, char *pat)
{
	int	i;
	int	j;
	int	maxm;

	maxm = 0;
	i = 0;
	while (i < dim[0])
	{
		j = 0;
		while (j < dim[1])
		{
			if (mat[i][j] != pat[1])
			{
				d[i][j] = f_min(d, i, j) + 1;
				if (d[i][j] > maxm)
					maxm = d[i][j];
			}
			j++;
		}
		i++;
	}
	return (maxm);
}

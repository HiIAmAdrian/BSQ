/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpene <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 15:53:26 by cpene             #+#    #+#             */
/*   Updated: 2017/09/06 21:07:45 by cpene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		check1_2(char *leg)
{
	int	i;

	i = 0;
	while (leg[i] != '\n' && leg[i])
		i++;
	if (i < 4 || leg[0] == '0')
		return (-1);
	i -= 4;
	while (i >= 0)
	{
		if (leg[i] < '0' || leg[i] > '9')
			return (-1);
		i--;
	}
	return (0);
}

int		check1(char *leg, char **mat)
{
	int	last;

	last = 0;
	if (check1_2(leg) == (-1))
		return (-1);
	if (check2(leg, mat) == (-1))
		return (-1);
	return (check3(leg, mat));
}

int		check2(char *leg, char **mat)
{
	int		i;
	int		j;
	char	pat[2];

	i = 0;
	while (leg[i] != '\n' && leg[i])
		i++;
	if (leg[i - 1] == leg[i - 2] ||
			leg[i - 1] == leg[i - 3] || leg[i - 2] == leg[i - 3])
		return (-1);
	pat[1] = leg[i - 2];
	pat[0] = leg[i - 3];
	i = 0;
	while (mat[i])
	{
		j = 0;
		while (mat[i][j])
		{
			if (pat[0] != mat[i][j] && pat[1] != mat[i][j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int		check3_2(char **mat)
{
	int i;
	int j;
	int last;

	i = 0;
	last = 0;
	while (mat[i])
	{
		j = 0;
		while (mat[i][j])
			j++;
		if (last == 0)
		{
			last = j;
			j = 0;
		}
		else if (j != last)
		{
			return (-1);
		}
		i++;
	}
	return (i);
}

int		check3(char *leg, char **mat)
{
	int		i;
	int		j;
	int		lines;

	i = 0;
	while (leg[i] != '\n' && leg[i])
		i++;
	i -= 4;
	j = 0;
	lines = 0;
	while (j <= i)
		lines = lines * 10 + leg[j++] - '0';
	i = check3_2(mat);
	if (i == (-1) || i != lines)
		return (-1);
	return (0);
}

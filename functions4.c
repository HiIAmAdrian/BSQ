/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpene <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 12:00:30 by cpene             #+#    #+#             */
/*   Updated: 2017/09/06 21:08:08 by cpene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	function4(int *lim, char **mat, char a, int maxm)
{
	int	i;
	int	j;

	i = lim[0] - maxm + 1;
	while (i <= lim[0])
	{
		j = lim[1] - maxm + 1;
		while (j <= lim[1])
			mat[i][j++] = a;
		i++;
	}
	i = 0;
	while (mat[i])
	{
		j = 0;
		while (mat[i][j])
		{
			ft_putchar(mat[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	function3(char a, char **mat, int **d, int maxm)
{
	int	i;
	int	j;
	int	done;
	int	*lim;

	lim = malloc(sizeof(int) * 2);
	done = 0;
	i = 0;
	while (mat[i] && done == 0)
	{
		j = 0;
		while (mat[i][j] && done == 0)
		{
			if (d[i][j] == maxm)
				done = 1;
			j++;
		}
		i++;
	}
	lim[0] = i - 1;
	lim[1] = j - 1;
	function4(lim, mat, a, maxm);
}

void	function(char *leg, char **mat, int lines)
{
	int		**d;
	char	*pat;
	int		*dim;
	int		maxm;

	pat = malloc(sizeof(char) * 4);
	dim = malloc(sizeof(int) * 2);
	if (check1(leg, mat) == (-1))
	{
		ft_putstr_error("map error");
		return ;
	}
	dim[0] = lines;
	dim[1] = 0;
	while (mat[0][dim[1]])
		dim[1]++;
	pat[0] = leg[ft_strlen(leg) - 3];
	pat[1] = leg[ft_strlen(leg) - 2];
	pat[2] = leg[ft_strlen(leg) - 1];
	d = malloc(sizeof(int*) * (lines));
	d = d_init(mat, dim);
	maxm = function2(d, mat, dim, pat);
	function3(pat[2], mat, d, maxm);
}

int		aux_error(void)
{
	ft_putstr_error("map error");
	return (0);
}

int		bsq(char *str)
{
	char	*leg;
	char	**mat;
	int		lines;
	int		i;
	int		j;

	leg = malloc(sizeof(char));
	leg = init_legend_2(str);
	if (leg == NULL)
		return (aux_error());
	lines = 0;
	i = 0;
	while (leg[i + 4])
		i++;
	j = 0;
	while (j <= i)
		lines = lines * 10 + leg[j++] - '0';
	mat = malloc(sizeof(char*));
	mat = init_mat_2(lines, str);
	if (mat == NULL)
		return (aux_error());
	function(leg, mat, lines);
	return (0);
}

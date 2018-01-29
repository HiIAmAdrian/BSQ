/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpene <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 15:09:20 by cpene             #+#    #+#             */
/*   Updated: 2017/09/06 21:08:18 by cpene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		bsq_in(void)
{
	char	*leg;
	char	**mat;
	int		lines;
	int		i;
	int		j;

	leg = malloc(sizeof(char));
	leg = init_legend();
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
	mat = init_mat(lines);
	if (mat == NULL)
		return (aux_error());
	function(leg, mat, lines);
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;
	int		fd;

	i = 1;
	if (argc < 2)
	{
		bsq_in();
		return (0);
	}
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
			ft_putstr_error("map error");
		else
		{
			close(fd);
			bsq(argv[i]);
		}
		i++;
	}
	return (0);
}

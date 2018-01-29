/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpene <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 15:14:01 by cpene             #+#    #+#             */
/*   Updated: 2017/09/06 09:43:58 by cpene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puterror(char c)
{
	write(2, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putstr_error(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_puterror(str[i]);
		i++;
	}
	ft_puterror('\n');
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

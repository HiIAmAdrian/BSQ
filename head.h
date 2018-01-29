/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpene <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 15:12:10 by cpene             #+#    #+#             */
/*   Updated: 2017/09/06 18:52:22 by cpene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H

# define HEAD_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void	ft_putchar(char c);
void	ft_puterror(char c);
void	ft_putstr(char *str);
void	ft_putstr_error(char *str);
int		check1(char *leg, char **mat);
int		check2(char *leg, char **mat);
int		check3(char *leg, char **mat);
int		check1_2(char *leg);
int		check3_2(char **mat);
char	*ft_append(char *s1, char *s2);
char	**init_mat(int lines);
char	*init_legend(void);
char	**init_mat_2(int lines, char *str);
char	*init_legend_2(char *str);
int		ft_strlen(char *str);
char	**aux(int ret, int fd, char *buf);
int		**d_init(char **mat, int *dim);
int		minm(int a, int b, int c);
int		f_min(int **d, int i, int j);
int		function2(int **d, char **mat, int *dim, char *pat);
void	function4(int *lim, char **mat, char a, int maxm);
void	function3(char a, char **mat, int **d, int maxm);
void	function(char *leg, char **mat, int lines);
int		bsq(char *str);
int		bsq_in(void);
int		aux_error(void);

#endif

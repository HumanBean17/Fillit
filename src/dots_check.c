/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:26:35 by croxane           #+#    #+#             */
/*   Updated: 2019/05/31 17:38:32 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_set(t_flist *alst, char **field, int y_begin, int x_begin)
{
	int		i;
	t_flist	*tmp;

	i = 0;
	tmp = alst;
	while (i < 4)
	{
		field[(tmp->y)[i] + y_begin][(tmp->x)[i] + x_begin] = '1';
		i++;
	}
	ft_dot_field(alst, field, ft_strlen(field[0]));
}

int			ft_are_dots(t_flist *alst, char **field, int i, int j)
{
	if (((alst)->y[0] + i >= 0 && (alst)->x[0] + j >= 0) &&
			((alst)->y[1] + i >= 0 && (alst)->x[1] + j >= 0) &&
			((alst)->y[2] + i >= 0 && (alst)->x[2] + j >= 0) &&
			((alst)->y[3] + i >= 0 && (alst)->x[3] + j >= 0))
		if ((field[(alst->y)[0] + i][(alst->x)[0] + j] == '.' ||
					field[(alst->y)[0] + i][(alst->x)[0] + j] == alst->letter)
				&& (field[(alst->y)[1] + i][(alst->x)[1] + j] == '.' ||
				field[(alst->y)[1] + i][(alst->x)[1] + j] == alst->letter) &&
				(field[(alst->y)[2] + i][(alst->x)[2] + j] == '.' ||
				field[(alst->y)[2] + i][(alst->x)[2] + j] == alst->letter) &&
				(field[(alst->y)[3] + i][(alst->x)[3] + j] == '.' ||
				field[(alst->y)[3] + i][(alst->x)[3] + j] == alst->letter))
			return (1);
	return (0);
}

int			ft_fit(t_flist *alst, int count, int i, int j)
{
	if (i + (alst->y)[0] < count && i + (alst->y)[1] < count &&
			i + (alst->y)[2] < count && i + (alst->y)[3] < count &&
			j + (alst->x)[0] < count && j + (alst->x)[1] < count &&
			j + (alst->x)[2] < count && j + (alst->x)[3] < count)
		return (1);
	return (0);
}

void		ft_set_dots(t_clist **alst, t_flist *tmp, char **field, int count)
{
	int		i;
	int		j;

	((*alst)->a)[0] = 0;
	((*alst)->a)[1] = 0;
	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			if (field[i][j] == tmp->letter)
				field[i][j] = '.';
			j++;
		}
		i++;
	}
}

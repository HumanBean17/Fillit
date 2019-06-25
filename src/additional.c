/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:06:28 by lcrawn            #+#    #+#             */
/*   Updated: 2019/05/31 17:33:23 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_set_zero(t_clist **alst, char **field, int count)
{
	t_clist *tmp;

	tmp = *alst;
	if (tmp)
	{
		while (tmp)
		{
			(tmp->a)[0] = 0;
			(tmp->a)[1] = 0;
			tmp = tmp->next;
		}
	}
	ft_del_matrix(field, count);
}

void		ft_change_coords(t_clist **tmp, int i, int j, int count)
{
	((*tmp)->a)[0] = i;
	((*tmp)->a)[1] = j;
	if (j + 1 < count)
		((*tmp)->a)[1] += 1;
	else if (i + 1 < count)
	{
		((*tmp)->a)[1] = 0;
		((*tmp)->a)[0] += 1;
	}
}

int			ft_try_set(t_flist *alst, char **field, int count, int flag)
{
	t_clist			*tmp;
	static t_clist	*a;
	int				i;
	int				j;

	flag == 0 ? ft_set_zero(&a, field, count) : 0;
	flag == 2 ? ft_glist_del(&a) : 0;
	if (flag != 1)
		return (0);
	tmp = ft_find_list(&a, alst->letter, &ft_push_list_2);
	i = (tmp->a)[0] - 1;
	j = (tmp->a)[1] - 1;
	while (++i < count)
	{
		while (++j < count)
			if (ft_fit(alst, count, i, j) && ft_are_dots(alst, field, i, j))
			{
				ft_set(alst, field, i, j);
				ft_change_coords(&tmp, i, j, count);
				return (1);
			}
		j = -1;
	}
	ft_set_dots(&tmp, alst, field, count);
	return (0);
}

void		ft_dot_field(t_flist *tmp, char **field, int count)
{
	int c;
	int i;
	int j;

	c = 0;
	i = -1;
	while (++i < count)
	{
		j = -1;
		while (++j < count)
		{
			if (field[i][j] == tmp->letter)
			{
				c++;
				field[i][j] = '.';
			}
			if (c >= 4)
			{
				ft_fill_back(tmp, field, count);
				return ;
			}
		}
	}
	ft_fill_back(tmp, field, count);
}

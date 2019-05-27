/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:06:28 by lcrawn            #+#    #+#             */
/*   Updated: 2019/05/27 14:50:03 by lcrawn           ###   ########.fr       */
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

void		ft_fill_back(t_flist *alst, char **field, int count)
{
	int i;
	int j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			if (field[i][j] == '1')
				field[i][j] = alst->letter;
			j++;
		}
		i++;
	}
}

int			ft_are_dots(t_flist *alst, char **field, int i, int j)
{
	if ((field[(alst->y)[0] + i][(alst->x)[0] + j] == '.' ||
	field[(alst->y)[0] + i][(alst->x)[0] + j] == alst->letter) &&
		(field[(alst->y)[1] + i][(alst->x)[1] + j] == '.' ||
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

t_clist		*ft_find_list(t_clist **head, char to_find,
		void (*f)(t_clist **, char to_push))
{
	t_clist *tmp;

	tmp = *head;
	while (tmp && (tmp->letter != to_find))
		tmp = tmp->next;
	if (tmp == NULL)
	{
		f(head, to_find);
		tmp = *head;
		while (tmp && (tmp->letter != to_find))
			tmp = tmp->next;
	}
	return (tmp);
}

t_clist		*ft_create_elem(char l, int y, int x)
{
	t_clist *tmp;

	tmp = (t_clist *)malloc(sizeof(t_clist));
	if (tmp)
	{
		tmp->letter = l;
		(tmp->a)[0] = y;
		(tmp->a)[1] = x;
		tmp->next = NULL;
		return (tmp);
	}
	return (NULL);
}

void		ft_push_list_2(t_clist **head, char to_push)
{
	t_clist *tmp;

	tmp = *head;
	if (!tmp)
	{
		tmp = ft_create_elem(to_push, 0, 0);
		*head = tmp;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_elem(to_push, 0, 0);
}

void		ft_set_dots(t_clist **alst, t_flist *tmp, char **field, int count)
{
	int i;
	int j;

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

t_flist		*ft_return_prev(t_flist *alst, t_flist *to_find)
{
	t_flist *tmp;

	tmp = alst;
	if (tmp->letter == to_find->letter)
		return (NULL);
	while (tmp && ((tmp->next)->letter != to_find->letter))
		tmp = tmp->next;
	return (tmp);
}
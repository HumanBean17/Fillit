/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:06:39 by lcrawn            #+#    #+#             */
/*   Updated: 2019/05/27 14:49:03 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_find_min(const int *ar)
{
	int i;
	int min;

	i = 0;
	min = ar[0];
	while (i < 4)
	{
		if (ar[i] < min)
			min = ar[i];
		i++;
	}
	return (min);
}

void		ft_fill_elem(t_flist *tmp, char **matrix)
{
	int k;
	int i;
	int j;

	i = 0;
	k = 0;
	tmp->x = (int *)malloc(sizeof(int) * 4);
	tmp->y = (int *)malloc(sizeof(int) * 4);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (matrix[i][j] != '.')
			{
				(tmp->x)[k] = j;
				(tmp->y)[k] = i;
				k++;
			}
			j++;
		}
		i++;
	}
}

void		ft_swap_2(t_flist **alst)
{
	int		i;
	t_flist	*tmp;

	tmp = *alst;
	i = 0;
	while ((tmp->x)[0] != 0)
	{
		while (i < 4)
		{
			(tmp->x)[i] -= 1;
			i++;
		}
		i = 0;
	}
}

void		ft_swap(t_flist **tmp)
{
	int		i;
	int		x_min;
	int		y_min;

	i = 0;
	x_min = ft_find_min((*tmp)->x);
	y_min = ft_find_min((*tmp)->y);
	while (i < 4)
	{
		((*tmp)->x)[i] -= x_min;
		((*tmp)->y)[i] -= y_min;
		i++;
	}
}

void		ft_push_list(t_flist **alst, int l, char **matrix)
{
	t_flist	*tmp;

	tmp = *alst;
	if (!tmp)
	{
		tmp = ft_new_elem(l);
		*alst = tmp;
		ft_fill_elem(tmp, matrix);
		ft_swap(&tmp);
		ft_swap_2(&tmp);
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_new_elem(l);
	ft_fill_elem(tmp->next, matrix);
	ft_swap(&(tmp->next));
	ft_swap_2(&(tmp->next));
}

void		ft_glist_del(t_clist **head)
{
	t_clist *cur;
	t_clist *tmp;

	tmp = *head;
	if (tmp)
	{
		while (tmp)
		{
			tmp = (*head)->next;
			cur = *head;
			(*head) = (*head)->next;
			free(cur);
			cur = NULL;
		}
	}
}

void		ft_list_del(t_flist **head)
{
	t_flist *cur;
	t_flist *tmp;

	tmp = *head;
	if (tmp)
	{
		while (tmp)
		{
			free(tmp->x);
			tmp->x = NULL;
			free(tmp->y);
			tmp->y = NULL;
			tmp = (*head)->next;
			cur = *head;
			(*head) = (*head)->next;
			free(cur);
			cur = NULL;
		}
	}
}

t_flist		*ft_new_elem(int l)
{
	t_flist *tmp;

	tmp = (t_flist *)malloc(sizeof(t_flist));
	if (tmp)
	{
		tmp->letter = (char)(l + 65);
		tmp->x = NULL;
		tmp->y = NULL;
		tmp->next = NULL;
		return (tmp);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:06:39 by lcrawn            #+#    #+#             */
/*   Updated: 2019/05/25 17:13:26 by lcrawn           ###   ########.fr       */
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

void		ft_fill_elem(list *tmp, char **matrix)
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

void		ft_swap_2(list **alst)
{
	int		i;
	list	*tmp;

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

void		ft_swap(list **tmp)
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

void		ft_push_list(list **alst, int l, char **matrix)
{
	list	*tmp;

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

void		ft_glist_del(g_list **head)
{
	g_list *cur;
	g_list *tmp;

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

void		ft_list_del(list **head)
{
	list *cur;
	list *tmp;

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

list		*ft_new_elem(int l)
{
	list *tmp;

	tmp = (list *)malloc(sizeof(list));
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_and_not_only.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:33:12 by croxane           #+#    #+#             */
/*   Updated: 2019/05/27 15:39:08 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_clist			*ft_find_list(t_clist **head, char to_find,
		void (*f)(t_clist **, char to_push))
{
	t_clist		*tmp;

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

t_clist			*ft_create_elem(char l, int y, int x)
{
	t_clist		*tmp;

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

void			ft_push_list_2(t_clist **head, char to_push)
{
	t_clist		*tmp;

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

void			ft_fill_back(t_flist *alst, char **field, int count)
{
	int			i;
	int			j;

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

t_flist			*ft_return_prev(t_flist *alst, t_flist *to_find)
{
	t_flist		*tmp;

	tmp = alst;
	if (tmp->letter == to_find->letter)
		return (NULL);
	while (tmp && ((tmp->next)->letter != to_find->letter))
		tmp = tmp->next;
	return (tmp);
}

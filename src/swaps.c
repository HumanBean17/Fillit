/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:39:52 by croxane           #+#    #+#             */
/*   Updated: 2019/05/27 15:41:41 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int			ft_find_min(const int *ar)
{
	int		i;
	int		min;

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

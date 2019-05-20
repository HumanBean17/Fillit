/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 09:42:16 by lcrawn            #+#    #+#             */
/*   Updated: 2019/05/20 15:21:09 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_set(char **field, list *alst, int x_begin, int y_begin)
{
	int 	i;
	list 	*tmp;

	i = 0;
	tmp = alst;
	while (i < 4)
	{
		field[(tmp->y)[i] + y_begin][(tmp->x)[i] + x_begin] = tmp->letter;
		i++;
	}
}

int 	ft_is_dots(char **field, list *alst, int j, int i)
{
	if	(field[(alst->y)[0] + i][(alst->x)[0] + j]== '.' &&
			field[(alst->y)[1] + i][(alst->x)[1] + j]== '.' &&
			field[(alst->y)[2] + i][(alst->x)[2] + j]== '.' &&
			field[(alst->y)[3] + i][(alst->x)[3] + j]== '.')
		return (1);
	return (0);
}

int		ft_try_set(char **field, int count, list *alst)
{
	int i;
	int j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			if (field[i][j] == '.')
			{
				if ((j + ft_find_max(alst->x)) < count && (i + ft_find_max(alst->y)) < count)
				{
					if (ft_is_dots(field, alst, j, i) == 1)
					{
						ft_set(field, alst, j, i);
						return (1);
					}
				}
				else if ((i + ft_find_max(alst->y)) >= count)
				{
					ft_print(field, count);
					printf("%d %d\n", i, ft_find_max(alst->y));
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_fillit(list **alst, int count)
{
	char 	**field;
	list	*tmp;

	field = NULL;
	field = ft_create_field(count);
	tmp = *alst;
	while (tmp)
	{
		if (ft_try_set(field, count, tmp) == 0)
		{
			ft_del_matrix(field, count);
			ft_fillit(alst, count + 1);
			return ;
		}
		tmp = tmp->next;
	}
	ft_print(field, count);
}

int     main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		ft_putstr("error\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	ft_tetromin_save(fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 09:42:16 by lcrawn            #+#    #+#             */
/*   Updated: 2019/05/20 18:49:28 by lcrawn           ###   ########.fr       */
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
	if (field[(alst->y)[0] + i][(alst->x)[0] + j] == '.' &&
			field[(alst->y)[1] + i][(alst->x)[1] + j] == '.' &&
			field[(alst->y)[2] + i][(alst->x)[2] + j] == '.' &&
			field[(alst->y)[3] + i][(alst->x)[3] + j] == '.')
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
				if ((j + ft_find_min(alst->x)) < count && (i + ft_find_max(alst->y)) < count)
				{
					if (ft_is_dots(field, alst, j, i) == 1)
					{
						ft_set(field, alst, j, i);
						return (1);
					}
				}
				else if ((i + ft_find_max(alst->y)) > count)
				{
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_go_back(char **field, int count, list *alst)
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

void	ft_fillit(list **head, int count, char **field)
{
	list	*tmp;
	list	*prev;

	printf("recursion really sucks\n");
	if (!(*field))
		field = ft_create_field(count);
	tmp = *head;
	printf("letter %c\n", tmp->letter);
	ft_print(field, count);
	while (tmp)
	{
		if (ft_try_set(field, count, tmp) == 0)
		{
			prev = ft_return_prev(head, tmp);
			if (prev == *head || prev == NULL)
			{
				ft_print(field, count);
				ft_del_matrix(field, count);
				ft_fillit(head, count + 1, field);
				return ;
			}
			ft_adskiy_kostyl(field, count, prev);
			ft_print(field, count);
			ft_dot_field(prev, field, count);
			ft_go_back(field, count, prev);
			printf("should be removed\n");
			ft_print(field, count);
			ft_fillit(&tmp, count, field);
			return ;
		}
		printf("%c\n", tmp->letter);
		ft_print(field, count);
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
	//fd = open("/Users/lcrawn/Fillit/jestkiy_test", O_RDONLY);
	ft_tetromin_save(fd);
	return (0);
}

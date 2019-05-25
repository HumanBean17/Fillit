/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 09:42:16 by lcrawn            #+#    #+#             */
/*   Updated: 2019/05/25 13:07:16 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fillit(list *head, list *const_head, int *count)
{
	static char **field;
	static int 	i;
	list		*tmp;
	list		*prev;

	if ((!field) || !(*field))
		field = ft_create_field(*count);
	tmp = head;
	if (i == 70000)
	{
		i = 0;
		return (1);
	}
	i++;
	while (tmp)
	{
		if (ft_try_set(tmp, field, *count, 1) == 0)
		{
			prev = ft_return_prev(const_head, tmp);
			if (prev == NULL)
			{
				ft_try_set(tmp, field, *count, 0);
				ft_del_matrix(field, *count);
				*count += 1;
				ft_fillit(const_head, const_head, count);
				return (2);
			}
			else
			{
				ft_fillit(prev, const_head, count);
				if (i == 0)
					return (0);
				return (3);
			}
		}
		else
			tmp = tmp->next;
	}
	ft_print(field, *count);
	exit(0);
}

void	ft_dfs(list **head, int count)
{
	int i;

	i = 0;
	while (i != 4)
		i = ft_fillit(*head, *head, &count);
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

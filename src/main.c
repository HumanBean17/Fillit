/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 12:58:43 by croxane           #+#    #+#             */
/*   Updated: 2019/05/31 17:37:15 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_do_op(t_flist **head, char **field, int count)
{
	ft_print(field, count);
	ft_del_matrix(field, count);
	ft_list_del(head);
	ft_try_set(*head, field, count, 2);
}

int		ft_fillit(t_flist *head, t_flist *const_head, int *count, int *i)
{
	static char **field;

	if ((!field) || !(*field))
		field = ft_create_field(*count);
	if ((*i)++ == 50000)
		return (1);
	while (head)
	{
		if (!(ft_try_set(head, field, *count, 1)))
		{
			if (ft_return_prev(const_head, head) == NULL)
			{
				ft_try_set(head, field, (*count)++, 0);
				ft_fillit(const_head, const_head, count, i);
				return (2);
			}
			else
				ft_fillit(ft_return_prev(const_head, head),
						const_head, count, i);
			return (3);
		}
		head = head->next;
	}
	ft_do_op(&const_head, field, *count);
	exit(0);
}

void	ft_dfs(t_flist **head, int count)
{
	int i;
	int c;

	i = 1;
	c = 0;
	while (i)
	{
		c = 0;
		ft_fillit(*head, *head, &count, &c);
	}
}

int		main(int argc, char **argv)
{
	int fd;
	int fd_n;
	int count;

	count = 0;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	fd_n = open(argv[1], O_RDONLY);
	ft_tetromin_save(fd_n, fd, count, count);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 09:42:16 by lcrawn            #+#    #+#             */
/*   Updated: 2019/05/21 18:19:39 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fillit(list *head, list *const_head, int count, char **field)
{
	list	*tmp;
	list	*prev;
	int i = 0;

	if (!(*field))
		field = ft_create_field(count);
	tmp = head;
	printf("before change %c\n", tmp->letter);
	ft_print(field, count);
	while (tmp)
	{
		if (ft_try_set(tmp, field, count) == 0)
		{
			printf("after change %c\n", tmp->letter);
			ft_print(field, count);
			prev = ft_return_prev(const_head, tmp);
			if (prev == NULL)
			{
				printf("gonna delete\n");
				ft_print(field, count);
				ft_del_matrix(field, count);
				ft_fillit(const_head, const_head, count + 1, field);
				return (0);
			}
			else
			{
				printf("head = %c prev = %c set = %c\n", const_head->letter, prev->letter, tmp->letter);
				ft_print(field, count);
				ft_fillit(prev, const_head, count, field);
			}
		}
		else
		{
			tmp = tmp->next;
			//printf("tmp next comes\n");
			//ft_print(field, count);
		}
	}
	ft_print(field, count);
	return (0);
}

int     main(int argc, char **argv)
{
	int fd;

	/*if (argc != 2)
	{
		ft_putstr("error\n");
		return (0);
	}*/
	//fd = open(argv[1], O_RDONLY);
	fd = open("/Users/lcrawn/Fillit/test.txt", O_RDONLY);
	ft_tetromin_save(fd);
	return (0);
}

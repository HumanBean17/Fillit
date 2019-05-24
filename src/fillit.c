/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 09:42:16 by lcrawn            #+#    #+#             */
/*   Updated: 2019/05/24 17:35:39 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fillit(list *head, list *const_head, int *count, int c)
{
	static char **field;
	static int 	i;
	list		*tmp;
	list		*prev;

	if ((!field) || !(*field))
		field = ft_create_field(*count);
	tmp = head;
	//printf("before change %c\n", tmp->letter);
	//ft_print(field, count);
	//printf("ok\n");
	if (i == 80000)
	{
		i = 0;
		//printf("return 1\n");
		//ft_print(field, *count);
		return (1);
	}
	i++;
	while (tmp)
	{
		if (ft_try_set(tmp, field, *count, 1) == 0)
		{
			//printf("after change %c\n", tmp->letter);
			//ft_print(field, count);
			prev = ft_return_prev(const_head, tmp);
			if (prev == NULL)
			{
				//printf("gonna delete\n");
				ft_try_set(tmp, field, *count, 0);
				//ft_print(field, count);
				ft_del_matrix(field, *count);
				*count += 1;
				ft_fillit(const_head, const_head, count, c);
				//printf("return 2\n");
				//printf("i = %d\n", i);
				if (c == 3) {
					ft_print(field, *count);
					exit(0);
				}
				if (i == 0)
					return (6);
				return (2);
			}
			else
			{
				//printf("head = %c prev = %c set = %c\n", const_head->letter, prev->letter, tmp->letter);
				//ft_print(field, count);
				ft_fillit(prev, const_head, count, c);
				//printf("return 3\n");
				//ft_print(field, *count);
				return (3);
			}
		}
		else
		{
			//printf("tmp next comes %c\n", tmp->letter);
			tmp = tmp->next;
			//ft_print(field, count);
		}
	}
	//printf("at the end\n");
	//printf("return 4\n");
	ft_print(field, *count);
	exit(0);
	return (4);
}

void	ft_dfs(list **head, int count)
{
	char **field;
	int i;
	int c;

	i = ft_fillit(*head, *head, &count, 0);
	while (i != 2)
	{
		i = ft_fillit(*head, *head, &count, i);
		//printf("i = %d\n", i);
	}
	//printf("%d\n", i);
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
	//fd = open("/Users/lcrawn/Fillit/test.txt", O_RDONLY);
	ft_tetromin_save(fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:06:19 by lcrawn            #+#    #+#             */
/*   Updated: 2019/05/27 14:45:29 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_error(void)
{
	ft_putstr("error\n");
	exit(1);
}

int 	ft_square(int count)
{
	int num;

	num = 1;
	while (num * num < count * 4)
		num++;
	return (num);
}

void		ft_validation(char **line, int i, int j, int *c)
{
	if (j != 3 && line[i][j + 1] != '.')
		line[i][j]++;
	if (j != 0 && line[i][j - 1] != '.' )
		line[i][j]++;
	if (i != 3 && line[i + 1][j] != '.')
		line[i][j]++;
	if (i != 0 && line[i - 1][j] != '.')
		line[i][j]++;
	*c += (int)line[i][j] - 48;
}

void		ft_check(char **line)
{
	int i;
	int j;
	int c;

	i = -1;
	c = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (line[i][j] != '#' && line[i][j] != '.')
				ft_print_error();
			else if (line[i][j] == '#')
			{
				line[i][j] = '0';
				ft_validation(line, i, j, &c);
			}
			else if ((line[i][j] == '0' || line[i][j] > '3') && line[i][j] != '.')
				ft_print_error();
	}
	if (c != 8 && c != 6)
		ft_print_error();
}

void	ft_check_2(int fd)
{
	char *line;

	get_next_line(fd, &line);
	if (line[0] != 0)
		ft_print_error();
	ft_strdel(&line);
}

int 	ft_check_3(t_flist **head, char **matrix, int fd, int *count)
{
	ft_check_2(fd);
	ft_check(matrix);
	ft_push_list(head, *count, matrix);
	(*count)++;
	return (0);
}

int 	ft_tetromin_save(int fd, int count, int i)
{
	char    **matrix;
	t_flist	*head;

	head = NULL;
	if (!(matrix = ft_create_matrix(4)))
		return (0);
	while (get_next_line(fd, &matrix[i]))
	{
		if (ft_strlen(matrix[i]) != 4 || count > 25)
			ft_print_error();
		if (++i > 3)
		{
			i = ft_check_3(&head, matrix, fd, &count);
			ft_del_matrix(matrix, 4);
			matrix = ft_create_matrix(4);
		}
	}
	if (count != 0 && matrix[i] == 0)
	{
		ft_del_matrix(matrix, 4);
		ft_dfs(&head, ft_square(count));
	}
	ft_print_error();
	return (0);
}

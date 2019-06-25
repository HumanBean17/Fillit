/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:06:19 by lcrawn            #+#    #+#             */
/*   Updated: 2019/05/31 17:38:06 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_square(int count)
{
	int		num;

	num = 1;
	while (num * num < count * 4)
		num++;
	return (num);
}

void		ft_validation(char **line, int i, int j, int *c)
{
	if (j != 3 && line[i][j + 1] != '.')
		line[i][j]++;
	if (j != 0 && line[i][j - 1] != '.')
		line[i][j]++;
	if (i != 3 && line[i + 1][j] != '.')
		line[i][j]++;
	if (i != 0 && line[i - 1][j] != '.')
		line[i][j]++;
	*c += (int)line[i][j] - 48;
}

void		check_n(int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;

	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	if (buff[ret - 1] != '\n')
		ft_print_error();
}

int			ft_tetromin_save(int fd_n, int fd, int count, int i)
{
	char	**matrix;
	t_flist	*head;

	head = NULL;
	check_n(fd_n);
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

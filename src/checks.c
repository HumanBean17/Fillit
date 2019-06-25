/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:25:42 by croxane           #+#    #+#             */
/*   Updated: 2019/05/31 17:36:29 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_check(char **line, int k)
{
	int		i;
	int		j;
	int		c;

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
				k++;
				line[i][j] = '0';
				ft_validation(line, i, j, &c);
			}
		if ((line[i][j] == '0' || line[i][j] > '3')
					&& line[i][j] != '.')
			ft_print_error();
	}
	if ((c != 8 && c != 6) || k != 4)
		ft_print_error();
}

void		ft_check_2(int fd)
{
	char	*line;

	get_next_line(fd, &line);
	if (line[0] != 0)
		ft_print_error();
	ft_strdel(&line);
}

int			ft_check_3(t_flist **head, char **matrix, int fd, int *count)
{
	int k;

	k = 0;
	ft_check_2(fd);
	ft_check(matrix, k);
	ft_push_list(head, *count, matrix);
	(*count)++;
	return (0);
}

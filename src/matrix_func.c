/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:39:35 by croxane           #+#    #+#             */
/*   Updated: 2019/05/27 15:39:37 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_del_matrix(char **matrix, int count)
{
	int i;

	i = 0;
	if (*matrix)
	{
		while (i < count)
		{
			ft_strdel(&matrix[i]);
			i++;
		}
		free(matrix);
		*matrix = NULL;
	}
}

char		**ft_create_field(int count)
{
	char	**field;
	int		i;
	int		j;

	field = ft_create_matrix(count);
	i = 0;
	while (i < count)
	{
		j = 0;
		field[i] = ft_strnew(count);
		while (j < count)
		{
			field[i][j] = '.';
			j++;
		}
		i++;
	}
	return (field);
}

char		**ft_create_matrix(int size)
{
	int		i;
	char	**matrix;

	i = 0;
	matrix = NULL;
	matrix = (char **)malloc(sizeof(char*) * size);
	if (matrix)
	{
		while (i < size)
		{
			matrix[i] = NULL;
			i++;
		}
		return (matrix);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:06:33 by lcrawn            #+#    #+#             */
/*   Updated: 2019/05/27 15:22:08 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_print(char **matrix, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		ft_putstr(matrix[i]);
		ft_putchar('\n');
		i++;
	}
}

void		ft_print_error(void)
{
	ft_putstr("error\n");
	exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 17:04:09 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/14 17:13:06 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
		i++;
	i--;
	while (i > k)
	{
		str[k] += str[i];
		str[i] = str[k] - str[i];
		str[k] -= str[i];
		k++;
		i--;
	}
	return (str);
}

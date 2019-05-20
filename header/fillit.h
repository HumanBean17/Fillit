/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 09:39:51 by lcrawn            #+#    #+#             */
/*   Updated: 2019/05/20 18:18:17 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <fcntl.h>
#include "get_next_line.h"

typedef struct 	f_list
{
	int 			*x;
	int 			*y;
	char 			letter;
	struct f_list 	*next;
}				list;

void			ft_kostyl_set(char **field, list *alst, int x_begin, int y_begin);
void			ft_adskiy_kostyl(char **field, int count, list *alst);
void			ft_set(char **field, list *alst, int x_begin, int y_begin);
int 			ft_is_dots(char **field, list *alst, int j, int i);
void			ft_dot_field(list *tmp, char **field, int count);
list			*ft_return_prev(list **alst, list *to_find);
void			ft_fillit(list **head, int count, char **field);
int 			ft_tetromin_save(int fd);
void			ft_print(char **matrix, int count);
void			ft_list_print(list **head);
list			*ft_new_elem(int l, char **matrix);
void			ft_fill_elem(list *tmp, char **matrix);
int 			ft_find_min(const int *ar);
int 			ft_find_max(const int *ar);
void			ft_swap(list *alst);
void 			ft_push_list(list **alst, int l, char **matrix);
void			ft_del_matrix(char **matrix, int count);
char			**ft_create_field(int count);
int 			ft_check(char **line);

#endif

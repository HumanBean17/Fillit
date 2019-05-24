/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 09:39:51 by lcrawn            #+#    #+#             */
/*   Updated: 2019/05/24 16:52:39 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
#define LOG_TRACE printf("Entering %s()\n", __FUNCTION__);
#include <fcntl.h>
#include "get_next_line.h"

typedef struct  c_list
{
	char 			letter;
	int 			a[2];
	struct c_list 	*next;
}				g_list;

typedef struct 	f_list
{
	int 			*x;
	int 			*y;
	char 			letter;
	struct f_list 	*next;
}				list;

void			ft_dfs(list **head, int count);
int 			ft_count_dots(char **field, int count);
g_list			*ft_find_list(g_list **head, char to_find);
void			ft_push_list_2(g_list **head, char to_push);
void			ft_fill_back(list *alst, char **field, int count);
int				ft_fit(list *alst, int count, int i, int j);
void			ft_set(list *alst, char **field, int y_begin, int x_begin);
int				ft_try_set(list *alst, char **field, int count, int flag);
int 			ft_are_dots(list *alst, char **field, int i, int j);
void			ft_dot_field(list *tmp, char **field, int count);
list			*ft_return_prev(list *alst, list *to_find);
int				ft_fillit(list *head, list *const_head, int *count, int c);
int 			ft_tetromin_save(int fd);
void			ft_print(char **matrix, int count);
void			ft_list_print(list **head);
list			*ft_new_elem(int l);
void			ft_fill_elem(list *tmp, char **matrix);
int 			ft_find_min(const int *ar);
int 			ft_find_max(const int *ar);
void			ft_swap(list **tmp);
void 			ft_push_list(list **alst, int l, char **matrix);
void			ft_del_matrix(char **matrix, int count);
char			**ft_create_field(int count);
int 			ft_check(char **line);

#endif

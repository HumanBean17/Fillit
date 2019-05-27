/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 09:39:51 by lcrawn            #+#    #+#             */
/*   Updated: 2019/05/27 14:56:44 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "get_next_line.h"

typedef struct		s_clist
{
	char			letter;
	int				a[2];
	struct s_clist	*next;
}					t_clist;

typedef struct		s_flist
{
	int				*x;
	int				*y;
	char			letter;
	struct s_flist	*next;
}					t_flist;

void				ft_glist_del(t_clist **head);
void				ft_list_del(t_flist **head);
char 				**ft_create_matrix(int size);
int 				ft_square(int count);
void				ft_dfs(t_flist **head, int count);
t_clist				*ft_find_list(t_clist **head, char to_find, void (*f)(t_clist **, char to_push));
void				ft_push_list_2(t_clist **head, char to_push);
void				ft_fill_back(t_flist *alst, char **field, int count);
int					ft_fit(t_flist *alst, int count, int i, int j);
void				ft_set(t_flist *alst, char **field, int y_begin, int x_begin);
int					ft_try_set(t_flist *alst, char **field, int count, int flag);
int 				ft_are_dots(t_flist *alst, char **field, int i, int j);
void				ft_dot_field(t_flist *tmp, char **field, int count);
t_flist				*ft_return_prev(t_flist *alst, t_flist *to_find);
int					ft_fillit(t_flist *head, t_flist *const_head, int *count, int *i);
int 				ft_tetromin_save(int fd, int count, int i);
void				ft_print(char **matrix, int count);
void				ft_list_print(t_flist **head);
t_flist				*ft_new_elem(int l);
void				ft_fill_elem(t_flist *tmp, char **matrix);
int 				ft_find_min(const int *ar);
int 				ft_find_max(const int *ar);
void				ft_swap(t_flist **tmp);
void 				ft_push_list(t_flist **alst, int l, char **matrix);
void				ft_del_matrix(char **matrix, int count);
char				**ft_create_field(int count);
void	 			ft_check(char **line);

#endif

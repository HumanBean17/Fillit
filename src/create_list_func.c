#include "fillit.h"

int 	ft_find_min(const int *ar)
{
	int i;
	int min;

	i = 0;
	min = ar[0];
	while (i < 4)
	{
		if (ar[i] < min)
			min = ar[i];
		i++;
	}
	return (min);
}

int 	ft_find_max(const int *ar)
{
	int i;
	int max;

	i = 0;
	max = ar[0];
	while (i < 4)
	{
		if (ar[i] > max)
			max = ar[i];
		i++;
	}
	return (max);
}

void	ft_fill_elem(list *tmp, char **matrix)
{
	int k;
	int i;
	int j;

	i = 0;
	k = 0;
	tmp->x = (int *)malloc(sizeof(int) * 4);
	tmp->y = (int *)malloc(sizeof(int) * 4);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (matrix[i][j] != '.')
			{
				(tmp->x)[k] = j;
				(tmp->y)[k] = i;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	ft_swap_2(list **alst)
{
	int 	flag;
	int 	i;
	list 	*tmp;

	tmp = *alst;
	i = 0;
	flag = 0;
	/*while (i < 4)
	{
		if ((tmp->x)[i] == 0 && (tmp->y)[i] == 0)
			flag = 1;
		i++;
	}
	i = 0;*/
	while ((tmp->x)[0] != 0)
	{
		while (i < 4)
		{
			(tmp->x)[i] -= 1;
			i++;
		}
		i = 0;
	}
}

void	ft_swap(list **tmp)
{
	int		i;
	int 	x_min;
	int 	y_min;

	i = 0;
	x_min = ft_find_min((*tmp)->x);
	y_min = ft_find_min((*tmp)->y);
	while (i < 4)
	{
		((*tmp)->x)[i] -= x_min;
		((*tmp)->y)[i] -= y_min;
		i++;
	}
}

void 	ft_push_list(list **alst, int l, char **matrix)
{
	list 	*tmp;

	tmp = *alst;
	if (!tmp)
	{
		tmp = ft_new_elem(l);
		*alst = tmp;
		ft_fill_elem(tmp, matrix);
		ft_swap(&tmp);
		ft_swap_2(&tmp);
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_new_elem(l);
	ft_fill_elem(tmp->next, matrix);
	ft_swap(&(tmp->next));
	ft_swap_2(&(tmp->next));
}

list		*ft_new_elem(int l)
{
	list *tmp;

	tmp = (list *)malloc(sizeof(list));
	if (tmp)
	{
		tmp->letter = (char)(l + 65);
		tmp->x = NULL;
		tmp->y = NULL;
		tmp->next = NULL;
		return (tmp);
	}
	return (NULL);
}
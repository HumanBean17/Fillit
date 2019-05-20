#include "fillit.h"

void		ft_print(char **matrix, int count)
{
	for (int i = 0; i < count; i++)
		printf("%s\n", matrix[i]);
	//printf("\n");
}

void		ft_list_print(list **head)
{
	list *tmp;

	tmp = *head;
	while (tmp)
	{
		printf("%c\n", tmp->letter);
		for (int i = 0; i < 4; i++)
			printf("%d ", tmp->x[i]);
		printf("\n");
		for (int i = 0; i < 4; i++)
			printf("%d ", tmp->y[i]);
		printf("\n");
		tmp = tmp->next;
	}
}

list		*ft_new_elem(int l, char **matrix)
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

void	ft_swap(list *alst)
{
	int		i;
	list 	*tmp;
	int 	x_min;
	int 	y_min;

	i = 0;
	tmp = alst;
	x_min = ft_find_min(tmp->x);
	y_min = ft_find_min(tmp->y);
	while (i < 4)
	{
		(tmp->x)[i] -= x_min;
		(tmp->y)[i] -= y_min;
		i++;
	}
}

void 	ft_push_list(list **alst, int l, char **matrix)
{
	list 	*tmp;

	tmp = *alst;
	if (!tmp)
	{
		tmp = ft_new_elem(l, matrix);
		*alst = tmp;
		ft_fill_elem(tmp, matrix);
		ft_swap(tmp);
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_new_elem(l, matrix);
	ft_fill_elem(tmp->next, matrix);
	ft_swap(tmp->next);
}

void	ft_del_matrix(char **matrix, int count)
{
	int i;

	i = 0;
	if (matrix)
	{
		while (i < count)
		{
			ft_strdel(&matrix[i]);
			i++;
		}
		free(matrix);
	}
}

char	**ft_create_field(int count)
{
	char 	**field;
	int 	i;
	int 	j;

	field = (char **) malloc(sizeof(char *) * count);
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
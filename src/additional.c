#include "fillit.h"

void	ft_set(char **field, list *alst, int x_begin, int y_begin)
{
	int 	i;
	list 	*tmp;

	i = 0;
	tmp = alst;
	while (i < 4)
	{
		field[(tmp->y)[i] + y_begin][(tmp->x)[i] + x_begin] = '1';
		i++;
	}
}

void	ft_fill_back(char **field, int count, list *alst)
{
	int i;
	int j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			if (field[i][j] == '1')
				field[i][j] = alst->letter;
			j++;
		}
		i++;
	}
}


int 	ft_are_dots(char **field, list *alst, int j, int i)
{
	//ft_list_print(&alst);
	if ((field[(alst->y)[0] + i][(alst->x)[0] + j] == '.' || field[(alst->y)[0] + i][(alst->x)[0] + j] == '1' || field[(alst->y)[0] + i][(alst->x)[0] + j] == alst->letter) &&
		(field[(alst->y)[1] + i][(alst->x)[1] + j] == '.' || field[(alst->y)[1] + i][(alst->x)[1] + j] == '1' || field[(alst->y)[0] + i][(alst->x)[0] + j] == alst->letter) &&
		(field[(alst->y)[2] + i][(alst->x)[2] + j] == '.' || field[(alst->y)[2] + i][(alst->x)[2] + j] == '1' || field[(alst->y)[0] + i][(alst->x)[0] + j] == alst->letter) &&
		(field[(alst->y)[3] + i][(alst->x)[3] + j] == '.' || field[(alst->y)[3] + i][(alst->x)[3] + j] == '1' || field[(alst->y)[0] + i][(alst->x)[0] + j] == alst->letter))
		return (1);
	return (0);
}

int		ft_fit(list *alst, int count, int i, int j)
{
	if (i + (alst->y)[0] < count && i + (alst->y)[1] < count &&
		i + (alst->y)[2] < count && i + (alst->y)[3] < count &&
		j + (alst->x)[0] < count && j + (alst->x)[1] < count &&
		j + (alst->x)[2] < count && j + (alst->x)[3] < count)
		return (1);
	return (0);
}

int 	ft_find_i(list *alst, char **field, int count)
{
	int i;
	int j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			if (field[i][j] == alst->letter)
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int 	ft_find_j(list *alst, char **field, int count)
{
	int i;
	int j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			if (field[i][j] == alst->letter)
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}

int		ft_try_set(list *alst, char **field, int count)
{
	int i;
	int j;

	i = ft_find_i(alst, field, count);
	j = ft_find_j(alst, field, count);
	if (i < 0)
		i = 0;
	if (j < 0)
		j = 0;
	printf("FUCKING I = %d FUCKING J = %d\n", i, j);
	while (i < count)
	{
		while (j < count)
		{
			if (ft_fit(alst, count, i, j) == 1)
			{
				printf("fit i = %d  j = %d\n", i, j);
				if (ft_are_dots(field, alst, j, i) == 1)
				{
					printf("i = %d  j = %d\n", i, j);
					printf("OK\n");
					ft_set(field, alst, j, i);
					ft_print(field, count);
					ft_dot_field(alst, field, count);
					ft_print(field, count);
					ft_fill_back(field, count, alst);
					ft_print(field, count);
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_dot_field(list *tmp, char **field, int count)
{
	int c;
	int i;
	int j;

	c = 0;
	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			if (field[i][j] == tmp->letter)
			{
				c++;
				field[i][j] = '.';
			}
			if (c >= 4)
				return ;
			j++;
		}
		i++;
	}
}

list	*ft_return_prev(list *alst, list *to_find)
{
	list *tmp;

	tmp = alst;
	if (tmp->letter == to_find->letter)
		return (NULL);
	while (tmp && ((tmp->next)->letter != to_find->letter))
		tmp = tmp->next;
	//printf("\n");
	return (tmp);
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
		*matrix = NULL;
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
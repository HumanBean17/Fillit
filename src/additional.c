#include "fillit.h"

void	ft_set(list *alst, char **field, int y_begin, int x_begin)
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

void	ft_fill_back(list *alst, char **field, int count)
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


int 	ft_are_dots(list *alst, char **field, int i, int j)
{
	//ft_list_print(&alst);
	if ((field[(alst->y)[0] + i][(alst->x)[0] + j] == '.' || field[(alst->y)[0] + i][(alst->x)[0] + j] == ',' || field[(alst->y)[0] + i][(alst->x)[0] + j] == '1' || field[(alst->y)[0] + i][(alst->x)[0] + j] == alst->letter) &&
		(field[(alst->y)[1] + i][(alst->x)[1] + j] == '.' || field[(alst->y)[1] + i][(alst->x)[1] + j] == ',' || field[(alst->y)[1] + i][(alst->x)[1] + j] == '1' || field[(alst->y)[1] + i][(alst->x)[1] + j] == alst->letter) &&
		(field[(alst->y)[2] + i][(alst->x)[2] + j] == '.' || field[(alst->y)[2] + i][(alst->x)[2] + j] == ',' || field[(alst->y)[2] + i][(alst->x)[2] + j] == '1' || field[(alst->y)[2] + i][(alst->x)[2] + j] == alst->letter) &&
		(field[(alst->y)[3] + i][(alst->x)[3] + j] == '.' || field[(alst->y)[3] + i][(alst->x)[3] + j] == ',' || field[(alst->y)[3] + i][(alst->x)[3] + j] == '1' || field[(alst->y)[3] + i][(alst->x)[3] + j] == alst->letter))
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
			if (i != count - 1 && (field[i][j] == alst->letter || field[i + 1][j] == alst->letter))
				return (i);
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
			if (i != count - 1 && (field[i][j] == alst->letter || field[i + 1][j] == alst->letter))
				return (j);
			if (field[i][j] == alst->letter)
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}

void	ft_z(char **field, int count)
{
	int i;
	int j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			if (field[i][j] == ',')
				field[i][j] = '.';
			j++;
		}
		i++;
	}
}

g_list	*ft_find_list(g_list **head, char to_find)
{
	g_list *tmp;

	tmp = *head;
	while (tmp && (tmp->letter != to_find))
		tmp = tmp->next;
	if (tmp == NULL)
		return (NULL);
	return (tmp);
}

g_list		*ft_create_elem(char l, int y, int x)
{
	g_list *tmp;

	tmp = (g_list *)malloc(sizeof(g_list));
	if (tmp)
	{
		tmp->letter = l;
		(tmp->a)[0] = y;
		(tmp->a)[1] = x;
		tmp->next = NULL;
		return (tmp);
	}
	return (NULL);
}

void	ft_push_list_2(g_list **head, char to_push)
{
	g_list *tmp;

	tmp = *head;
	if (!tmp)
	{
		tmp = ft_create_elem(to_push, 0, 0);
		*head = tmp;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_elem(to_push, 0, 0);
}

int		ft_try_set(list *alst, char **field, int count)
{
	g_list			*tmp;
	static g_list	*a;
	int 			i;
	int 			j;

	tmp = ft_find_list(&a, alst->letter);
	if (tmp == NULL)
		ft_push_list_2(&a, alst->letter);
	tmp = ft_find_list(&a, alst->letter);
	//printf("%d %d %c\n", (tmp->a)[0], (tmp->a)[1], tmp->letter);
	/*field[0][0] = ',';
	ft_set(alst, field, 0, 0);
	ft_dot_field(alst, field, count);
	ft_fill_back(alst, field, count);
	i = 0;
	j = 1;
	if (field[i][j] == '.' && ft_fit(alst, count, i, j) == 1 && ft_are_dots(alst, field, i, j) == 1)
		ft_set(alst, field, i, j);*/
	/*i = ft_find_i(alst, field, count);
	j = ft_find_j(alst, field, count);
	if (i < 0)
		i = 0;
	if (j < 0)
		j = 0;*/
	i = (tmp->a)[0];
	j = (tmp->a)[1];
	//printf("I = %d J = %d\n", i, j);
	while (i < count)
	{
		while (j < count)
		{
			if ((field[i][j] == '.' || field[i][j] == alst->letter) && ft_fit(alst, count, i, j) == 1 && ft_are_dots(alst, field, i, j) == 1)
			{
				//printf("i = %d  j = %d\n", i, j);
				//printf("OK\n");
				ft_set(alst, field, i, j);
				ft_dot_field(alst, field, count);
				ft_fill_back(alst, field, count);
				(tmp->a)[0] = i;
				(tmp->a)[1] = j;
 				if (j + 1 < count)
					(tmp->a)[1] += 1;
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	//printf("return 0\n");
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
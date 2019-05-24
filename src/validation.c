#include "fillit.h"

int ft_check(char **line)
{
	int i;
	int j;
	int c;

	i = 0;
	c = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (line[i][j] != '#' && line[i][j] != '.')
			{
				ft_putstr("error\n");
				return (1);
			}
			if (line[i][j] == '#')
			{
				line[i][j] = '0';
				if (j != 3 && line[i][j + 1] != '.')
					line[i][j]++;
				if (j != 0 && line[i][j - 1] != '.' )
					line[i][j]++;
				if (i != 3 && line[i + 1][j] != '.')
					line[i][j]++;
				if (i != 0 && line[i - 1][j] != '.')
					line[i][j]++;
				c += (int)line[i][j] - 48;
			}
			if ((line[i][j] == '0' || line[i][j] > '3') && line[i][j] != '.')
			{
				ft_putstr("error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	if (c != 8 && c != 6)
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}

int ft_tetromin_save(int fd)
{
	int		count;
	int     i;
	int 	flag;
	char    **matrix;
	list	*head;

	flag = 0;
	i = 0;
	count = 0;
	head = NULL;
	if (!(matrix = (char **)malloc(sizeof(char *) * 4 + 1)))
		return (0);
	while (get_next_line(fd, &matrix[i]))
	{
		flag = 0;
		if (ft_strlen(matrix[i]) != 4 || count > 25)
		{
			ft_putstr("error\n");
			return (0);
		}
		matrix[i][ft_strlen(matrix[i])] = '\n';
		matrix[i][ft_strlen(matrix[i]) + 1] = '\0';
		i++;
		if (i > 3)
		{
			flag = 1;
			get_next_line(fd, &matrix[i]);
			if (matrix[i][0] != 0)
			{
				ft_putstr("error\n");
				return (0);
			}
			if (ft_check(matrix) == 1)
				return (0);
			ft_push_list(&head, count, matrix);
			i = 0;
			count++;
			ft_del_matrix(matrix, 4);
			matrix = (char **)malloc(sizeof(char *) * 4 + 1);
		}
	}
	if (count != 0 && flag == 1 && matrix[i] == 0)
	{
		ft_del_matrix(matrix, 4);
		//ft_list_print(&head);
		ft_dfs(&head, 2);
	}
	else
	{
		ft_putstr("error\n");
		return (0);
	}
	return (0);
}
#include "fillit.h"

void		ft_print(char **matrix, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		ft_putstr(matrix[i]);
		ft_putchar('\n');
		i++;
	}
}

void		ft_list_print(list **head)
{
	list *tmp;

	tmp = *head;
	while (tmp)
	{
		printf("%c\nx = ", tmp->letter);
		for (int i = 0; i < 4; i++)
			printf("%d ", tmp->x[i]);
		printf("\ny = ");
		for (int i = 0; i < 4; i++)
			printf("%d ", tmp->y[i]);
		printf("\n");
		tmp = tmp->next;
	}
}
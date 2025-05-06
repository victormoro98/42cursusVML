#include "push_swap.h"
#include "parsing_stack.c"
// typedef	struct nodo{
// 	int			dato;
// 	struct nodo *next;
// }				new_node;

new_node *first = NULL;
new_node *last = NULL;

void	insert_node(int number)
{
	new_node *new = (new_node *)malloc(sizeof(new_node));
	new->dato = number;
	
	if (first == NULL)
	{
		first = new;
		first ->next = NULL;
		last = first;
	}
	else
	{
		last->next = new;
		new ->next = NULL;
		last = new;
	}
}

void	print_list()
{
	new_node *actual = (new_node*)malloc(sizeof(new_node));
	actual = first;
	if (first != NULL)
	{
		while(actual != NULL)
		{
			printf("%d\n", actual->dato);
			actual = actual->next;
		}
	}
	else
		printf("\nLa lista esta vacia");
}

int	find_node(int	to_find)
{
	int	node_finded;

	node_finded = 0;
	new_node *actual = (new_node *)malloc(sizeof(new_node));
	actual = first;
	if (first != NULL)
	{
		while (actual != NULL && node_finded != 1)
		{
			if (actual->dato == to_find)
				node_finded = 1;
			actual = actual->next;
		}
	}
	return (node_finded);
}

int	ft_atoi(const char *str)
{
	bool	is_negative;
	int		n;

	is_negative = false;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_negative = !is_negative;
		++str;
	}
	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		n *= 10;
		n += *str - '0';
		++str;
	}
	if (is_negative)
		n = -n;
	return (n);
}

int	main(int argc, char **argv)
{
	char	**arg_str;
	int		i;
	int		new_number;

	i = 1;
	if (argc < 2 || (argc == 2 && count_nums(argv) == 1))
		return (0);
	while (argv[i])
	{
		arg_str = ft_split(argv[i], ' ');
		int 	j = 0;
		while (arg_str[j])
		{
			if (is_valid(arg_str[j]))
			{
				new_number = ft_atoi(arg_str[j]);
				if (find_node(new_number) != 1)
					insert_node(new_number);
				else
					return(0);
				j++;
			}
			else
				return(0);
		}
		free(arg_str);
		i++;
	}
	print_list();
	printf("-- --\na   b\n");
}

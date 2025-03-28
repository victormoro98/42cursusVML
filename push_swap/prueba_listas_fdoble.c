#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include "push_swap.h"
// #include <parsing_stack.c>

typedef	struct nodo{
	int			dato;
	struct nodo *next;
	struct nodo *prev;
}				node;

node *first = NULL;
node *last = NULL;

void	insert_node(int number)
{
	node *new = (node *)malloc(sizeof(node));
	new->dato = number;

	if (first == NULL)
	{
		first = new;
		first->prev = NULL;
		first ->next = NULL;
		last = first;
	}
	else
	{
		last->next = new;
		new ->next = NULL;
		new->prev = last;
		last = new;
	}
}

void	print_list()
{
	node *actual = (node*)malloc(sizeof(node));
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

void	print_reverse_list()
{
	node *actual = (node*)malloc(sizeof(node));
	actual = last;
	if (last != NULL)
	{
		while(actual != NULL)
		{
			printf("%i\n", actual->dato);
			actual = actual->prev;
		}
	}
	else
		printf("\nLa lista esta vacia");
}

void	find_node(int	to_find)
{
	int	node_finded;

	node_finded = 0;
	node *actual = (node *)malloc(sizeof(node));
	actual = first;
	if (first != NULL)
	{
		while (actual != NULL && node_finded != 1)
		{
			if (actual->dato == to_find)
			{
				node_finded = 1;
				printf("Nodo %d encontrado\n", to_find);
			}
			actual = actual->next;
		}
		if (node_finded == 0)
			printf("No se ha encontrado el nodo\n");
	}
	else
		printf("ERROR: empty list.\n");
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

bool	is_valid(char **str_num);
int		ft_isdigit(int c);

int	main(int argc, char **argv)
{
	int	i;
	int	new_node;

	i = 1;
	if (argc < 3 || !is_valid(argv))
		return (0);
	while(argv[i])
	{
		new_node = ft_atoi(argv[i]);
		insert_node(new_node);
		i++;
	}
	print_list();
	printf("-- --\na   b\n");
}

// print_list();
// print_reverse_list();
// find_node(10);
// return(0);

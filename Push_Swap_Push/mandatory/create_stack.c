/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:34:32 by rmohamma          #+#    #+#             */
/*   Updated: 2023/02/17 16:34:52 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*create_stack_a_quote(int argc, char **argv)
{
	t_stack		*head;
	long int	nbr;
	int			j;

	j = 0;
	head = NULL;
	nbr = 0;
	while (argv[j])
	{
		nbr = ft_atoi(argv[j]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			free_malloc(argv);
			error_cmd(&head, NULL);
		}
		stack_add_tail(&head, stack_new((int)nbr));
		j++;
	}
	return (head);
}

t_stack	*create_stack_a(int argc, char **argv)
{
	t_stack		*head;
	long int	nbr;
	int			i;

	head = NULL;
	nbr = 0;
	i = 1;
	if (argc == 2)
		head = create_stack_a_quote(argc, argv);
	else
	{	
		while (i < argc)
		{
			nbr = ft_atoi(argv[i]);
			if (nbr > INT_MAX || nbr < INT_MIN)
				error_cmd(&head, NULL);
			stack_add_tail(&head, stack_new((int)nbr));
			i++;
		}
	}
	return (head);
}

void	assign_pos(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		max;

	while (--stack_size > 0)
	{
		max = INT_MIN;
		ptr = stack_a;
		highest = NULL;
		while (ptr)
		{
			if (ptr->data == INT_MIN && ptr->pos == 0)
				ptr->pos = 1;
			if (ptr->data > max && ptr->pos == 0)
			{
				max = ptr->data;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->link;
		}
		if (highest != NULL)
			highest->pos = stack_size;
	}
}

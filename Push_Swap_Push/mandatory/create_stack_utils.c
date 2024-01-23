/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:52:09 by rmohamma          #+#    #+#             */
/*   Updated: 2023/02/08 13:54:24 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_cmd(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || *stack_a)
		stack_clear(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		stack_clear(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

void	free_malloc(char **ptr_ptr)
{
	size_t	i;

	i = 0;
	while (ptr_ptr[i])
	{
		free(ptr_ptr[i]);
		i++;
	}
	free(ptr_ptr);
}

t_stack	*before_stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->link->link)
		stack = stack->link;
	return (stack);
}

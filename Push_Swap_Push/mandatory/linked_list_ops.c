/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_ops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:34:03 by rmohamma          #+#    #+#             */
/*   Updated: 2023/01/25 17:35:07 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = content;
	new_node->pos = 0;
	new_node->index = -1;
	new_node->mark_index = -1;
	new_node->move_a = -1;
	new_node->move_b = -1;
	new_node->link = NULL;
	return (new_node);
}

void	stack_add_tail(t_stack **stack, t_stack *new_node)
{
	if (!stack || !new_node)
		return ;
	if (!*stack)
		*stack = new_node;
	else
		stack_last(*stack)->link = new_node;
	return ;
}

t_stack	*stack_last(t_stack *stack)
{
	while (stack && stack->link)
		stack = stack->link;
	return (stack);
}

void	stack_clear(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->link;
		(*stack)->data = 0;
		(*stack)->index = 0;
		(*stack)->pos = 0;
		(*stack)->mark_index = 0;
		(*stack)->move_a = 0;
		(*stack)->move_b = 0;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	stack_size(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (stack)
	{
		stack = stack->link;
		i++;
	}
	return (i);
}

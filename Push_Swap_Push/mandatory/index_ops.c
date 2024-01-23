/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:51:29 by rmohamma          #+#    #+#             */
/*   Updated: 2023/02/02 14:51:34 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_mark_index_sub(t_stack **stack_a, int b_pos)
{
	t_stack	*tmp_a;
	int		mark_index;
	int		mark_pos;

	mark_pos = INT_MAX;
	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->pos < mark_pos)
		{
			mark_pos = tmp_a->pos;
			mark_index = tmp_a->index ;
		}
		tmp_a = tmp_a->link;
	}
	return (mark_index);
}

static int	find_mark_index_in_a(t_stack **stack_a, int b_pos)
{
	t_stack	*tmp_a;
	int		mark_index;
	int		mark_pos;

	mark_pos = INT_MAX;
	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->pos > b_pos && tmp_a->pos < mark_pos)
		{
			mark_pos = tmp_a->pos;
			mark_index = tmp_a->index;
		}
		tmp_a = tmp_a->link;
	}
	if (mark_pos != INT_MAX)
		return (mark_index);
	mark_index = find_mark_index_sub(stack_a, b_pos);
	return (mark_index);
}

static void	assign_element_index(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = NULL;
	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->link;
		i++;
	}
}

void	assign_mark_index_in_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		mark_index;

	tmp_b = NULL;
	tmp_b = *stack_b;
	assign_element_index(stack_a);
	assign_element_index(stack_b);
	while (tmp_b)
	{
		mark_index = find_mark_index_in_a(stack_a, tmp_b->pos);
		tmp_b->mark_index = mark_index;
		tmp_b = tmp_b->link;
	}
}

int	find_min_pos_index(t_stack **stack_a)
{
	t_stack	*tmp;
	int		min_index;
	int		min_pos;

	tmp = *stack_a;
	min_pos = INT_MAX;
	assign_element_index(stack_a);
	while (tmp)
	{
		if (tmp->pos < min_pos)
		{
			min_pos = tmp->pos;
			min_index = tmp->index ;
		}
		tmp = tmp->link;
	}
	return (min_index);
}

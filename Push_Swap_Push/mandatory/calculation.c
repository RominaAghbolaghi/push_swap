/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:29:27 by rmohamma          #+#    #+#             */
/*   Updated: 2023/02/03 11:29:42 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	element_move_each_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = stack_size(tmp_a);
	size_b = stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->move_b = tmp_b->index;
		if (tmp_b->index > size_b / 2)
			tmp_b->move_b = (size_b - tmp_b->index) * -1;
		tmp_b->move_a = tmp_b->mark_index;
		if (tmp_b->mark_index > size_a / 2)
			tmp_b->move_a = (size_a - tmp_b->mark_index) * -1;
		tmp_b = tmp_b->link;
	}
}

void	do_min_movement(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		min;
	int		move_a;
	int		move_b;

	tmp = *stack_b;
	min = INT_MAX;
	while (tmp)
	{
		if (absolute(tmp->move_a) + absolute(tmp->move_b) < min)
		{
			min = absolute(tmp->move_b) + absolute(tmp->move_a);
			move_a = tmp->move_a;
			move_b = tmp->move_b;
		}
		tmp = tmp->link;
	}
	move(stack_a, stack_b, move_a, move_b);
}

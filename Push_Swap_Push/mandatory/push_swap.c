/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:19:42 by rmohamma          #+#    #+#             */
/*   Updated: 2023/01/26 10:19:47 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_till_three(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushed;
	int	i;

	size = stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < (size / 2))
	{
		if (stack_a && (*stack_a)->pos <= (size / 2))
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

static void	rotate_stack(t_stack **stack_a)
{
	int	min_index;
	int	size;

	size = stack_size(*stack_a);
	min_index = find_min_pos_index(stack_a);
	if (min_index > size / 2)
	{
		while (min_index < size)
		{
			rra(stack_a);
			min_index++;
		}
	}
	else
	{
		while (min_index > 0)
		{
			ra(stack_a);
			min_index--;
		}
	}
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	push_till_three(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		assign_mark_index_in_b(stack_a, stack_b);
		element_move_each_stack(stack_a, stack_b);
		do_min_movement(stack_a, stack_b);
	}
	if (!sorted_check(*stack_a))
		rotate_stack(stack_a);
}

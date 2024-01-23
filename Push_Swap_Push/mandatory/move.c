/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:53:33 by rmohamma          #+#    #+#             */
/*   Updated: 2023/02/03 11:56:43 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rest_move_a(t_stack **stack_a, int *move_a)
{
	while (*move_a)
	{
		if (*move_a > 0)
		{
			ra(stack_a);
			(*move_a)--;
		}
		else if (*move_a < 0)
		{
			rra(stack_a);
			(*move_a)++;
		}
	}
}

static void	rest_move_b(t_stack **stack_b, int *move_b)
{
	while (*move_b)
	{
		if (*move_b > 0)
		{
			rb(stack_b);
			(*move_b)--;
		}
		else if (*move_b < 0)
		{
			rrb(stack_b);
			(*move_b)++;
		}
	}
}

static void	rotate_both(t_stack **stack_a, t_stack **stack_b,
						int *move_a, int *move_b)
{
	while (*move_a > 0 && *move_b > 0)
	{
		(*move_a)--;
		(*move_b)--;
		rr(stack_a, stack_b);
	}
}

static void	rev_rotate_both(t_stack **stack_a, t_stack **stack_b,
							int *move_a, int *move_b)
{
	while (*move_a < 0 && *move_b < 0)
	{
		(*move_a)++;
		(*move_b)++;
		rrr(stack_a, stack_b);
	}
}

void	move(t_stack **stack_a, t_stack **stack_b, int move_a, int move_b)
{
	if (move_a < 0 && move_b < 0)
		rev_rotate_both(stack_a, stack_b, &move_a, &move_b);
	else if (move_a > 0 && move_b > 0)
		rotate_both(stack_a, stack_b, &move_a, &move_b);
	rest_move_a(stack_a, &move_a);
	rest_move_b(stack_b, &move_b);
	pa(stack_a, stack_b);
}

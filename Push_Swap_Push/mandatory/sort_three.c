/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:28:44 by rmohamma          #+#    #+#             */
/*   Updated: 2023/02/02 14:37:34 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	highest_pos(t_stack *stack_a)
{
	int		max;

	max = stack_a->pos;
	while (stack_a)
	{
		if (stack_a->pos > max)
			max = stack_a->pos;
		stack_a = stack_a->link;
	}
	return (max);
}

void	sort_three(t_stack **stack_a)
{
	int		highest;

	highest = highest_pos(*stack_a);
	if ((*stack_a)->pos == highest)
		ra(stack_a);
	else if ((*stack_a)->link->pos == highest)
		rra(stack_a);
	if ((*stack_a)->pos > (*stack_a)->link->pos)
		sa(stack_a);
}

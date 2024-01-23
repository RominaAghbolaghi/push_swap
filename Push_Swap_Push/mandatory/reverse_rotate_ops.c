/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:04:07 by rmohamma          #+#    #+#             */
/*   Updated: 2023/02/03 15:04:26 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = stack_last(*head);
	before_tail = before_stack_last(*head);
	tmp = *head;
	*head = tail;
	(*head)->link = tmp;
	before_tail->link = NULL;
}

void	rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	pf_str("rra\n");
}

void	rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	pf_str("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	pf_str("rrr\n");
}

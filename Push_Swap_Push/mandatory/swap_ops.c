/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:06:29 by rmohamma          #+#    #+#             */
/*   Updated: 2023/02/02 14:10:33 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *head)
{
	int	tmp;

	if (head == NULL || head->link == NULL)
		return ;
	tmp = head->data;
	head->data = head->link->data;
	head->link->data = tmp;
	tmp = head->pos;
	head->pos = head->link->pos;
	head->link->pos = tmp;
}

void	sa(t_stack **stack_a)
{
	swap(*stack_a);
	pf_str("sa\n");
}

void	sb(t_stack **stack_b)
{
	swap(*stack_b);
	pf_str("sa\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	pf_str("ss\n");
}

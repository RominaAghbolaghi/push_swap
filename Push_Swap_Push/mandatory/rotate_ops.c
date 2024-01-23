/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:58:16 by rmohamma          #+#    #+#             */
/*   Updated: 2023/02/03 14:58:29 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **head)
{
	t_stack	*tmp;

	if (!*head || !(*head)->link)
		return ;
	tmp = *head;
	stack_last(*head)->link = tmp;
	*head = tmp->link;
	tmp->link = NULL;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	pf_str("ra\n");
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	pf_str("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	pf_str("rr\n");
}

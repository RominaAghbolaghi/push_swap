/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:49:31 by rmohamma          #+#    #+#             */
/*   Updated: 2023/02/15 09:49:37 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap(t_stack **head)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!*head || !((*head)->link))
		return ;
	tmp = *head;
	*head = (*head)->link;
	tmp->link = (*head)->link;
	(*head)->link = tmp;
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	tmp = NULL;
	if (*src == NULL)
		return ;
	tmp = (*src)->link;
	(*src)->link = *dest;
	*dest = *src;
	*src = tmp;
}

void	rotate(t_stack **head)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!*head || !(*head)->link)
		return ;
	tmp = *head;
	stack_last(*head)->link = tmp;
	*head = tmp->link;
	tmp->link = NULL;
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	rev_rotate(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	tmp = NULL;
	tail = NULL;
	before_tail = NULL;
	if (!*head || !(*head)->link)
		return ;
	tail = stack_last(*head);
	before_tail = before_stack_last(*head);
	tmp = *head;
	*head = tail;
	(*head)->link = tmp;
	before_tail->link = NULL;
}

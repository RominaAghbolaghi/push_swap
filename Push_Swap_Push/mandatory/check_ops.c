/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:26:14 by rmohamma          #+#    #+#             */
/*   Updated: 2023/01/25 17:26:59 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	comparing(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] && s2[j] && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

int	sorted_check(t_stack *stack_a)
{
	t_stack	*head;

	head = NULL;
	head = stack_a;
	if (!stack_a)
		return (0);
	while (head->link)
	{
		if (head->data > head->link->data)
			return (0);
		head = head->link;
	}
	return (1);
}

int	absolute(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

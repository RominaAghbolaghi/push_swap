/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:34:13 by rmohamma          #+#    #+#             */
/*   Updated: 2023/02/08 11:40:12 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	error_cmd2(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (!stack_a || *stack_a)
		stack_clear(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		stack_clear(stack_b);
	free(line);
	write(2, "Error\n", 6);
	exit (1);
}

static void	check_linux_sub(t_stack **a, t_stack **b, char *line)
{
	if (line[2] == 'a')
		rev_rotate(a);
	else if (line[2] == 'b')
		rev_rotate(b);
	else if (line[2] == 'r')
	{
		rev_rotate(a);
		rev_rotate(b);
	}
}

static void	checker_linux(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		swap(a);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		swap(b);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		push(b, a);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		push(a, b);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		rotate(a);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rotate(b);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		check_linux_sub(a, b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rotate_both(a, b);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
	{
		swap(a);
		swap(b);
	}
	else
		error_cmd2(a, b, line);
}

void	checker(t_stack **a, t_stack **b, char *line)
{
	char	*tmp;

	tmp = NULL;
	while (line && *line != '\n')
	{
		tmp = line;
		checker_linux(a, b, line);
		line = get_next_line(0);
		free(tmp);
	}
	if (*b)
		write(1, "KO\n", 3);
	else if (!sorted_check(*a))
		write(1, "KO\n", 3);
	else if (!*b && sorted_check(*a))
		write(1, "OK\n", 3);
	free(line);
}

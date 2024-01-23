/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:04:50 by rmohamma          #+#    #+#             */
/*   Updated: 2023/02/17 16:05:18 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_a) == 2)
		sa(stack_a);
	else if (stack_size(*stack_a) == 3)
		sort_three(stack_a);
	else if (stack_size(*stack_a) > 3)
		push_swap(stack_a, stack_b);
}

static int	quote_cmd(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (!argv_valid(argv, argc))
	{	
		free_malloc(argv);
		error_cmd(&a, &b);
	}	
	a = create_stack_a(argc, argv);
	free_malloc(argv);
	size = stack_size(a);
	assign_pos(a, size + 1);
	if (!sorted_check(a))
		sort_stack(&a, &b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;
	int		i;

	i = 1;
	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		return (quote_cmd(argc, argv));
	}
	if (!argv_valid(argv, argc))
		error_cmd(&a, &b);
	a = create_stack_a(argc, argv);
	size = stack_size(a);
	assign_pos(a, size + 1);
	if (!sorted_check(a))
		sort_stack(&a, &b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:36:36 by rmohamma          #+#    #+#             */
/*   Updated: 2023/02/21 14:36:39 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	quote_cmd(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	int		size;
	//int j=0;

	a = NULL;
	argv = ft_split(argv[1], ' ');
	/*while (argv[j])
	{
		printf("%s\n", argv[j]);
		j++;
	}*/
	if (!argv_valid(argv, argc))
	{	
		free_malloc(argv);
		error_cmd(NULL, NULL);
	}	
	b = NULL;
	a = create_stack_a(argc, argv);
	free_malloc(argv);
	size = stack_size(a);
	assign_pos(a, size + 1);
	line = get_next_line(0);
	if (!line && !sorted_check(a))
		error_cmd(&a, &b);
	else
		checker(&a, &b, line);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}

static int	more_three_argv(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	int		size;
	int		i;

	i = 1;
	a = NULL;
	if (!argv_valid(argv, argc))
		error_cmd(NULL, NULL);
	b = NULL;
	a = create_stack_a(argc, argv);
	size = stack_size(a);
	assign_pos(a, size + 1);
	line = get_next_line(0);
	if (!line && !sorted_check(a))
		error_cmd(&a, &b);
	else
		checker(&a, &b, line);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	int		size;
	int		i;

	i = 1;
	a = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
		return (quote_cmd(argc, argv));
	else
		return (more_three_argv(argc, argv));
}

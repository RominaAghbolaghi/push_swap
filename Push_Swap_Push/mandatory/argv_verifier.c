/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_verifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:11:47 by rmohamma          #+#    #+#             */
/*   Updated: 2023/02/17 16:12:27 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(char *argv)
{
	int	i;

	i = 0;
	if (!argv[i])
		return (0);
	if ((argv[i] == '-' || argv[i] == '+') && argv[i + 1])
		i++;
	while (argv[i] && ft_isdigit(argv[i]))
		i++;
	if (argv[i] && !ft_isdigit(argv[i]))
		return (0);
	return (1);
}

static int	zero_num(char *argv)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	if ((argv[i] == '-' || argv[i] == '+'))
		i++;
	while (argv[i] && argv[i] == '0')
	{
		i++;
		num++;
	}	
	if (argv[i])
		return (0);
	return (num);
}

static int	dup_check(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && comparing(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	argv_valid(char **argv, int argc)
{
	int	i;
	int	num;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	num = 0;
	if (!argv[i])
		return (0);
	while (argv[i])
	{
		if (!is_number(argv[i]))
			return (0);
		num += zero_num(argv[i]);
		i++;
	}
	if (num > 1)
		return (0);
	if (dup_check(argv))
		return (0);
	return (1);
}

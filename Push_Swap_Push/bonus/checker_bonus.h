/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:54:36 by rmohamma          #+#    #+#             */
/*   Updated: 2023/02/09 16:35:37 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <unistd.h>
# include "../mandatory/push_swap.h"
# include "../GNL/get_next_line.h"

//void	checker_linux(t_stack **a, t_stack **b, char *line);
//void	check_linux_sub(t_stack **a, t_stack **b, char *line);
void	checker(t_stack **a, t_stack **b, char *line);
void	swap(t_stack **head);
void	push(t_stack **src, t_stack **dest);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **head);
void	rev_rotate(t_stack **head);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:01:29 by rmohamma          #+#    #+#             */
/*   Updated: 2023/01/25 13:27:29 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>//symbolic constants and types,The values shall be suitable 
				//for use in #if
# include <stddef.h>//contains definitions of the commonly used pointers, 
				//variables, and types, from the typedef statements
# include <stdio.h>// t reads the character from the file.print on the output
				//reads from the keyboard 
# include <stdlib.h> // malloc() and free() exit()
# include <stdbool.h> //true which expands to 1
				//false which expands to 0
# include "../libft/libft.h" 

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef INT_MAX//checks whether a macro is not defined.
#  define INT_MAX 2147483647
# endif

typedef struct new_node
{
	int				data;
	int				index;
	int				pos;
	int				mark_index;
	int				move_a;
	int				move_b;
	struct new_node	*link;
}t_stack;

t_stack	*create_stack_a(int argc, char **argv);
t_stack	*stack_new(int content);
t_stack	*stack_last(t_stack *stack);
t_stack	*before_stack_last(t_stack *stack);

void	assign_pos(t_stack *stack_a, int stack_size);
void	error_cmd(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack_a);
void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	element_move_each_stack(t_stack **stack_a, t_stack **stack_b);
void	do_min_movement(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	move(t_stack **stack_a, t_stack **stack_b, int move_a, int move_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	stack_add_tail(t_stack **stack, t_stack *new_node);
void	stack_clear(t_stack **stack);
void	assign_mark_index_in_b(t_stack **stack_a, t_stack **stack_b);
void	free_malloc(char **ptr_ptr);

int		stack_size(t_stack *stack);
int		sorted_check(t_stack *stack_a);
int		absolute(int nbr);
int		find_min_pos_index(t_stack **stack_a);
int		argv_valid(char **argv, int argc);
int		comparing(const char *s1, const char *s2);

#endif

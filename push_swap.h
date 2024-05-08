/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:40:32 by mgering           #+#    #+#             */
/*   Updated: 2024/05/08 16:34:34 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> //!!!!delete later
# include <stdbool.h>
# include <limits.h>
# include "lib/libft/libft.h"

typedef struct stack_list
{
	int					value;
	int					current_position;
	bool				split;
	bool				smallest3rd;
	struct stack_list	*target_node;
	struct stack_list	*next;
	struct stack_list	*prev;
}	t_stack;

//initialize
int		main(int argc, char **argv);
void	init_stack_a(t_stack **a, char **argv);
bool	init_pos_split(t_stack **node);
int		set_smallest_third(t_stack *node);
int		how_many_smallest_third(t_stack *node);
int		mid_node(t_stack *b);
bool 	where(t_stack *a, t_stack *b);

//sort
void	test_sort(t_stack **a);
void	small_sort(t_stack **a);
void	sort_pseudo(t_stack **a);
bool	a_sorted(t_stack *a);
bool	pseudo_sorted(t_stack *node);
void	start_sort_b(t_stack **a, t_stack **b);
void	push_back(t_stack **a, t_stack **b);
bool	from_above(t_stack	*b);

//stack_utils
t_stack	*find_last(t_stack *node);
t_stack	*find_first(t_stack **node);
t_stack	*find_max_node(t_stack *node);
t_stack	*find_min_node(t_stack *node);
int		refresh_current_pos(t_stack *node);

//errors
void	free_stack(t_stack **stack);
int		error_syntax(char *str);
int		error_duplicate(t_stack *stack, int nbr);
void	error_occured(t_stack **a);

//commands
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

#endif
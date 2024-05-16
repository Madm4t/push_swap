/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:40:32 by mgering           #+#    #+#             */
/*   Updated: 2024/05/16 18:12:25 by mgering          ###   ########.fr       */
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

//push_swap
int		main(int argc, char **argv);

//big_sort + utils
int		find_place_b(t_stack *a, t_stack *b);
bool	where(t_stack *b);
void	start_sort_b(t_stack **a, t_stack **b);

//init_stack
bool	init_pos_split(t_stack **node);
void	init_stack_a(t_stack **a, char **argv);

//is_sorted
bool	is_sorted(t_stack *a);
bool	pseudo_sorted(t_stack *node);

//smallest_num
void	set_smallest(t_stack *node);
int		how_many_smallest(t_stack *node);
t_stack	*upper_3rd(t_stack *a);

//sort
void	small_sort(t_stack **a);
void	test_sort(t_stack **a);
void	push_back(t_stack **a, t_stack **b);
void	sort_pseudo_a(t_stack **a);

//stack_utils
t_stack	*find_last(t_stack *node);
t_stack	*find_first(t_stack *node);
t_stack	*max(t_stack *node);
t_stack	*min(t_stack *node);
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
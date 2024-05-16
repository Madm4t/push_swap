/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:42:33 by mgering           #+#    #+#             */
/*   Updated: 2024/05/16 18:19:18 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	small_sort(t_stack **a)
{
	t_stack	*biggest;

	biggest = max(*a);
	if (biggest == *a)
		ra(a);
	else if (biggest == (*a)->next)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
	return ;
}

void	test_sort(t_stack **a)
{
	t_stack	*b_stack;
	t_stack	**b;

	b_stack = NULL;
	b = &b_stack;
	if (3 == find_last(*a)->current_position)
		small_sort(a);
	else if (is_sorted(*a))
		return ;
	else
	{
		start_sort_b(a, b);
		while (*b && (find_last(*b)->value > (*b)->value))
			rrb(b);
		small_sort(a);
		push_back(a, b);
		sort_pseudo_a(a);
	}
	return ;
}

void	push_back(t_stack **a, t_stack **b)
{
	if (!b)
		return ;
	while (*b)
	{
		while ((find_last(*a)->value > (*b)->value && find_last(*a)->value
				< (*a)->value) || (*b)->value > (*a)->value)
			rra(a);
		pa(a, b);
	}
	return ;
}

void	sort_pseudo_a(t_stack **a)
{
	if (is_sorted(*a))
		return ;
	else if (pseudo_sorted(*a))
	{
		if (init_pos_split(a))
		{
			while (!is_sorted(*a))
				rra(a);
		}
		else
		{
			while (!is_sorted(*a))
				ra(a);
		}
		return ;
	}
}

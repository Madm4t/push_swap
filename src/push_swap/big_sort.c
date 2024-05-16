/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:19:46 by mgering           #+#    #+#             */
/*   Updated: 2024/05/16 18:13:02 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	handle_small_num(t_stack **a, t_stack **b);
static void	handle_between(t_stack **a, t_stack **b, int flag);
static void	handle_smallest_min_max(t_stack **b);
static void	handle_not_smallest(t_stack **a, t_stack **b);

void	start_sort_b(t_stack **a, t_stack **b)
{
	if (!a)
		return ;
	while (!pseudo_sorted(*a))
	{
		refresh_current_pos(*b);
		set_smallest(*a);
		if ((*a)->smallest3rd)
		{
			if (!*b)
				pb(b, a);
			else if (!(*b)->next)
				pb(b, a);
			else
				handle_small_num(a, b);
		}
		else
			handle_not_smallest(a, b);
	}
}

static void	handle_small_num(t_stack **a, t_stack **b)
{
	if ((*a)->value > (*b)->next->value && (*a)->value < (*b)->value)
	{
		pb(b, a);
		if ((*a)->value > (*a)->next->value)
			ss(a, b);
		else
			sb(b);
	}
	else if ((*a)->value > (*a)->next->value)
		sa(a);
	else if ((*a)->value > max(*b)->value || (*a)->value < min(*b)->value)
	{
		handle_smallest_min_max(b);
		pb(b, a);
	}
	else if (find_place_b(*a, *b) > 0)
	{
		handle_between(a, b, 1);
		pb(b, a);
	}
	else
	{
		handle_between(a, b, 0);
		pb(b, a);
	}
}

static void	handle_between(t_stack **a, t_stack **b, int flag)
{
	if (1 == flag)
	{
		while (!((*a)->value > (*b)->value
				&& (*a)->value < find_last(*b)->value))
			rb(b);
	}
	else
	{
		while (!((*a)->value > (*b)->value
				&& (*a)->value < find_last(*b)->value))
			rrb(b);
	}
}

static void	handle_smallest_min_max(t_stack **b)
{
	if (where(*b))
	{
		while ((*b)->value < find_last(*b)->value)
			rb(b);
	}
	else
	{
		while ((*b)->value < find_last(*b)->value)
			rrb(b);
	}
}

static void	handle_not_smallest(t_stack **a, t_stack **b)
{
	if ((*a)->next->value > find_last(*a)->value
		&& (*a)->value > (*a)->next->value)
		sa(a);
	else if (find_place_b(upper_3rd(*a), *b) > 0
		&& !(upper_3rd(*a)->value > max(*b)->value
			|| upper_3rd(*a)->value < min(*b)->value)
		&& max(*b)->current_position == 1)
		rr(a, b);
	else
		ra(a);
}

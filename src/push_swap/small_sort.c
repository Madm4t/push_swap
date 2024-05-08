/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:42:33 by mgering           #+#    #+#             */
/*   Updated: 2024/05/08 17:52:50 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	small_sort(t_stack **a)
{
	t_stack	*biggest;

	biggest = find_max_node(*a);
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
	t_stack *b_stack;
	t_stack **b = &b_stack;

	b_stack = NULL;
	if (3 == find_last(*a)->current_position)
		small_sort(a);
	else if (a_sorted(*a))
		return ;
	else
	{
		start_sort_b(a, b);
		if (3 == set_smallest_third(*a))
			small_sort(a);
		else
			sort_pseudo(a);
		if (from_above(*b))
		{
			while ((*b)->value < find_last(*b)->value)
				rrb(b);
		}
		else
		{
			while ((*b)->value < find_last(*b)->value)
				rb(b);
		}
		push_back(a, b);
	}
	return ;
}

void	sort_pseudo(t_stack **a)
{
	if (a_sorted(*a))
		return ;
	else if (pseudo_sorted(*a))
	{
		if (init_pos_split(a))
		{
			while (!a_sorted(*a))
				rra(a);
		}
		else
		{
			while (!a_sorted(*a))
				ra(a);
		}
		return ;
	}
}

void	start_sort_b(t_stack **a, t_stack **b)
{
	int	flag;

	flag = 0;
	if (!a)
		return ;
	while (!pseudo_sorted(*a))
	{
		find_first(a);
		set_smallest_third(*a);
		int i = (*a)->value;
		printf("value:%d flag:%d\n", i, flag);
		if ((*a)->smallest3rd)
		{
 			if (flag == 1)
			{
				if ((*a)->value > find_max_node(*b)->value)
				{
					if (where(*a, *b))
					{
						while (find_max_node(*b)->current_position != 1)
							rb(b);
					}
					else
					{
						while (find_max_node(*b)->current_position != 1)
							rrb(b);
					}
				}
				else if (where(*a, *b))
				{
					while ((*a)->value < (*b)->next->value)
						rb(b);
				}
				else
				{
					while ((*a)->value > find_last(*b)->value)
						rrb(b);
				}
				pb(b, a);
				if (find_max_node(*b)->current_position == 1)
					flag = 0;
			}
			if ((*a)->value < (*a)->next->value)
			{
				if (!*b)
					pb(b, a);
				else if ((*a && (*a)->value > (*b)->value))
					pb(b, a);
				else
				{
					if ((*a)->value < find_last(*b)->value)
					{
						pb(b, a);
						if ((*a)->value > (*a)->next->value)
						{
							if ((*b)->value > (*b)->next->value)
								ss(a, b);
							else
								rr(a, b);
						}
						else
							rb(b);
					}
					else if ((*a)->value > (*b)->next->value)
					{
						pb(b, a);
						if ((*a)->value > (*a)->next->value)
							ss(a, b);
						else
							sb(b);
					}
					else
					{
						flag = 1;
						if ((*a)->value > mid_node(*b))
						{
							rb(b);
							while ((*a)->value < (*b)->value)
								rb(b);
						}
						else
						{
							rrb(b);
							while ((*a)->value > (*b)->value && (*a)->value > find_last(*b)->value)
								rrb(b);
						}
						pb(b, a);
					}
				}
			}
			else
				sa(a);
		}
		else
		{
			if ((*a)->value < (*a)->next->value)
				ra(a);
			else
			{
				if ((*a)->next->smallest3rd)
				{
					if ((*a)->value > find_last(*a)->value)
						ra(a);
					else
						sa(a);
				}
				else if ((*a)->next->value < find_last(*a)->value)
					ra(a);
				else
				{
					sa(a);
					ra(a);
				}
			}
		}
	}
}

void	push_back(t_stack **a, t_stack **b)
{
	if (!b)
		return ;
	while (*b)
	{
		pa(a, b);
	}
	return ;
}

bool	from_above(t_stack	*b)
{
	int	total_nodes;

	total_nodes = find_last(b)->current_position;
	total_nodes /= 2;
	refresh_current_pos(b);
	if (find_max_node(b)->current_position > total_nodes)
		return (true);
	return (false);
}

int	mid_node(t_stack *b)
{
	int	total_nodes;

	total_nodes = find_last(b)->current_position;
	total_nodes /= 2;
	refresh_current_pos(b);
	while (total_nodes > 0)
	{
		b = b->next;
		total_nodes -= 1;
	}
	return (b->value);
}


bool where(t_stack *a, t_stack *b)
{
	t_stack *temp;
	int	i;
	int	j;

	temp = b;
	i = 0;
	j = 0;
	while (a->value < temp->value && temp->next)
	{
		temp = temp->next;
		i++;
	}
	temp = find_last(b);
	while (a->value < temp->value && temp->prev)
	{
		temp = temp->prev;
		j++;
	}
	if (i < j)
		return (true);
	return (false);
}

int find_target_down(t_stack *a, t_stack *b)
{
	int	flag;
	int	set;
	int	i;

	flag = 0;
	set = 0;
	i = 0;
	while (b->next)
	{
		if (a->value < b->value)
			flag = 1;
		if (a->value > b->next->value)
			set = 1;
		if (flag == 1 && set == 1)
			return (i);
		i++;
	}
	return (0);
}

int find_target_up(t_stack *a, t_stack *b)
{
	int	flag;
	int	set;
	int	i;

	flag = 0;
	set = 0;
	i = 0;
	while (b->next)
	{
		if (a->value < b->value)
			flag = 1;
		if (a->value > b->next->value)
			set = 1;
		if (flag == 1 && set == 1)
			return (i);
		i++;
	}
	return (0);
}
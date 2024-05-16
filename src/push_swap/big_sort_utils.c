/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:48:01 by mgering           #+#    #+#             */
/*   Updated: 2024/05/16 18:15:32 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	find_place_b(t_stack *a, t_stack *b)
{
	t_stack	*temp;
	int		i;
	int		j;

	if (!b || !b->next)
		return (0);
	temp = b;
	i = 1;
	j = 1;
	while (!(a->value > temp->next->value && a->value < temp->value) && i++)
	{
		if (!temp->next->next)
			break ;
		temp = temp->next;
	}
	temp = find_last(b);
	while (!(a->value > temp->value && a->value < temp->prev->value) && j++)
	{
		if (!temp->prev->prev)
			break ;
		temp = temp->prev;
	}
	if (i <= j)
		return (i);
	return (-j);
}

bool	where(t_stack *b)
{
	int		total_half_nodes;

	total_half_nodes = find_last(b)->current_position / 2;
	if (max(b)->current_position <= total_half_nodes)
		return (true);
	return (false);
}

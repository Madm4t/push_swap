/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 23:58:35 by mgering           #+#    #+#             */
/*   Updated: 2024/05/16 18:07:48 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	set_smallest(t_stack *node)
{
	t_stack	*smallest_num;
	int		temp;
	int		count;

	count = find_last(node)->current_position;
	count = count / ((count / 20) + 2) - how_many_smallest(node);
	while (count > 0)
	{
		node = find_first(node);
		smallest_num = NULL;
		temp = INT_MAX;
		while (node->next)
		{
			if (!(node->smallest3rd) && node->value < temp)
			{
				temp = node->value;
				smallest_num = node;
			}
			node = node->next;
		}
		if (smallest_num)
			smallest_num->smallest3rd = true;
		count--;
	}
}

int	how_many_smallest(t_stack *node)
{
	int	i;

	i = 0;
	while (node)
	{
		if (node->smallest3rd)
			i++;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (i);
}

t_stack	*upper_3rd(t_stack *a)
{
	t_stack	*temp;

	temp = a;
	if (!a)
		return (NULL);
	refresh_current_pos(temp);
	set_smallest(temp);
	while (!(temp->smallest3rd) && temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}

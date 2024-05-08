/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:28:47 by mgering           #+#    #+#             */
/*   Updated: 2024/05/03 19:49:41 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*find_last(t_stack *node)
{
	refresh_current_pos(node);
	if (!node)
		return (NULL);
	while (node->next != NULL)
	{
		node = node->next;
	}
	return (node);
}

t_stack	*find_first(t_stack **node)
{
	refresh_current_pos(*node);
	if (!(*node))
		return (NULL);
	while ((*node)->prev != NULL)
	{
		*node = (*node)->prev;
	}
	return (*node);
}

t_stack	*find_max_node(t_stack *node)
{
	t_stack	*max_node;
	int		max_value;

	max_node = node;
	max_value = node->value;
	refresh_current_pos(node);
	while (node->next)
	{
		if (max_value < node->next->value)
		{
			max_value = node->next->value;
			max_node = node->next;
		}
		node = node->next;
	}
	return (max_node);
}

t_stack	*find_min_node(t_stack *node)
{
	t_stack	*min_node;
	int		min_value;

	min_node = node;
	min_value = node->value;
	refresh_current_pos(node);
	while (node->next)
	{
		if (min_value > node->next->value)
		{
			min_value = node->next->value;
			min_node = node->next;
		}
		node = node->next;
	}
	return (min_node);
}

int	refresh_current_pos(t_stack *node)
{
	int	i;

	i = 1;
	while (node)
	{
		node->current_position = i;
		node = node->next;
		i++;
	}
	return (i);
}

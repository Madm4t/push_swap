/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:11:49 by mgering           #+#    #+#             */
/*   Updated: 2024/05/02 17:55:37 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

bool	a_sorted(t_stack *a)
{
	if (!a)
		return (true);
	while (a->next)
	{
		if (a->value < a->next->value)
			a = a->next;
		else
			return (false);
	}
	return (true);
}



bool	pseudo_sorted(t_stack *node)
{
	int	flag;

	flag = 0;
	if (!node)
		return (true);
	while (node->next && flag < 2)
	{
		if (node->value > node->next->value)
		{
			flag++;
			node->split = true;
			if (find_first(&node)->value < find_last(node)->value)
				return (false);
			node = node->next;
			if (flag == 2)
				return (false);
		}
		else if (node->value < node->next->value)
			node = node->next;
	}
	if (!node->next)
		return (true);
	return (false);
}

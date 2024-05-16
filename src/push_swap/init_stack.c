/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:37:51 by mgering           #+#    #+#             */
/*   Updated: 2024/05/12 23:58:50 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	result = result * sign;
	return (result);
}

static void	build_stack_a(t_stack **a, int num, int *i)
{
	t_stack	*node;
	t_stack	*last_node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->value = num;
	node->current_position = *i;
	node->smallest3rd = false;
	node->split = false;
	if (!(*a))
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*a);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_stack **a, char **argv)
{
	long	num;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
		{
			write(2, "Error\n", 6);
			error_occured(a);
		}
		num = ft_atol(argv[i]);
		if (INT_MIN > num || INT_MAX < num)
		{
			write(2, "Error\n", 6);
			error_occured(a);
		}
		if (error_duplicate(*a, (int)num))
			error_occured(a);
		i++;
		build_stack_a(a, (int)num, &i);
	}
	*a = find_first(*a);
}

bool	init_pos_split(t_stack **node)
{
	int	total_nodes;
	int	split_pos;

	total_nodes = 0;
	split_pos = 0;
	*node = find_first(*node);
	while ((*node)->next)
	{
		(*node)->current_position = ++total_nodes;
		if ((*node)->split)
			split_pos = (*node)->current_position;
		*node = (*node)->next;
	}
	*node = find_first(*node);
	if (split_pos > (total_nodes / 2))
		return (true);
	else
		return (false);
}

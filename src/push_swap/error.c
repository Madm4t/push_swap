/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:56:41 by mgering           #+#    #+#             */
/*   Updated: 2024/05/12 22:47:49 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	*stack = find_first(*stack);
	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

int	error_syntax(char *str)
{
	if (!('+' == *str || '-' == *str || ('0' <= *str && '9' >= *str)))
		return (1);
	if (('+' == *str || '-' == *str) && ('0' > *(str + 1) || '9' < *(str + 1)))
		return (1);
	while (*++str)
	{
		if ('0' > *str || '9' < *str)
			return (1);
	}
	return (0);
}

int	error_duplicate(t_stack *stack, int nbr)
{
	if (!(stack))
		return (0);
	while (stack)
	{
		if ((stack)->value == nbr)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		stack = stack->next;
	}
	return (0);
}

void	error_occured(t_stack **a)
{
	free_stack(a);
	exit(1);
}

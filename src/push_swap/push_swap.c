/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:34:33 by mgering           #+#    #+#             */
/*   Updated: 2024/05/13 00:28:52 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	a = NULL;
	i = 0;
	if (1 == argc || (2 == argc && !argv[1][0]))
		return (0);
	else if (2 == argc)
	{
		argv = ft_split(argv[1], ' ');
		init_stack_a(&a, argv);
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	else if (2 < argc)
		init_stack_a(&a, argv + 1);
	test_sort(&a);
	free_stack(&a);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:54:22 by mgering           #+#    #+#             */
/*   Updated: 2023/10/25 17:04:46 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The isdigit() function tests for a decimal digit character.
Regardless of locale, this includes the following characters only:
0, 1, 2, 3, 4, 5, 6, 7, 8, 9 */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
int main()
{
    printf("\nisdigit: %d", ft_isdigit('0'));
}
*/
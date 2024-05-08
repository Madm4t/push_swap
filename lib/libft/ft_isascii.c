/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:11:58 by mgering           #+#    #+#             */
/*   Updated: 2023/10/26 14:05:16 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The isascii() function tests for an ASCII character,
which is any character between 0 and dec 255 inclusive. */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
int main()
{
    printf("\nisascii: %d", ft_isascii('='));
}
*/
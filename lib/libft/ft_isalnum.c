/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:02:11 by mgering           #+#    #+#             */
/*   Updated: 2023/10/25 17:06:03 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The isalnum() function tests for any character for which
isalpha(3) or isdigit(3) is true.
The value of the argument must be representable
as an unsigned char or the value of EOF */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
int main()
{
    printf("/nisalnum: %d", ft_isalnum('g'));
}
*/
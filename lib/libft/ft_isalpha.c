/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:01:57 by mgering           #+#    #+#             */
/*   Updated: 2023/10/25 17:03:10 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The isalpha() function tests for any character
for which isupper(3) or islower(3) is true.
The value of the argument must be representable
as an unsigned char or the value of EOF. */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
int main()
{
    printf("\nvalue isalpha = %d", ft_isalpha('A'));
    printf("\nvalue isalpha = %d", ft_isalpha('Z'));
    printf("\nvalue isalpha = %d", ft_isalpha('a'));
    printf("\nvalue isalpha = %d", ft_isalpha('z'));
    printf("\nvalue isalpha = %d", ft_isalpha('['));
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:09:23 by mgering           #+#    #+#             */
/*   Updated: 2023/10/25 17:25:32 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The tolower() function converts an upper-case letter to
the corresponding lower-case letter.  The argument must be
representable as an unsigned char or the value of EOF. */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		return (c + 32);
	else
		return (c);
}

/* #include <stdio.h>
#include <ctype.h>

int main() 
{
    char lowercase = 'Z';
    char uppercase;

    uppercase = ft_tolower(lowercase);

    printf("Lowercase character: %c\n", lowercase);
    printf("Uppercase character: %c\n", uppercase);

    return 0;
} */ 
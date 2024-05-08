/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:58:17 by mgering           #+#    #+#             */
/*   Updated: 2023/10/25 17:24:54 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The toupper() function converts a lower-case letter to
the corresponding upper-case letter.  The argument must be
representable as an unsigned char or the value of EOF. */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		return (c - 32);
	else
		return (c);
}

/* #include <stdio.h>
#include <ctype.h>

int main() {
    char lowercase = 'd';
    char uppercase;

    uppercase = ft_toupper(lowercase);

    printf("Lowercase character: %c\n", lowercase);
    printf("Uppercase character: %c\n", uppercase);

    return 0;
} */
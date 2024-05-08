/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:46:42 by mgering           #+#    #+#             */
/*   Updated: 2023/10/25 17:19:56 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The bzero() function writes n zeroed bytes to the string s.
If n is zero, bzero() does nothing. */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n > 0)
	{
		*ptr++ = '\0';
		n--;
	}
}

/* #include <stdio.h>

int main () {
	char str[50] = "This is ft_bzero function";
	ft_bzero(str, 8);
	printf("ft_bezero: %c", str[8]);
	return(0);
}  */
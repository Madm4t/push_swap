/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:02:18 by mgering           #+#    #+#             */
/*   Updated: 2023/10/26 16:24:56 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The memchr() function locates the first occurrence of c
(converted to an unsigned char) in string s.
The memchr() function returns a pointer to the byte
located, or NULL if no such byte exists within n bytes.*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		if (*ptr == (unsigned char) c)
			return (ptr);
		ptr++;
		n--;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
    const char *text = "This is a sample text.";
    char target = 's';

    if (result != NULL) {
        size_t position = (size_t)(result - (const void *)text);
        printf("Character '%c' found at position %zu.\n", target, position);
    } else {
        printf("Character '%c' not found.\n", target);
    }

    return 0;
}  */

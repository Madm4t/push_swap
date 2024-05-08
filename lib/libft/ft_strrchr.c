/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:17:03 by mgering           #+#    #+#             */
/*   Updated: 2023/10/26 15:45:42 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strchr() function locates the last occurrence of c
(converted to a char) in the string pointed to by s.
The terminating null character is considered to be
part of the string; therefore if c is `\0', the
functions locate the terminating `\0'. */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	while (*s != '\0')
	{
		if ((unsigned char)c == (unsigned char)*s)
			ptr = (char *)s;
		s++;
	}
	if ((unsigned char)c == (unsigned char)*s)
		ptr = (char *)s;
	return (ptr);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
    const char *str = "Hello, World!";
    char target = 'o';

    const char *result = ft_strrchr(str, target);

    if (result != NULL) {
        printf("The char '%c' was found at pos %ld\n", target, result - str);
    } else {
        printf("The char '%c' was not found in the string.\n", target);
    }

    return 0;
} */
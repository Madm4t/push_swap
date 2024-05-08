/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:17:03 by mgering           #+#    #+#             */
/*   Updated: 2023/11/01 12:08:22 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strchr() function locates the first occurrence of c
(converted to a char) in the string pointed to by s.
The terminating null character is considered to be
part of the string; therefore if c is `\0', the
functions locate the terminating `\0'. */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

/* #include <stdio.h>
#include <string.h>

int main() {
    const char *str = "";
    char target = '\0';

    const char *result = ft_strchr(str, target);

    if (result != NULL) {
        printf("The char'%c' was found at pos %lu\n", target, result - str);
    } else {
        printf("The char '%c' was not found in the string.\n", target);
    }

    return 0;
} */
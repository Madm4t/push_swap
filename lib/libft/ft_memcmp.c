/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:26:29 by mgering           #+#    #+#             */
/*   Updated: 2023/10/26 16:29:08 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The memcmp() function compares byte string s1 against
byte string s2.  Both strings are assumed to be n bytes long.
The memcmp() function returns zero if the two strings are identical,
otherwise returns the difference between the first two differing bytes.*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	i = 0;
	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (temp_s1[i] == temp_s2[i])
			i++;
		else
			return (temp_s1[i] - temp_s2[i]);
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
    const char *str1 = "Hello";
    const char *str2 = "Hello";
    size_t size = 5; // Number of bytes to compare

    int result = ft_memcmp(str1, str2, size);

    if (result == 0) {
        printf("The first %zu bytes oare equal.\n", size);
    } else if (result < 0) {
        printf("The first %zu bytes of str1 are less than str2.\n", size);
    } else {
        printf("The first %zu bytes of str1 are greater than str2.\n", size);
    }

    return 0;
}
*/
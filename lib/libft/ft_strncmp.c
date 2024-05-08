/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:12:21 by mgering           #+#    #+#             */
/*   Updated: 2023/11/08 16:48:20 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strncmp() function compares not more than n characters.
Because strncmp() is designed for comparing strings rather
than binary data, characters that appear after a `\0'
character are not compared. */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((unsigned char)*s1 == (unsigned char)*s2 && *s1 != '\0' && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/* #include <stdio.h>
#include <string.h>

int main() {
    const char *str1 = "abcdefgh";
    const char *str2 = "abcdwxyz";
    int num_chars_to_compare = 4; // Number of characters to compare

    int result = ft_strncmp(str1, str2, num_chars_to_compare);

    if (result == 0) {
        printf("equal%d\n", num_chars_to_compare);
    } else if (result < 0) {
        printf("str1  less than str2.\n");
    } else {
        printf("str1  greater than str2.\n");
    }

    return 0;
} */
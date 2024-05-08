/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:36:25 by mgering           #+#    #+#             */
/*   Updated: 2023/11/08 17:16:59 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strnstr() function locates the first occurrence of
the null-terminated string needle in the string haystack,
where not more than len characters are searched.
Characters that appear after a `\0' character are not searched.
If needle is an empty string, haystack is returned;
if needle occurs nowhere in haystack, NULL is returned;
otherwise a pointer to the first character of the first
occurrence of needle is returned.*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!needle[0])
		return ((char *)haystack);
	else
	{
		while (haystack[i] != '\0' && (i + j) < len)
		{
			j = 0;
			while (haystack[i + j] == needle[j] && (i + j) < len)
			{
				j++;
				if (needle[j] == '\0')
					return ((char *)haystack + (i));
			}
			i++;
		}
		return (NULL);
	}
}

/* #include <stdio.h>
#include <string.h>

int main() {
    const char *haystack = "fghijabcde";
    const char *needle = "abcd";
    size_t length = 9;
    
    char* result = strnstr(haystack, needle, length);
    char* ft_result = ft_strnstr(haystack, needle, length);
    
    printf("strnstr: %s\n", result);
    printf("ft_strnstr: %s\n", ft_result);
    return 0;
} */
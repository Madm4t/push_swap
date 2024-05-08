/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:43:48 by mgering           #+#    #+#             */
/*   Updated: 2024/04/20 16:54:20 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns a copy of ’s1’
with the characters specified in ’set’ removed
from the beginning and the end of the string.
s1: The string to be trimmed.
set: The reference set of characters to trim.*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]) && s1[end - 1])
		end--;
	ptr = malloc((end - start + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	if (ptr)
		ft_strlcpy(ptr, &s1[start], (end - start + 1));
	return (ptr);
}

/* #include <stdio.h>

int main()
{
	char *new_string = ft_strtrim("abcd", "d");
	printf("%s\n", new_string);
	printf("%c=%p\n", new_string[3], &new_string[3]);
	printf("%c=%p\n", new_string[4], &new_string[4]);
} */
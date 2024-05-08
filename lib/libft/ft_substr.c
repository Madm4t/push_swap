/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:59:51 by mgering           #+#    #+#             */
/*   Updated: 2023/10/31 12:03:22 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns a substring from the string ’s’.
The substring begins at index ’start’ and is of maximum size ’len’.
s: The string from which to create the substring.
start: The start index of the substring in the string ’s’.
len: The maximum length of the substring. */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	str_len;
	char	*ptr;

	i = 0;
	str_len = ft_strlen(s);
	if (start > str_len)
		len = 0;
	else if (len > (str_len - start))
		len = str_len - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (len-- && s[start + i] != '\0')
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/* #include <stdio.h>
int main()
{
    char *string = "hola";
    char *sub_string = ft_substr(string, 2, 1);

    printf("ft_substr= %s", sub_string);
    return(0);
}    */
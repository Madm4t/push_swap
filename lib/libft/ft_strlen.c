/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:36:40 by mgering           #+#    #+#             */
/*   Updated: 2023/11/01 12:05:18 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The strlen() function computes the length of the string s.

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/* #include <stdio.h>
int main()
{
    printf("string lenght = %lu\n", ft_strlen(""));
}  */
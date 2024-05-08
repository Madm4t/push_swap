/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:52:11 by mgering           #+#    #+#             */
/*   Updated: 2023/10/25 18:35:35 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Applies the function ’f’ on each character of
the string passed as argument, passing its index
as first argument. Each character is passed
by address to ’f’ to be modified if necessary.
s: The string on which to iterate.
f: The function to apply to each character. */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/* void	test(unsigned int index, char *string)
{
	index = 0;
	*string = ft_toupper(*string);
}

#include <stdio.h>
int main()
{
	char str[] = "Hello";
	ft_striteri(str, test);
	printf("str now: %s", str);
} */

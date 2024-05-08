/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:52:38 by mgering           #+#    #+#             */
/*   Updated: 2023/10/30 15:21:16 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns a string representing
the integer received as an argument. Negative numbers must be handled.
n: the integer to convert.*/

#include "libft.h"

static int	dec_places(int dec)
{
	int	dec_count;

	dec_count = 0;
	if (dec < 0)
		dec_count++;
	if (dec == 0)
		dec_count++;
	while (dec != 0)
	{
		dec = dec / 10;
		dec_count++;
	}
	return (dec_count);
}

static int	dec_num(long *num)
{
	int	i;

	i = 0;
	if (*num > 0)
	{
		i = *num % 10;
		*num = *num / 10;
		return (i);
	}
	return (0);
}

void	is_negative(int *is_positiv, long *num, int *lenght)
{
	if (*num < 0)
	{
		*num *= -1;
		*lenght -= 1;
		*is_positiv = 0;
	}
}

char	*ft_itoa(int n)
{
	long	j;
	int		len;
	int		positiv;
	char	*result;

	j = n;
	len = dec_places(n);
	positiv = 1;
	result = malloc(((len + 1) * sizeof(char)));
	if (!result)
		return (NULL);
	if (j < 0)
	{
		result[0] = '-';
		is_negative(&positiv, &j, &len);
	}
	while (len > 0)
	{
		result[len - positiv] = dec_num(&j) + '0';
		len--;
	}
	result[dec_places(n)] = '\0';
	return (result);
}

/* #include <stdio.h>
#include <string.h>

int main() {
    int n = -2147483648;
    
	int dec_count = dec_places(n);
    char *result = ft_itoa(n);
    
    printf("decimal places: %d\n", dec_count);
	printf("itoa:%s\n", result);
    return 0;
} */
// -2147483648
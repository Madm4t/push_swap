/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:15:01 by mgering           #+#    #+#             */
/*   Updated: 2023/10/26 16:35:18 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The atoi() function converts the initial portion of
the string pointed to by str to int representation. */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	result = result * sign;
	return (result);
}
//(str + i) ist dasselbe wie str[i] syntaxischer zucker
/* 
#include <stdio.h>
#include <string.h>

int main() {
    const char *string = "45345kk";
    
    int result = atoi(string);
    int ft_result = ft_atoi(string);
    
    printf("Needle: %d\n", result);
    printf("Needle: %d\n", ft_result);
    return 0;
} */
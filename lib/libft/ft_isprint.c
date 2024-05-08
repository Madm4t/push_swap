/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:19:24 by mgering           #+#    #+#             */
/*   Updated: 2023/10/25 17:08:11 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The isprint() function tests for any printing character,
including space (` ').  The value of the argument must be
representable as an unsigned char or the value of EOF. */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (1);
	else
		return (0);
}

/*
#include<stdio.h>
int main()
{
    printf("/nisprint:%d",ft_isprint(' '));
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:10:27 by mgering           #+#    #+#             */
/*   Updated: 2023/11/08 17:51:20 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The memcpy() function copies n bytes from memory area src to memory area dst.
If dst and src overlap, behavior is undefined.  Applications in which dst and
src might overlap should use memmove(3) instead. */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp_src;
	unsigned char	*temp_dst;

	i = 0;
	temp_src = (unsigned char *) src;
	temp_dst = (unsigned char *) dst;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		temp_dst[i] = temp_src[i];
		i++;
	}
	return (dst);
}

/* #include <stdio.h>
#include <string.h>

int main () 
{
   char src[50];
   char dst[50];

   strcpy(src,NULL);
   puts(src);

   ft_memcpy(dst, src, 9);
   puts(dst);
   return(0);
} */
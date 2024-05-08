/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:16:46 by mgering           #+#    #+#             */
/*   Updated: 2023/11/08 17:58:38 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The memmove() function copies len bytes from string src to string dst.
The two strings may overlap; the copy is always done in a
non-destructive manner. */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*temp_src;
	unsigned char	*temp_dst;

	i = 0;
	temp_src = (unsigned char *) src;
	temp_dst = (unsigned char *) dst;
	if (!dst && !src)
		return (NULL);
	while (i < len && src < dst)
	{
		i++;
		temp_dst[len - i] = temp_src[len - i];
	}
	while (i < len && src > dst)
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

   strcpy(src,"This is string.h library function");
   puts(src);

   ft_memmove(dst, src, 9);
   puts(dst);
   
   return(0);
} */
// a[5]
// 5[a]
// *(a+5)
// printf("%p, %p, %c, %c", src, src+1, ((char *)src)[0], ((char *)(src+2))[0]);
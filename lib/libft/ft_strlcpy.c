/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:11:01 by mgering           #+#    #+#             */
/*   Updated: 2023/10/25 17:22:44 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* strlcpy() copies up to dstsize - 1 characters from the string
src to dst, NUL-terminating the result if dstsize is not 0. */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	length;

	i = 0;
	length = ft_strlen(src);
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (length);
}

/* #include <stdio.h>
#include <string.h>

int main () 
{
   char src[50];
   char dst[50];
    size_t n_test = 10;

   strcpy(src,"This is string.h library funßction");
   puts(src);

   ft_strlcpy(dst, src, n_test);
   puts(dst);
   printf("\nft_strlcpy return= %lu",ft_strlcpy(dst, src, n_test));
   printf("\nft_strlcpy return= %lu\n",strlcpy(dst, src, n_test));
   return(0);
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:28:03 by mgering           #+#    #+#             */
/*   Updated: 2023/11/08 16:48:10 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* strlcat() appends string src to the end of dst.
It will append at most dstsize - strlen(dst) - 1 characters.
It will then NUL-terminate, unless dstsize is 0 or
the original dst string was longer than dstsize */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize == 0)
		return (len_src);
	if (dstsize <= len_dst)
		return (len_src + dstsize);
	while (src[i] != '\0' && (len_dst + i) < dstsize - 1)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}

/* #include <stdio.h>
#include <string.h>

int main() 
{
    char dest[30] = "";
    const char* src = "123";
    char dst[30] = "";
   
    size_t result = strlcat(dest, src, 0);
    size_t ft_result = ft_strlcat(dst,src, 0);
    
    printf("Concatenated string: %s\n", dest);
    printf("strlcat return= %lu\n",result);
    
    printf("Concatenated string: %s\n", dst);
    printf("ft_strlcat return= %lu\n",ft_result);

    return 0;
}  */

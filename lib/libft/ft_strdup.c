/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:49:20 by mgering           #+#    #+#             */
/*   Updated: 2023/10/26 17:37:17 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strdup() function allocates sufficient memory for
a copy of the string s1, does the copy, and returns
a pointer to it.  The pointer may subsequently be
used as an argument to the function free(3).
If insufficient memory is available, 
NULL is returned and errno is set to ENOMEM. */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;

	ptr = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!ptr)
	{
		return (NULL);
	}
	ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
	return (ptr);
}

/* #include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    const char *originalString = "Hello du";
    
    // Duplicate the original string
    char *duplicateString = strdup(originalString);
    char *ft_duplicateString = ft_strdup(originalString);

    if (duplicateString == NULL) {
        perror("strdup");
        return 1; // Handle allocation failure
    }

    // Print the original and duplicate strings
    printf("Original String: %s\n", originalString);
    printf("Duplicate String: %s\n", duplicateString);
    printf("ft_Duplicate String: %s\n", ft_duplicateString);


    // Free the memory allocated by strdup
    free(duplicateString);
    free(ft_duplicateString);

    return 0;
} */
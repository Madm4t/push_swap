/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:02:15 by mgering           #+#    #+#             */
/*   Updated: 2023/10/25 17:37:18 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The calloc() function contiguously allocates enough space
for count objects that are size bytes of memory each and
returns a pointer to the allocated memory.
The allocated memory is filled with bytes of value zero. */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = count * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_memset(ptr, 0, total_size);
	return (ptr);
}

/* 
#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t array_size = 6; // The number of elements in the array

    // Allocate memory for an array of integers and initialize with zeros
    int *myArray = (int *)calloc(array_size, sizeof(int));
    int *ft_myArray = (int *)calloc(array_size, sizeof(int));

    if (myArray == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit with an error code
    }
    // Display the contents of the allocated array
    printf("Allocated array elements:\n");
    for (size_t i = 0; i < array_size; i++) {
        printf("myArray[%zu] = %d\n", i, myArray[i]);
    }
    printf("Allocated array elements:\n");
    for (size_t i = 0; i < array_size; i++) {
        printf("ft_myArray[%zu] = %d\n", i, ft_myArray[i]);
    }
    
    free(myArray);

    return 0;
} */
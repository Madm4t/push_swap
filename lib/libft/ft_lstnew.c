/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:53:16 by mgering           #+#    #+#             */
/*   Updated: 2023/11/07 18:17:34 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns a new node.
The member variable ’content’ is initialized with
the value of the parameter ’content’. 
The variable ’next’ is initialized to NULL.
content: The content to create the node with.
External func: malloc.
return: The new node. */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/* #include <stdio.h>

int main()
{
	t_list	*list1;
	t_list	*list2;
	int *number = malloc(sizeof(int));

	*number = 42;
	list1 = ft_lstnew("Hello");
	list2 = ft_lstnew((int*)number);
	printf("content list1:%s\n", (char*)list1->content);
	printf("content list1:%d\n", *(int*)list2->content);
	free(number);
	free(list1);
	free(list2);
} */

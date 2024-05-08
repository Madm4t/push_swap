/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:23:28 by mgering           #+#    #+#             */
/*   Updated: 2023/11/08 13:14:16 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Deletes and frees the given node and every successor of that node,
using the function ’del’ and free(3).
Finally, the pointer to the list must be set to NULL.
lst: The address of a pointer to a node.
del: The address of the function used to delete the content of the node.
External functs: free.
Return: none */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp_node;
	t_list	*node;

	if (!lst || !*lst || !del)
		return ;
	temp_node = *lst;
	while (temp_node)
	{
		node = temp_node;
		del(node->content);
		temp_node = temp_node->next;
		free(node);
	}
	*lst = NULL;
}

/* #include <stdio.h>
#include <string.h>

void delete(void *content)
{
	free(content);
}

int main()
{
	t_list *list;

	list = ft_lstnew(strdup("whatsup"));
	ft_lstadd_back(&list, ft_lstnew(strdup("hi")));
	ft_lstadd_back(&list, ft_lstnew(strdup("how")));
	ft_lstadd_back(&list, ft_lstnew(strdup("are")));
	ft_lstadd_back(&list, ft_lstnew(strdup("you")));

	ft_lstclear(&list, delete);
	while (list)
	{
		printf("%s\n", list->content);
		list = list->next;
	}
}  */

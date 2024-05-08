/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:07:06 by mgering           #+#    #+#             */
/*   Updated: 2023/11/08 13:06:19 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Takes as a parameter a node and frees the memory of the node’s content
using the function ’del’ given as a parameter and free the node.
The memory of ’next’ must not be freed.
lst: The node to free.
del: The address of the function used to delete the content.
External functs: free.
Return: none */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
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
	t_list *temp_list;

	list = ft_lstnew(strdup("whatsup"));
	ft_lstadd_back(&list, ft_lstnew(strdup("hi")));
	ft_lstadd_back(&list, ft_lstnew(strdup("how")));
	ft_lstadd_back(&list, ft_lstnew(strdup("are")));
	ft_lstadd_back(&list, ft_lstnew(strdup("you")));

	temp_list = list->next;
	ft_lstdelone(list, delete);
	list = temp_list;
	while (list)
	{
		printf("%s\n", list->content);
		list = list->next;
	}
}  */
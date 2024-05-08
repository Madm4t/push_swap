/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:52:05 by mgering           #+#    #+#             */
/*   Updated: 2023/11/08 12:23:42 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Adds the node ’new’ at the end of the list.
lst: The address of a pointer to the first link of a list.
new: The address of a pointer to the node to be added to the list.
return: None*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current_list;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current_list = *lst;
	while (current_list->next != NULL)
		current_list = current_list->next;
	current_list->next = new;
}
/* #include <stdio.h>

int main()
{
	t_list	*list;

	list = ft_lstnew("jo");
	ft_lstadd_back(&list, ft_lstnew("Hello"));
	ft_lstadd_back(&list, ft_lstnew("World"));
	while (list)
	{
		printf("%s\n", list->content);
		list = list->next;
	}
	free(list);
}  */
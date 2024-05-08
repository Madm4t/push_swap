/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:10:41 by mgering           #+#    #+#             */
/*   Updated: 2023/11/08 12:24:30 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Adds the node ’new’ at the beginning of the list.
lst: The address of a pointer to the first link of a list.
new: The address of a pointer to the node to be added to the list.
Return: none */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/* #include <stdio.h>

int main()
{
	t_list	*list;

	list = ft_lstnew("jo");
	ft_lstadd_front(&list, ft_lstnew("Hello"));
	ft_lstadd_front(&list, ft_lstnew("World"));
	while (list)
	{
		printf("%s\n", list->content);
		list = list->next;
	}
	free(list);
} */

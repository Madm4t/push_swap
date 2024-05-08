/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:41:34 by mgering           #+#    #+#             */
/*   Updated: 2024/04/28 14:10:40 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Returns the last node of the list.
lst: The beginning of the list.
Return: Last node of the list. */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

/* #include <stdio.h>

int main()
{
	t_list	*list;

	list = ft_lstnew("whatsup");
	ft_lstadd_back(&list, ft_lstnew("hi"));
	ft_lstadd_back(&list, ft_lstnew("how"));
	ft_lstadd_back(&list, ft_lstnew("are"));
	ft_lstadd_back(&list, ft_lstnew("you"));

	printf("%s\n", ft_lstlast(list)->content);
	free(list);
} */
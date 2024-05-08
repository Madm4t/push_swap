/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:27:06 by mgering           #+#    #+#             */
/*   Updated: 2023/11/08 12:30:50 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Counts the number of nodes in a list.
lst: The beginning of the list.
return: The length of the list */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

/* #include <stdio.h>

int main()
{
	t_list *list;

	list = ft_lstnew("whatsup");
	ft_lstadd_back(&list, ft_lstnew("hi"));
	ft_lstadd_back(&list, ft_lstnew("how"));
	ft_lstadd_back(&list, ft_lstnew("are"));
	ft_lstadd_back(&list, ft_lstnew("you"));

	printf("%d\n", ft_lstsize(list));
	free(list);
} */

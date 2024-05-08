/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:35:47 by mgering           #+#    #+#             */
/*   Updated: 2023/11/08 13:32:23 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Iterates the list ’lst’ and applies the function ’f’ 
on the content of each node.
lst: The address of a pointer to a node.
f: The address of the function used to iterate on the list.
Return: none. */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list	*temp_lst;

	temp_lst = lst;
	if (!lst || !f)
		return ;
	while (temp_lst)
	{
		f(temp_lst->content);
		temp_lst = temp_lst->next;
	}
}

/* #include <stdio.h>
#include <string.h>

void func(void *content)
{
	printf("%zu\n", strlen(content));
}


int main()
{
	t_list *list;

	list = ft_lstnew(strdup("whatsup"));
	ft_lstadd_back(&list, ft_lstnew(strdup("hi")));
	ft_lstadd_back(&list, ft_lstnew(strdup("how")));
	ft_lstadd_back(&list, ft_lstnew(strdup("are")));
	ft_lstadd_back(&list, ft_lstnew(strdup("you")));

	ft_lstiter(list, (void*)func);

	t_list *temp_list;
	while (list)
	{
		temp_list = list->next;
		free(list->content);
		free(list);
		list = temp_list;
	}
} */
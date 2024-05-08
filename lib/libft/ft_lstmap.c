/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:47:15 by mgering           #+#    #+#             */
/*   Updated: 2023/11/08 14:08:32 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new_lst;
	t_list	*new_node;
	t_list	*temp_lst;
	void	*new_content;

	new_lst = NULL;
	temp_lst = lst;
	if (!lst || !f || !del)
		return (NULL);
	while (temp_lst)
	{
		new_content = f(temp_lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		temp_lst = temp_lst->next;
	}
	return (new_lst);
}

/* #include <stdio.h>
#include <string.h>

void func(void *content)
{
	strlen(content);
}

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

	t_list	*new_list;
	new_list = ft_lstmap(list, (void*)func, (void*)delete);

	while (new_list)
	{
		printf("%d\n", (int)new_list->content);
		new_list = new_list->next;
	}

	t_list	*temp_list;
	while (list)
	{
		temp_list = list->next;
		free(list->content);
		free(list);
		list = temp_list;
	}
	while (new_list)
	{
		temp_list = new_list->next;
		free(new_list->content);
		free(new_list);
		new_list = temp_list;
	}
}  */
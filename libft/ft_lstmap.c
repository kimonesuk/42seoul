/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:44:11 by okim              #+#    #+#             */
/*   Updated: 2020/11/29 20:04:01 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*nextlst;

	if (!lst || !f)
		return (0);
	if (!(nextlst = ft_lstnew(f(lst->content))))
		return (0);
	newlst = nextlst;
	lst = lst->next;
	while (lst)
	{
		if (!(nextlst = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&newlst, del);
			return (0);
		}
		lst = lst->next;
		ft_lstadd_back(&newlst, nextlst);
	}
	return (newlst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:44:11 by okim              #+#    #+#             */
/*   Updated: 2020/11/25 20:16:20 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*firstlst;
	t_list	*nextlst;
	t_list	*tmp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	if (!(firstlst = ft_lstnew(f(lst->content))))
	{
		ft_lstclear(&firstlst, del);
		return (NULL);
	}
	lst = lst->next;
	tmp = firstlst;
	while (lst != NULL)
	{
		if (!(nextlst = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&nextlst, del);
			return (NULL);
		}
		lst = lst->next;
		tmp->next = nextlst;
		tmp = nextlst;
	}
	return (firstlst);
}

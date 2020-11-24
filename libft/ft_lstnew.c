/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:36:44 by okim              #+#    #+#             */
/*   Updated: 2020/11/24 21:25:26 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *newlst;

	if (!(newlst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	newlst -> content = content;
	newlst -> next = NULL;
	return (newlst);
}

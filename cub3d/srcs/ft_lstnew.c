/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:36:44 by okim              #+#    #+#             */
/*   Updated: 2021/04/24 17:52:11 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_list	*ft_lstnew(char *content)
{
	t_list *newlst;

	if (!(newlst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	newlst->content = ft_strdup(content);
	newlst->next = NULL;
	return (newlst);
}

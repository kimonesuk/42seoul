/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 09:18:56 by okim              #+#    #+#             */
/*   Updated: 2021/04/25 22:55:22 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// F5 : 96  <- : 123  -> : 124  A : 0  W : 13  S : 1  D : 2
int	press_key(int key, void *param)
{
	if (key == 53 && param)
	{
		write(1, "The Window is stopped.\n", 23);
		exit(0);
	}
	if (key == 0 && param)
		write(1, "The A is input.\n", 16);
	if (key == 13 && param)
		write(1, "The W is input.\n", 16);
	if (key == 1 && param)
		write(1, "The S is input.\n", 16);
	if (key == 2 && param)
		write(1, "The D is input.\n", 16);
	if (key == 123 && param)
		write(1, "The left is input.\n", 19);
	if (key == 124 && param)
		write(1, "The right is input.\n", 20);
	return (0);
}
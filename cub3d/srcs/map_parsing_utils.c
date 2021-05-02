/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 09:10:00 by okim              #+#    #+#             */
/*   Updated: 2021/05/02 08:55:11 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (&str[i]);
}

int		error_msg(int error_n)
{
	write(1, "Error\n", 6);
	if (error_n == -1)
		write(1, "Invalid file path\n", 18);
	else if (error_n == -2)
		write(1, "Invalid file contents\n", 22);
	else if (error_n == -3)
		write(1, "Invalid map contents\n", 21);
	else if (error_n == -4)
		write(1, "Invalid map shape\n", 18);
	else if (error_n == -5)
		write(1, "Invalid input.\n", 15);
	else if (error_n == -6)
		write(1, "Invalid map file.\n", 18);
	else if (error_n == -7)
		write(1, "Can't Connect mlx\n", 18);
	else if (error_n == -8)
		write(1, "Can't open a new window\n", 24);
	else
		return (0);
	return (-1);
}

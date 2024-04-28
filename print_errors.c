/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/28 19:15:20 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	function_errors(int index)
{
	if (index == 1)
		ft_putstr("Invalid arguments : Please give one map (.ber)\n", 2);
	else if (index == 2)
		ft_putstr("Open fail : Can't open the giving file\n", 2);
	else if (index == 3)
		ft_putstr("Malloc fail: unexpected fail during memory allocation\n", 2);
	else if (index == 4)
		ft_putstr("Read fail : Can't read from giving file\n", 2);
}

void	maps_errors(int index)
{
	if (index == 1)
		ft_putstr("Invalid map extention : Please enter valid map (.ber)\n", 2);
	else if (index == 2)
		ft_putstr("Invalid map content : Extra or missing map characteres\n",
			2);
	else if (index == 3)
		ft_putstr("Invalid  map format : Map must be closed and rectangle\n",
			2);
	else if (index == 4)
		ft_putstr("Invalid map path : Player can't exit or collect all\n", 2);
	else if (index == 5)
		ft_putstr("Invalid map extention : Because it is a hidden file\n", 2);
}


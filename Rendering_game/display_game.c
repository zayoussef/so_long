/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/20 19:15:35 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_game display_gmae(t_game *so_long)
{
    int x;
    int y;

    x = 0;
    while (so_long->map[x])
    {
        y = 0;
        while (so_long->map[x][y] && so_long->map[x][y] != '\n')
        {
            draw
        }
    }
}
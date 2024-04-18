/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/18 19:07:22 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen( char *s)
{
	size_t	i;

    if (!s)
        return 0;
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void ft_putnbr(int nb)
{
    if (nb >= 10)
        putnbr(nb / 10);
    char f = nb % 10 + 48;
    write (1, &f, 1);
}

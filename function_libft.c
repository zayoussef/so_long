/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_libft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:15:34 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/06 04:03:50 by yozainan         ###   ########.fr       */
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



int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && (str1[i] == str2[i]))
		i++;
	return (str1[i] - str2[i]);
}

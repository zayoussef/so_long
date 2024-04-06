/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/06 06:31:47 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_line(char *str)
{
    int i = 0;
    if (str[i] == '\n')
        return 0;
    while (str[i])
    {
        if (str[i] == '\n' && (str[i + 1] == '\n') || str[i + 1] == '\0')
            return 0;
        i++;
    }
    return 1;
}


int main(int ac, char **av)
{
    char *line;
    char *tmp;
    int fd;

    fd = open(av[1], O_RDONLY);
    line = get_next_line(fd);
    printf ("%s", line);
    while (line)
    {
        tmp = ft_strjoin_ft(tmp, line);
        free(line);
        line = get_next_line(fd);
        printf ("%s", line);
    }
    close(fd);
    printf(":%s\n", tmp);
    
}
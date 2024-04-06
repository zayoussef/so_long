/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_Map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/06 09:07:10 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_file(char *path)
{
    int fd_1;

    fd_1 = open(path, O_RDONLY);
    if (fd_1 < 0)
        function_errors(2);
    close(fd_1);
}

void check_extention(char *path)
{
   int i;

    check_file(path);
    i = ft_strlen(path[i]);
    
    while (i >  0)
    {
        if (path[i] == '.')
            break;
        i--;
    }
   if (path[i] == '.' && (path[i - 1] == '/' || i == 0))
   {
        maps_errors(5);
        exit(EXIT_FAILURE);
   }
   if (path[i] && path[i] == '.')
   {
        if (!ft_strcmp(path + i, ".ber"))
        {
            maps_errors(1);
            exit(EXIT_FAILURE);
        }
   }
}
char **get_map(char *line)
{
    char **map;
    int i;

    i = 0;   

    while (line[i])
    {
        if (line[i] == '\n' && ((line[i + 1] == '\n') || line[i + 1] == '\0'))
        {
            maps_errors(3);
            return (NULL);
        }
        map = ft_split(line, '\n');
        if (!map)
        {
            free(line);
            return (NULL);
        }
        return (map);
    }    
}

char **read_map(char *path)
{
    char    **map;
    char    *line;
    char    *tmp;
    int     fd;

    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        function_errors(2);
        return (NULL);
    }
    line = get_next_line(fd);
    while (line)
    {
        tmp = ft_strjoin_ft(tmp, line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    map = get_map(line);
    if (!map)
    return (NULL);
    free(line);
    return (map);
}


char **valid_map(char *path)
{
    char **map;

    check_extention(path);
    map = read_map(path);
    if (!map)
        exit(1);
    if (!check_content(map) || !check_forma(map) || !check_valid_path(map))
    {
        free_map(map);
        exit(1);
    }
    return (map);
}

t_map *reading_map(char *path)
{
    t_map *map;

    map = malloc(sizeof (t_map));
    if (!map)
    {
        maps_errors(3);
        return (NULL);
    }
    map->map = valid_map(path);
}

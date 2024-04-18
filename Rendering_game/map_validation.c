/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/18 19:14:26 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_extension(char *path)
{
    char    *dot;
    int     fd;

    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        function_errors(2);
        exit(EXIT_FAILURE);
    }
    close(fd);
    dot = ft_strchr(path, '.');
    if (!dot || dot == path)
    {
        maps_errors(5);
        return (0);
    }
    if (ft_strcmp(dot, ".ber"))
    {
        function_errors(1);
        return 0;
    }
    return 1;
}

char	**get_map(char *str)
{
   char **map;
   
   if (str[0] == '\n' || str[ft_strlen(str) - 1] == '\n')
   {
        maps_errors(2);
        exit(EXIT_FAILURE);
   }
   map = ft_split(str, '\n');
   if (!map)
   {
        free(str);
        exit(EXIT_FAILURE);
   }
   return (map);
}

char *reading(int fd)
{
  char  *map;
  char  *buffer;
  int   i;

  buffer = malloc(sizeof(char) * 11);
  if (!buffer)
    return (NULL);
  map = NULL;
  i = 1;
  while (i)
  {
    i = read(fd, buffer, 10);
    if (i < 0)
    {
      free(buffer);
      return (NULL);
    }
    buffer[i] = '\0';
    map = ft_strjoin(map, buffer);
  }
  free(buffer);
  return (map);
}

char **reading_map(char *path)
{
    char    **map;
    char    *line;
    int     fd;
    
    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        function_errors(2);
        exit(EXIT_FAILURE);
    }
    line = reading(fd);
    if (!line)
    {
        function_errors(4);
        exit(EXIT_FAILURE);
    }
    map = get_map(line);
    if (!map)
    {
        free(line);
        exit(EXIT_FAILURE);
    }
    free(line);
    return (map);
}

char **map_validation(char *path)
{
    char **map;   

    if (!check_extension(path))
        exit(EXIT_FAILURE);
    map = reading_map(path);
    if (!validate_content(map) || !validation_format(map) || !validation_path(map))
    {
        free_map(map);
        exit(EXIT_FAILURE);
    }
    return (map);
}

/*
** get_next_line.c for get next line in /home/kerebel/Documents/EPITECH/CPE_2014_get_next_line
** 
** Made by kerebe_p
** Login   <kerebe_p@epitech.eu>
** 
** Started on  Mon Nov 17 00:45:22 2014 kerebe_p
** Last update Mon Nov 17 00:45:22 2014 kerebe_p
*/

#include <stdlib.h>
#include "get_next_line.h"

char    *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

char	*clean_get(char *str)
{
  int	i;

  i = 0;
  while (i <= READ_SIZE)
    {
      str[i] = '\0';
      i = i + 1;
    }
  return (str);
}

char	*get_next_line(const int fd)
{
  static char	tmp[READ_SIZE + 1];
  char		buffer[READ_SIZE + 1];
  char		*str;
  int		i;
  int		k;
  int		count;

  i = 0;
  k = 0;
  str = malloc((READ_SIZE + 2));
  if (tmp[0] == '\0')
    {
      count = read(fd, buffer, READ_SIZE);
      if (count <= 0)
	return (NULL);
      buffer[count] = '\0';
    }
  else
    my_strcpy(buffer, tmp);
  while (buffer[i] != '\n' && buffer[i] != '\0')
    str[i] = buffer[i++];
  if (buffer[i] == '\n')
    my_strcpy(tmp, &buffer[i + 1]);
  else if (buffer[i] == '\0')
    my_strcpy(tmp, &buffer[i]);
  if (str[0] == '\0')
    return (NULL);
  return (str);
}

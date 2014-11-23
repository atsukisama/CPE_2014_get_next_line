/*
** get_next_line.c for test in /home/kerebel/Documents/EPITECH/CPE_2014_get_next_line
** 
** Made by kerebe_p
** Login   <kerebe_p@epitech.eu>
** 
** Started on  Wed Nov 19 22:32:01 2014 kerebe_p
** Last update Sun Nov 23 18:47:03 2014 Paul Kerebel
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

char	*buffer_plus(char *old, char *current)
{
  int	i;
  int	k;
  int	z;
  char	*str;

  i = 0;
  k = 0;
  z = 0;
  if (old == NULL || current == NULL)
    return (NULL);
  while (old[i] != '\0')
    i = i + 1;
  while (current[z] != '\0')
    z = z + 1;
  str = malloc(sizeof(char) * (i + z + 1));
  if (str == NULL)
    return (NULL);
  i = 0;
    while (old[i] != '\0')
      str[k++] = old[i++];
  i = 0;
  while (current[i] != '\0')
    str[k++] = current[i++];
  str[k] = '\0';
  return (str);
}

char	*get_all_char(const int fd)
{
  char	tmp[1];
  char	buffer[READ_SIZE + 1];
  char	*save;
  int	count;
  int	r;

  r = fd;
  count = read(r, buffer, READ_SIZE);
  if (count < 0)
    return (NULL);
  buffer[count] = '\0';
  save = buffer_plus(tmp, buffer);
  if (save == NULL)
    return (NULL);
  while (count > 0)
      {
  	count = read(r, buffer, READ_SIZE);
  	if (count < 0)
  	  return (NULL);
  	buffer[count] = '\0';
  	save = buffer_plus(save, buffer);
  	if (save == NULL)
  	  return (NULL);
      }
  return (save);
}

char	*my_backslash(char *save, char *ret, int i)
{
  if (save[i + 1] == '\0' && save[i] != '\n')
    {
      ret[i] = save[i];
      ret[i + 1] = '\0';
    }
  else
    ret[i] = '\0';
  return (ret);
}

char		*get_next_line(const int fd)
{
  static char	*save;
  char		*ret;
  int		i;

  i = 0;
  if (save == NULL)
    save = get_all_char(fd);
  if (save == NULL)
    return (NULL);
  while (save[i] != '\n' && save[i] != '\0')
    i = i + 1;
  ret = malloc(sizeof(char) * (i + 1));
  if (ret == NULL)
    return (NULL);
  i = 0;
  while (save[i] != '\n' && save[i + 1] != '\0')
    {
      ret[i] = save[i];
      i = i + 1;
    }
  ret = my_backslash(save, ret, i);
  if (ret[0] == '\0' && save[0] != '\n')
    return (NULL);
  save = my_strcpy(save, &save[i + 1]);
  return (ret);
}

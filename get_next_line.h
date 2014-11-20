/*
** get_next_line.h for H next line in /home/kerebel/Documents/EPITECH/CPE_2014_get_next_line
** 
** Made by kerebe_p
** Login   <kerebe_p@epitech.eu>
** 
** Started on  Mon Nov 17 00:49:54 2014 kerebe_p
** Last update Mon Nov 17 00:49:54 2014 kerebe_p
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
# define READ_SIZE 1

char *my_strcpy(char *dest, char *src);
char *buffer_plus(char *old, char *current);
char *get_all_char(const int r);
char *my_backslash(char *save, char *ret, int i);
char *get_next_line(const int fd);

#endif

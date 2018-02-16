/*
** sort_symbol_array.c for sort symbol array in /home/tavart_f/Epitech/rendu/PSU3/PSU_2016_nmobjdump/src
** 
** Made by Fanny Tavart
** Login   <fanny.tavart@epitech.net>
** 
** Started on  Sun Feb 19 20:35:09 2017 Fanny Tavart
** Last update Sat Feb 25 16:20:53 2017 Fanny Tavart
*/

#include <stdlib.h>
#include "my.h"
#include "nm.h"

static char	*str_to_upcase(char *str)
{
  unsigned int	idx;
  char		*tmp;

  if ((tmp = malloc(my_strlen(str) + 1)) == NULL)
    return (NULL);
  idx = 0;
  while (str[idx] != '\0')
    {
      if (str[idx] >= 'a' && str[idx] <= 'z')
      	tmp[idx] = str[idx] - 32;
      else
	tmp[idx] = str[idx];
      idx += 1;
    }
  tmp[idx] = '\0';
  return (tmp);
}

static char	*epur_underscore(char *str)
{
  unsigned int	idx;

  idx = 0;
  while (str[idx] != '\0' && str[idx] == '_')
    idx += 1;
  return (str_to_upcase(str + idx));
}

static char	is_big(char *s1, char *s2, char *actual, char *actual_next)
{
  unsigned int	idx;

  idx = 0;
  while (s1[idx] != '\0' && s2[idx] != '\0')
    {
      if (s1[idx] == '_')
	s1[idx] = ' ';
      if (s2[idx] == '_')
	s2[idx] = ' ';
      if (s1[idx] > s2[idx])
	return (1);
      else if (s1[idx] < s2[idx])
	return (0);
      idx += 1;
    }
  return (0);
}

static unsigned int	free_names(char* name, char *name_next)
{
  free(name);
  free(name_next);
  return (0);
}

t_symbol	*sort_symbol_array(t_symbol *arr)
{
  unsigned int	idx;
  char		*name;
  char		*name_next;
  t_symbol	tmp;

  idx = 0;
  while (idx < get_symbol_array_size(arr))
    {
      if (idx + 1 < get_symbol_array_size(arr))
      	{
	  if ((name_next = epur_underscore(arr[idx + 1].name)) == NULL
	      || (name = epur_underscore(arr[idx].name)) == NULL)
	    return (NULL);
	  if (is_big(name, name_next, arr[idx].name, arr[idx + 1].name) == 1 ||
	      (my_strcmp(name_next, name) == 0 && arr[idx + 1].name[0] == '_'))
	    {
	      tmp = arr[idx + 1];
	      arr[idx + 1] = arr[idx];
	      arr[idx] = tmp;
	      idx = free_names(name, name_next);
	    }
	}
      idx += 1;
    }
  return (arr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:57:06 by albertini         #+#    #+#             */
/*   Updated: 2023/11/08 19:23:20 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char  *get_next_line(int fd)
{
  char *stash;
  (void)fd;
  stash = (char *)malloc(sizeof(char) * 1000 + 1);
  
  return (stash); 
}
int main(void)
{
  int fd;
  char *line;

  fd = open("test.tx", O_RDONLY);
  
  while(1)
  {
    line = get_next_line(fd);
    if(line == NULL)
    {
      printf("La lingne est: %s\n", line);
      break;  
    }
    printf("La ligne est: %s\n", line);
    free(line);
  }
  return (0);
}
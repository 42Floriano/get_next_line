/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:57:06 by albertini         #+#    #+#             */
/*   Updated: 2023/11/09 11:04:36 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char  *get_next_line(int fd)
{
  char              *line;
  static t_list     *stash = NULL;
  int               rd;
  
  stash = malloc(sizeof(t_list) + 1);
  line = (char )malloc(sizeof(char) * 1000 + 1);
  rd = 1;
  if(fd < 0 || BUFFER_SIZE < 0 || read(fd, &line, 0) < 0)
      return (NULL);
  //Read FD and add to linked list
  read_and_stash(fd, &stash, &rd);
  //Add FD to Line
  add_to_stash();
  //Return Stash
  
  return (stash); 
}

//Use read to add to the stash
void  read_and_stash(int fd, t_list **stash, int *rd)
{
  char  *buff;

  buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
  if (buff == NULL)
      return ;
  while (!found_nline(*stash) && *rd != 0)
  {
    *rd = (int)read(fd, &buff, BUFFER_SIZE);
    if ((*stash == NULL && *rd == 0) || *rd == -1)
    {
      free(buff);
      return ;
    }
    buff[*rd] = '\0';    
  }
   
}

//Add what is in the buffwer to the Stash
void  add_to_stash()
{

}

//Check the first \n in the stash and exctract the first line
void  extract_line()
{

}

//Clean the first line that we used in the Stash
void  clean_stash()
{

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
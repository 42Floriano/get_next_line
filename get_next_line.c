/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:57:06 by albertini         #+#    #+#             */
/*   Updated: 2023/11/08 17:29:17 by albertini        ###   ########.fr       */
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
  return (0);
}
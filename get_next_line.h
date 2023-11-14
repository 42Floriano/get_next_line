/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:57:09 by albertini         #+#    #+#             */
/*   Updated: 2023/11/13 15:27:58 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}		t_list;

char		*get_next_line(int fd);
void		read_and_stash(int fd, t_list **stash);
void		add_to_stash(t_list **stash, char *buff, int rd);
void		extract_line(t_list *stash, char **line);
void		clean_stash(t_list **stash);
int			found_nline(t_list *stash);
t_list		*ft_lst_get_last(t_list *stash);
int			get_size_line(t_list *stash);
int			ft_strlen(char *str);
void		free_stash(t_list *stash);

#endif
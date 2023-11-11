/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:57:06 by albertini         #+#    #+#             */
/*   Updated: 2023/11/11 17:28:02 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char  *get_next_line(int fd)
{
	char              *line;
	static t_list     *stash = NULL;
	
	if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	//Read FD and add to linked list
	read_and_stash(fd, &stash);
	//Extract line from stash;
	extract_line(stash, &line);
	//Clean Stash
	clean_stash(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line); 
}

//Use read to add to the stash
void  read_and_stash(int fd, t_list **stash)
{
	char  	*buff;
	int		rd;
	
	rd = 1;
	while (!found_nline(*stash) && rd != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buff == NULL)
			return ;
		rd = (int)read(fd, buff, BUFFER_SIZE);
		if ((*stash == NULL && rd == 0) || rd == -1)
		{
			free(buff);
			return ;
		}
		buff[rd] = '\0';
		add_to_stash(stash, buff, rd);
		free(buff);
	}
}

//Add what is in the buffwer to the Stash
void  add_to_stash(t_list **stash, char *buff, int rd)
{
	int	i;
	t_list	*last;
	t_list	*new_node;
	
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (rd + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buff[i] && i < rd)
	{
		new_node->content[i] = buff[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new_node;
	} 
	else 
	{
		last = ft_lst_get_last(*stash);
		last->next = new_node;
	}
	return ;
}

//Check the first \n in the stash and exctract the first line
void  extract_line(t_list *stash, char **line)
{
	t_list	*current;
	int		i;
	int		y;
	
	current = stash;
	*line = malloc(sizeof(char) * (get_size_line(stash) + 1));
	if (*line == NULL)
		return ;
	//Iterate dans chaque noeud pour récuperer la line
	y = 0;
	while(current != NULL)
	{
		i = 0;
		while (current->content[i])
		{
			if (current->content[i] == '\n')
			{
				(*line)[y++] = current->content[i];
				break ;
			}
			(*line)[y] = current->content[i];
			i++;
			y++;
		}
		//chopper le prochaine noeud
		current = current->next;
	}
	(*line)[y] = '\0';
}

//Clean the first line that we used in the Stash
void  clean_stash(t_list **stash)
{
	t_list	*last;
	t_list	*cleaned;
	int		i;
	int		y;
	
	if (stash == NULL)
		return ;
	cleaned = malloc(sizeof(t_list));
	if (cleaned == NULL)
		return ;
	i = 0;
	last = ft_lst_get_last(*stash);
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n')
		i++;
	cleaned->content = malloc(sizeof(char) * ((ft_strlen(last->content) - i) + 1));
	if (cleaned->content == NULL)
		return ;
	y = 0;
	while(last->content[i])
		cleaned->content[y++] = last->content[i++];
	cleaned->content[y] = '\0';
	free_stash(*stash);
	*stash = cleaned; 	 
}

int main(void)
{
	int fd;
	char *line;

	fd = open("./test.txt", O_RDONLY);
	while(1)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		if (line == NULL)
			break ;
		free(line);
	}
	return (0);
}

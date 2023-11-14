/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:57:16 by albertini         #+#    #+#             */
/*   Updated: 2023/11/13 16:02:47 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// check for a newline in the linked list
int	found_nline(t_list *stash)
{
	int		i;
	t_list	*current;

	if (stash == NULL)
		return (0);
	current = ft_lst_get_last(stash);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

t_list	*ft_lst_get_last(t_list *stash)
{
	t_list	*current;

	current = stash;
	while (current && current->next)
		current = current->next;
	return (current);
}

int	get_size_line(t_list *stash)
{
	t_list	*current;
	int		i;
	int		len;

	current = stash;
	len = 0;
	while (current != NULL)
	{
		i = 0;
		while (current->content[i])
		{
			if (current->content[i] == '\n')
			{
				len++;
				break ;
			}
			i++;
			len++;
		}
		current = current->next;
	}
	return (len);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_stash(t_list *stash)
{
	t_list	*current;
	t_list	*next;

	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

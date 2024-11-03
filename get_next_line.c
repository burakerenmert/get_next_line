/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buramert <buramert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:46:43 by buramert          #+#    #+#             */
/*   Updated: 2024/11/03 23:14:08 by buramert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_clean(char *buffer)
{
	char	*left;
	size_t		i;
	size_t	buffer_size;
	
	buffer_size = ft_strlen(buffer);
	i = 0;
	while(buffer[i] != '\n')
		i++;
	left = malloc(sizeof(char) * (buffer_size - i) + 1);
	left[buffer_size] = '\0';
	while(buffer_size >= i)
	{
		left[buffer_size] = buffer[buffer_size];
		buffer_size--;
	}
	free(buffer);
	return(left);
}
static char	*ft_line(char *temp)
{
	int end;
	char *new_string;
	
	end = 0;
	while(temp[end] != '\n')
	{
		end++;
	}
	end++;
	new_string = malloc(sizeof(char) * (end + 1));
	if (!new_string)
		return (NULL);
	new_string[end + 1] = '\0';
	while (end >= 0)
	{
		new_string[end] = temp[end];
		end--;
	}
	return (new_string);
}
static char	*ft_read(int fd, char *buffer)
{
	char	*temp;
	read(fd, buffer, BUFFER_SIZE);
	temp = buffer;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	if (ft_strchr(temp, '\n'))
	{
		temp = ft_line(temp);
	}
	free(buffer);
	return (temp);
}
char	*get_next_line(int fd)
{
	char *line;
	static char *buffer;
	line = ft_read(fd, buffer);
	if(!line)
		return(NULL);
	buffer = ft_clean(buffer);
	return (line);
}

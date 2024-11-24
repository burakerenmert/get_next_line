/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buramert <buramert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:56:15 by buramert          #+#    #+#             */
/*   Updated: 2024/11/25 00:28:25 by buramert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char *ft_parser(char *str, int line)
{
	int i;
	char *str_line;
	
	i = 0;
	str_line = malloc(sizeof(char) * (line + 2));
	while(i < line)
	{
		str_line[i] = str[i];
		i++;
	}
	if(str[i] == '\n')
	{
		str_line[i] == '\n';
		i++;
	}
	str_line[i] = '\0';
	return(str_line);
}
int ft_check_line(char *str)
{
	int i;
	
	i = 0;
	while(str[i] && str[i] != '\n')
	{
		i++;
	}
	if(str[i] == '\n')
	{
		return(i);
	}
	else
		return(0);
}
char *ft_read(int fd, char *str)
{
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read(fd, str, BUFFER_SIZE);
	return(str);
}
char *get_next_line(int fd)
{
	int			line;
	static char *str;
	char *line_to_return;

	if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
	str = ft_read(fd, str);
	line = ft_check_line(str);
	if(line != 0)
		line_to_return = ft_parser(str, line);
	return(str);
}
int main()
{
	int fd;
	fd = open("text.txt", O_RDONLY | O_CREAT);
	printf("%s", get_next_line(fd));
}
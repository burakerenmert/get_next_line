/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burakerenmert <burakerenmert@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:56:15 by buramert          #+#    #+#             */
/*   Updated: 2024/11/27 06:14:10 by burakerenme      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_parser(char *str, int line)
{
	char	*line_to_return;
	int		i;

	i = 0;
	line_to_return = malloc(sizeof(char) * (line + 2));
	while(i < line)
	{
		line_to_return[i] = str[i];
		i++;
	}
	line_to_return[i] = '\n';
	line_to_return[i + 1] = '\0';
	return(line_to_return);
}
static int ft_check_line(char *str)
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
		return(ft_strlen(str));
}
static char *ft_remainder(char *str)
{
	char	*remainder;
	int		length;
	
	remainder = ft_strchr(str, '\n');
	length = ft_strlen(remainder);
	remainder[length++] = '\0';
	str = ft_strdup(remainder);
	return(str);
}
char *get_next_line(int fd)
{
	static char *str;
	char		*line_to_return;
	int			line;
	int			bytes_read;
	if (!str)
		str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes_read = read(fd, (str + ft_strlen(str)), BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		if (ft_strlen(str) > 0)
		{
			line_to_return = ft_parser(str, ft_strlen(str));
			free(str);
			str = NULL;
			return (line_to_return);
		}
		return (NULL);
	}
	str[(ft_strlen(str) + bytes_read)] = '\0';
	line = ft_check_line(str);
	if (line > 0)
	{
		line_to_return = ft_parser(str, line);
		str = ft_remainder(str);
	}
	else
		line_to_return = NULL;
	return (line_to_return);
}
int main()
{
	int fd;
	fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
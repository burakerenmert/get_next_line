/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buramert <buramert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:56:15 by buramert          #+#    #+#             */
/*   Updated: 2024/12/02 19:34:12 by buramert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_get_line(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while(str[j] != '\n')
	{
		j++;
	}
	line = malloc(sizeof(char) * (j + 2));
	while(str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i] = '\n';
	line[++i] = '\0';
	return (line);
}
static char *ft_reader(char *str, int fd, int *bytes_read)
{
    char    *buffer;

    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    while (1)
    {
        *bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (*bytes_read <= 0)
            break;
        buffer[*bytes_read] = '\0';
        str = ft_strjoin(str, buffer);
        if (!str)
        {
            free(buffer);
            return (NULL);
        }
        if (ft_check_line(str))
            break;
    }
    free(buffer);
    if (*bytes_read == -1)
        return (NULL);
    return (str);
}


static char *ft_get_remainder(char *str)
{
	int		i;
	int		j;
	char	*remainder;

	i = 0;
	j = 0;
	while(str[i] != '\n')
		i++;
	remainder = malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
	if (!remainder)
		return (NULL);
	i++;
	while(str[i])
	{
		remainder[j] = str[i];
		i++;
		j++;
	}
	if (str[i] == '\0')
		remainder[i + 1] = '\0';
	return (remainder);
}
char *get_next_line(int fd)
{
	static char	*str;
	char		*temp;
	char		*line_to_return;
	int			bytes_read;
	
	if(!str)
		str = ft_strdup("");
	str = ft_reader(str, fd, &bytes_read);
	if (ft_check_line(str))
	{
		line_to_return = ft_get_line(str);
		temp = ft_get_remainder(str);
		free(str);
		str = ft_strdup(temp);
	}
	else if (!(ft_check_line(str)) && bytes_read == 0 && ft_strlen(str) == 0)
		return (NULL);
	else
	{
		line_to_return = ft_strdup(str);
		free(str);
		str = NULL;
	}
	return (line_to_return);
}
int main()
{
	int fd;
	fd = open("text.txt", O_RDONLY);
	
	printf("first read ; %s", get_next_line(fd));
	printf("second read ; %s", get_next_line(fd));
	printf("third read ; %s", get_next_line(fd));
	printf("fourth read ; %s", get_next_line(fd));
	printf("fifth read ; %s", get_next_line(fd));
	printf("sixth read ; %s", get_next_line(fd));
	printf("seventh read ; %s", get_next_line(fd));
	printf("eighth read ; %s", get_next_line(fd));
	printf("nineth read ; %s", get_next_line(fd));
	printf("tenth read ; %s", get_next_line(fd));
	
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	
	close(fd);
}
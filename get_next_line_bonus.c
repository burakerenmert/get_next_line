/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buramert <buramert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:22:12 by buramert          #+#    #+#             */
/*   Updated: 2024/12/07 14:27:27 by buramert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_get_line(char	*str)
{
	char	*line_extracted;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	line_extracted = malloc(sizeof(char) * (i + 1));
	if (!line_extracted)
		return (NULL);
	while (j < i)
	{
		line_extracted[j] = str[j];
		j++;
	}
	line_extracted[i] = '\0';
	return (line_extracted);
}

static char	*ft_reader(int fd, char	*str)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_check_line(str) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || (bytes_read == 0 && ft_strlen(str) == 0))
		{
			if (str)
				free(str);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

static char	*ft_get_remainder(char	*str)
{
	char	*remainder;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	remainder = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!remainder)
		return (NULL);
	while (str[i])
		remainder[j++] = str[i++];
	remainder[j] = '\0';
	free (str);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*str[10240];
	char		*line_to_return;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 10240)
		return (NULL);
	str[fd] = ft_reader(fd, str[fd]);
	if (!str[fd] || !*str[fd])
		return (NULL);
	line_to_return = ft_get_line(str[fd]);
	str[fd] = ft_get_remainder(str[fd]);
	return (line_to_return);
}

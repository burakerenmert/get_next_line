/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burakerenmert <burakerenmert@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:56:15 by buramert          #+#    #+#             */
/*   Updated: 2024/11/29 04:38:28 by burakerenme      ###   ########.fr       */
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
static int ft_check_line(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if(str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
static char *ft_get_remainder(char *str)
{
	int		i;
	char	*remainder;

	i = 0;
	while(str[i] != '\n')
		i++;
	i++;
	remainder = malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
	if (!remainder)
		return (NULL);
	while(str[i])
	{
		remainder[i] = str[i];
		i++;
	}
	if (str[i] == '\0')
		remainder[++i] = '\0';
	return (remainder);
}
char *get_next_line(int fd)
{
	static char *str;
	char		*temp;
	char		*line_to_return;
	int			bytes_read;
	
	if (!str)
		str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	bytes_read = read(fd, str, BUFFER_SIZE);
	str[bytes_read + 1] = '\0';
	if (ft_check_line(str))									//LINE FOUND
	{
		line_to_return = ft_get_line(str);
		if (ft_strlen(line_to_return) < ft_strlen(str))		//REMAINDER FOUND	
		{
			temp = ft_get_remainder(str);
			free(str);
			str = temp;
		}
	}
	else if (!(ft_check_line(str)) && bytes_read <= 0)	//EOF
	{
			line_to_return = str;
			free(str);				
	}
	else if ((!(ft_check_line(str))) && bytes_read > 0)		//NO LINE FOUND
		line_to_return = NULL;
	return (line_to_return);
}
int main()
{
	int fd;
	fd = open("text.txt", O_RDONLY);
	get_next_line(fd);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
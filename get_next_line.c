/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buramert <buramert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:56:15 by buramert          #+#    #+#             */
/*   Updated: 2024/11/30 00:06:30 by buramert         ###   ########.fr       */
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
	// printf("\nstring ; %s", str);
	while(str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i] = '\n';
	line[++i] = '\0';
	// printf("\nextracted line ; %s", line);
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
	// printf("\ninitial string ; %s", str);
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
	// printf("\nremainder ; %s", remainder);
	return (remainder);
}
char *get_next_line(int fd)
{
	static char *str;
	char		*buffer;
	char		*temp;
	char		*line_to_return;
	int			bytes_read;
	
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!str)
		str = ft_strdup("");
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_read] = '\0';
	str = ft_strjoin(str, buffer);
	free(buffer);
	// printf("initial string ; %s", str);
	if (ft_check_line(str))									//LINE FOUND
	{
		line_to_return = ft_get_line(str);
		if (ft_strlen(line_to_return) < ft_strlen(str))		//REMAINDER FOUND	
		{
			temp = ft_get_remainder(str);
			// printf("remainder ; %s\n", temp);
			free(str);
			// printf("%s", str);
			str = ft_strdup(temp);
			// printf("string ; %s\n", str);
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
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	get_next_line(fd);
	get_next_line(fd);
	// get_next_line(fd);

}
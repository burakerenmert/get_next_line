/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buramert <buramert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:56:15 by buramert          #+#    #+#             */
/*   Updated: 2024/11/24 22:28:39 by buramert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// void ft_free(str)
// {
	
// }
// char *ft_check_line(str)
// {
// 	int i;
	
// 	i = 0;
// }
char *ft_read(int fd, char *str)
{
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read(fd, str, BUFFER_SIZE);
	return(str);
}
char *get_next_line(int fd)
{
	static char *str;
	str = ft_read(fd, str);
	printf("%s", str);
	return(str);
}
int main()
{
	int fd;
	fd = open("text.txt", O_RDONLY | O_CREAT);
	printf("%s", get_next_line(fd));
}
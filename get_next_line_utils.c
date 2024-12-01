/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burakerenmert <burakerenmert@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:56:15 by buramert          #+#    #+#             */
/*   Updated: 2024/12/01 02:54:40 by burakerenme      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
char	*ft_strdup(const char *s1)
{
	size_t			s_len;
	size_t			i;
	unsigned char	*str1;

	s_len = (ft_strlen(s1));
	i = 0;
	str1 = malloc(sizeof(char) * (s_len + 1));
	if (str1 == NULL)
		return (NULL);
	while (i <= s_len)
	{
		str1[i] = s1[i];
		i++;
	}
	return ((char *)str1);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			s1_len;
	size_t			s2_len;
	size_t			i;
	size_t			j;
	char			*str;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str == NULL)
		return (NULL);
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < s2_len)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
int ft_check_line(char *str)
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

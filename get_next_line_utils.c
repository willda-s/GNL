/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:57:43 by willda-s          #+#    #+#             */
/*   Updated: 2024/12/13 19:15:37 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (free(s1), NULL);
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2 && *s2 && *s2 != '\n')
	{
		dest[i] = *s2;
		i++;
		s2++;
	}
	if (s2 && *s2 == '\n')
		dest[i++] = '\n';
	dest[i] = '\0';
	return (dest);
}

int	ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	tmp;

	i = 0;
	tmp = (unsigned char)c;
	while (str && str[i])
	{
		if (tmp == (unsigned char)str[i])
			return (i + 1);
		i++;
	}
	if (tmp == '\0')
		return (i + 1);
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:48:26 by willda-s          #+#    #+#             */
/*   Updated: 2024/12/06 23:30:16 by willda-s         ###   ########.fr       */
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
		return (NULL);
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

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*str;
	ssize_t		bytes;

	str = NULL;
	while (1)
	{
		if (!buf[0])
		{
			bytes = read(fd, buf, BUFFER_SIZE);
			if (bytes <= 0)
			{
				if (str != NULL && bytes != -1)
					return (str);
				else
					return (free(str), NULL);
			}
			buf[bytes] = '\0';
		}
		str = ft_strjoin(str, buf);
		if (ft_strchr(buf, '\n') != -1)
			return (ft_strcpy(buf, buf + ft_strchr(buf, '\n')), str);
		buf[0] = '\0';
	}
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int fd;
// 	char *str;
// 	int i;

// 	i = 0;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (printf("erreur"));
// 	str = get_next_line(fd);
// 	while (str)
// 	{
// 		printf("%s", str);
// 		free(str);
// 		str = get_next_line(fd);
// 	}
// }
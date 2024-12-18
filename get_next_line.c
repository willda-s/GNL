/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:48:26 by willda-s          #+#    #+#             */
/*   Updated: 2024/12/13 19:15:41 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*check_read(ssize_t bytes, char *str)
{
	if (str != NULL && bytes != -1)
		return (str);
	return (free(str), NULL);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*str;
	ssize_t		bytes;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (!buf[0])
		{
			bytes = read(fd, buf, BUFFER_SIZE);
			if (bytes <= 0)
				return (check_read(bytes, str));
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
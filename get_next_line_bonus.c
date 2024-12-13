/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:48:26 by willda-s          #+#    #+#             */
/*   Updated: 2024/12/13 18:14:43 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*check_bytes(ssize_t bytes, char *str)
{
	if (str != NULL && bytes != -1)
		return (str);
	return (free(str), NULL);
}

char	*get_next_line(int fd)
{
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*str;
	ssize_t		bytes;

	str = NULL;
	if (fd < 0 || fd >= FOPEN_MAX)
		return (NULL);
	while (1)
	{
		if (!buf[fd][0])
		{
			bytes = read(fd, buf[fd], BUFFER_SIZE);
			if (bytes <= 0)
				return (check_bytes(bytes, str));
			buf[fd][bytes] = '\0';
		}
		str = ft_strjoin(str, buf[fd]);
		if (ft_strchr(buf[fd], '\n') != -1)
			return (ft_strcpy(buf[fd], buf[fd] + ft_strchr(buf[fd], '\n')),
				str);
		buf[fd][0] = '\0';
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
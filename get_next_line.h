/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:51:50 by willda-s          #+#    #+#             */
/*   Updated: 2024/12/06 20:19:59 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

char	*ft_strcpy(char *dst, char *src);

size_t	ft_strlen(const char *str);

char	*ft_strjoin(char *s1, char const *s2);

int		ft_strchr(const char *str, int c);

char	*ft_strdup(const char *str1);

#endif
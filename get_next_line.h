/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:51:50 by willda-s          #+#    #+#             */
/*   Updated: 2024/12/13 19:11:21 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);

char	*ft_strcpy(char *dst, char *src);

size_t	ft_strlen(const char *str);

char	*ft_strjoin(char *s1, char const *s2);

int		ft_strchr(const char *str, int c);

char	*ft_strdup(char *dst, char *src);

#endif
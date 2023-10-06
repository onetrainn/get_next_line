/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrossi <lgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:34:38 by mcenci            #+#    #+#             */
/*   Updated: 2023/05/17 19:21:25 by lgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# ifndef BUFFER_SIZE
#  define  BUFFER_SIZE
# endif

char	*get_next_line(int fd);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);
#endif

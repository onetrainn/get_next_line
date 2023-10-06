/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrossi <lgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:35:21 by mcenci            #+#    #+#             */
/*   Updated: 2023/05/17 19:23:34 by lgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	a;

	a = 0;
	while (src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

char	*gnl_breaker(char	*final, char	*buff)
{
	int		i;
	char	*new;
	int		j;
	char	*tmp;

	tmp = NULL;
	i = 0;
	j = 0;
	if (final != NULL)
		tmp = final;
	while (final != NULL && final[i])
		i++;
	while (buff[j] && buff[j - 1] != '\n')
		j++;
	new = ft_calloc (i + j + 1, sizeof(char));
	if (final != NULL)
		ft_strcpy(new, final);
	j = 0;
	while (buff[j] && buff[j] != '\n')
		new[i++] = buff[j++];
	if (buff[j] == '\n')
		new[i] = '\n';
	if (tmp != NULL)
		free (tmp);
	return (new);
}

void	get_reminded(char **remind)
{
	char	*tmp;
	int		i;

	i = 0;
	if (*remind)
	{
		while ((*remind)[i] && (*remind)[i] != '\n')
			i++;
		if ((*remind)[i] == '\n')
			i++;
		if ((*remind)[i])
		{
			tmp = *remind;
			*remind = ft_strdup(&tmp[i]);
			free (tmp);
		}
		else
		{
			free (*remind);
			*remind = NULL;
		}
	}
}

int	get_buffed(char **final, char **remind, int fd)
{
	char	*buff;
	char	*nl;

	buff = ft_calloc (BUFFER_SIZE + 1, 1);
	while ((read (fd, buff, BUFFER_SIZE)) > 0)
	{
		if (ft_strchr(buff, '\n'))
		{
			*final = gnl_breaker(*final, buff);
			nl = (ft_strchr(buff, '\n')) + 1;
			if (nl[0])
				*remind = ft_strdup(nl);
			if (buff)
				free(buff);
			return (1);
		}
		else
			*final = gnl_breaker(*final, buff);
		ft_memset(buff, 0, BUFFER_SIZE);
	}
	free (buff);
	if (read(fd, buff, BUFFER_SIZE) == 0)
		return (1);
	else
		return (-1);
}

char	*get_next_line(int fd)
{
	char		*final;
	static char	*remind = NULL;

	final = NULL;
	if (remind != NULL)
	{
		final = gnl_breaker(final, remind);
		get_reminded(&remind);
		if (ft_strchr(final, '\n'))
			return (final);
	}
	if (get_buffed(&final, &remind, fd) > 0 || final != NULL )
		return (final);
	else
		return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 23:16:20 by ksaelim           #+#    #+#             */
/*   Updated: 2022/08/26 23:24:54 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_keep(char *str, size_t cut_len)
{
	char	*new;
	size_t	i;

	if (!str[cut_len])
	{
		free(str);
		return (NULL);
	}
	if (str[cut_len] == '\n')
		cut_len++;
	new = malloc(ft_strlen_mode(&str[cut_len], '\0') + 1);
	if (!new)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (str[cut_len])
		new[i++] = str[cut_len++];
	new[i] = '\0';
	free(str);
	return (new);
}

char	*get_cut_line(char *str, size_t cut_len)
{
	char	*new;
	size_t	i;

	if (!str[0])
		return (NULL);
	if (str[cut_len] == '\n')
		cut_len++;
	new = malloc(sizeof(char) * (cut_len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] && i < cut_len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*read_line(int fd, char *keep)
{
	char	*buff;
	int		read_byte;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_byte = 1;
	while (read_byte > 0)
	{
		read_byte = read(fd, buff, BUFFER_SIZE);
		if (read_byte < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[read_byte] = '\0';
		keep = ft_strjoin(keep, buff);
		if (ft_strrchr(buff))
			break ;
	}
	free(buff);
	return (keep);
}

char	*get_next_line(int fd)
{
	char		*cut_line;
	static char	*keep[OPEN_MAX];
	size_t		cut_len;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!keep[fd])
	{
		keep[fd] = malloc(1);
		keep[fd][0] = '\0';
	}
	keep[fd] = read_line(fd, keep[fd]);
	if (!keep[fd])
	{
		free(keep);
		return (NULL);
	}
	cut_len = ft_strlen_mode(keep[fd], '\n');
	cut_line = get_cut_line(keep[fd], cut_len);
	keep[fd] = get_keep(keep[fd], cut_len);
	return (cut_line);
}

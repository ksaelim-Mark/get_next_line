/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 23:16:45 by ksaelim           #+#    #+#             */
/*   Updated: 2022/08/26 23:37:00 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_mode(char *str, char c)
{
	size_t	i;

	if (!str[0])
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*ft_strrchr(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = ft_strlen_mode(str, '\0');
	while (i >= 0)
	{
		if (str[i] == '\n')
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen_mode(s1, 0) \
		+ ft_strlen_mode(s2, 0) + 1));
	if (!join)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = 0;
	free(s1);
	return (join);
}

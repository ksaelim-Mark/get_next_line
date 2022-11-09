/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:06:43 by ksaelim           #+#    #+#             */
/*   Updated: 2022/08/26 23:36:00 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*get_keep(char *str, size_t cut_line);
char	*get_cut_line(char *str, size_t cut_line);
size_t	ft_strlen_mode(char *str, char c);
char	*ft_strrchr(char *str);
char	*read_line(int fd, char *keep);
char	*ft_strjoin(char *s1, char *s2);
#endif

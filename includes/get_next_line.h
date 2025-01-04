/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <username@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:01:14 by username          #+#    #+#             */
/*   Updated: 2024/05/14 14:50:00 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

char	*get_next_line(int fd, char **rest);
char	*ft_strchr_gnl(char *s, int c);
size_t	ft_strlen_gnl(const char *s);
char	*ft_substr_gnl(char const *line, unsigned int start, size_t len);
char	*ft_strdup_gnl(const char *src);
char	*ft_strjoin_gnl(const char *line, char const *buf);

#endif

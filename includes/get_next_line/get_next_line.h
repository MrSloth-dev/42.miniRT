/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:35:53 by joao-pol          #+#    #+#             */
/*   Updated: 2024/05/07 15:47:47 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

void	ft_bzero(char *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_cleanfile(char *str);
#endif

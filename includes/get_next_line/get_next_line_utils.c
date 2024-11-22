/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:02:30 by joao-pol          #+#    #+#             */
/*   Updated: 2024/05/07 14:40:29 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cleanfile(char *file)
{
	char	*result;
	int		i;
	int		j;
	int		length;

	if (!*file)
	{
		free(file);
		return (NULL);
	}
	length = ft_strlen(file);
	i = 0;
	while (file[i] != '\0' && file[i] != '\n')
		i++;
	result = ft_calloc(((length - i) + 1), sizeof(char));
	j = 0;
	while (file[i])
	{
		result[j++] = file[++i];
	}
	result[j] = '\0';
	free(file);
	return (result);
}

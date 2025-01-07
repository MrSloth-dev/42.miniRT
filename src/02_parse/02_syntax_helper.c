/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_syntax_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:39:53 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:39:53 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_count_members(char **split)
{
	int	count;

	count = 0;
	while (*split++)
		count++;
	return (count);
}

int	ft_count_split(char **split)
{
	int	count;

	count = 0;
	while (*split++)
		count++;
	return (count);
}

/**
 * @brief 
 *
 * @param split 
 * @return 1 if ok 0 if ko
 */
int	ft_check_null_split(char **split)
{
	if (ft_count_split(split) != 3)
		return (0);
	while (*split)
	{
		if (ft_strlen(*split) == 0)
			return (0);
		split++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:45:15 by joao-pol          #+#    #+#             */
/*   Updated: 2024/11/19 16:17:40 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*ft_free_split(char **str, size_t index);
static		int	count_words(char *str, char *charset);
static		int	ft_lenword(char *str, char *charset);
static	char	*ft_strdupword(char *str, char *charset);

char	**ft_split_charset(char *str, char *charset)
{
	auto int count = count_words(str, charset);
	auto char **split = {0};
	auto int i = 0;
	auto int j = 0;
	if (str == NULL || count <= 0)
		return (NULL);
	split = ft_calloc(count + 1, sizeof(char *));
	if (!split)
		return (NULL);
	while (str[i])
	{
		while (str[i] && ft_strchr(charset, str[i]))
			i++;
		while (str[i] && !ft_strchr(charset, str[i]))
		{
			split[j] = ft_strdupword(&str[i], charset);
			i += ft_lenword(&str[i], charset);
			if (!split[j])
				return (ft_free_split(split, j));
			j++;
		}
	}
	split[count] = 0;
	return (split);
}

static int	count_words(char *str, char *charset)
{
	auto int i = 0;
	auto int count = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		while (str[i] && ft_strchr(charset, str[i]))
			i++;
		if (str[i] && !ft_strchr(charset, str[i]))
		{
			count ++;
			while (str[i] && !ft_strchr(charset, str[i]))
				i++;
		}
	}
	return (count);
}

static	char	*ft_strdupword(char *str, char *charset)
{
	auto int len = 0;
	auto char *dup = (NULL);
	auto int i = 0;
	while (str[len] && !ft_strchr(charset, str[len]))
		len++;
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

static int	ft_lenword(char *str, char *charset)
{
	auto int i = 0;
	while (!ft_strchr(charset, str[i]))
		i++;
	return (i);
}

static void	*ft_free_split(char **str, size_t index)
{
	size_t	j;

	j = 0;
	while (j < index)
	{
		free(str[j]);
		str[j++] = NULL;
	}
	free(*str);
	return (NULL);
}
/* #include <stdio.h>
int	main()
{
	int 	i;
	i = 0;
	char *empty = NULL;
	// char **split = ft_split(empty, ' '); 
	char **split = ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');
	if (split == NULL)
	{
		printf("ERROR STRING NOT FOUND");
		return (0);
	}
	while (i < count_words("^^^1^^2a,^^^^3^^^^--h^^^^", '^'))
		{
		printf("%s\n", split[i]);
		i++;
		}
	i = 0;
	while (i < count_words("^^^1^^2a,^^^^3^^^^--h^^^^", '^'))
		{
		free(split[i]);
		i++;
		}
		free(split);
	return (0);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:35:51 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/17 21:57:31 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_perror(t_world *w, t_shapes *s, char *msg)
{
	dup2(STDERR_FILENO, STDOUT_FILENO);
	printf("\033[1m\033[31mError \033[0m\n");
	if (msg)
	{
		printf("%s", msg);
		if (w && w->line)
			printf(" at line: \033[31m%s\033[0m", w->line);
		else
			printf("\n");
	}
	else
		perror(NULL);
	get_next_line(3, 1);
	if (s)
		free(s);
	if (w && w->line)
		free(w->line);
	if (w)
		ft_free_all_allocated_memory(w);
	exit(1);
}

double	ft_atof(t_world *w, t_shapes *s, char *str)
{
	double	res;
	double	fra;
	int		sig;

	res = 0;
	fra = 1;
	sig = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '\0')
		ft_perror(w, s, "Double is not valid");
	if (*str == '-')
		sig = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		res = res * 10 + *str++ - '0';
	if (*str == '.')
		str++;
	while (ft_isdigit(*str))
	{
		res = res * 10 + *str++ - '0';
		fra *= 10;
	}
	return (res / fra * sig);
}

double	ft_get_double(t_world *w, t_shapes *s, char **line, char d)
{
	int		i;
	int		dot;
	char	str[32];

	i = -1;
	dot = 0;
	if (**line == ',')
		(*line)++;
	while (**line == ' ')
		(*line)++;
	if (**line == '-' || **line == '+')
		str[++i] = *(*line)++;
	while (**line != d && **line != '\n' && **line)
	{
		if (**line == '.')
			dot++;
		if ((!ft_isdigit(**line) && **line != '.') || dot > 1 || i > 30)
			ft_perror(w, s, "Double is not valid");
		else if (**line != ' ')
			str[++i] = **line;
		(*line)++;
	}
	str[++i] = '\0';
	return (ft_atof(w, s, str));
}

t_point	ft_get_tuple(t_world *world, t_shapes *s, char **line, double w)
{
	double	color;
	t_vec3	tuple;

	color = 1;
	if (w == 3)
		color = 255.0;
	tuple = (t_vec3){-42, -42, -42, -42};
	while (**line)
	{
		if (**line == ' ')
			(*line)++;
		else if (ft_isdigit(**line) || **line == '-' || **line == '+')
		{
			tuple.x = ft_get_double(world, s, line, ',') / color;
			tuple.y = ft_get_double(world, s, line, ',') / color;
			tuple.z = ft_get_double(world, s, line, ' ') / color;
			tuple.w = w;
			break ;
		}
		else
			ft_perror(world, s, "Tuple is not valid");
	}
	if (w == 3 && ft_in_range(tuple, 0, 1) == false)
		ft_perror(world, s, "Color is not in range");
	return (tuple);
}

bool	ft_in_range(t_vec3 v, double min, double max)
{
	if (v.x < min || v.x > max
		|| v.y < min || v.y > max
		|| v.z < min || v.z > max)
		return (false);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:01:08 by lagea             #+#    #+#             */
/*   Updated: 2024/09/12 12:36:46 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	get_color_char(char *color, int i)
{
	while (color[i] && ft_isdigit((int)color[i]))
		i++;
	return (i);
}

static int	skip_until_digit(char *color, int i)
{
	while (color[i] && !ft_isdigit((int)color[i]))
		i++;
	return (i);
}

void	assign_color(t_data *data, t_color *color)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(color->r);
	g = ft_atoi(color->g);
	b = ft_atoi(color->b);
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		error_color(data, color->r, color->g, color->b);
	color->color = (r << 16) | (g << 8) | b;
}

t_color	*isolate_color_param(t_data *data, char *color)
{
	int		i;
	int		start;
	t_color	*_color;

	_color = init_color_struct(data);
	i = 0;
	start = skip_until_digit(color, i);
	i = get_color_char(color, i);
	if (start == i)
		error_color(data, _color->r, _color->g, _color->b);
	_color->r = ft_substr(color, start, i);
	start = skip_until_digit(color, i);
	i = get_color_char(color, start);
	if (start == i)
		error_color(data, _color->r, _color->g, _color->b);
	_color->g = ft_substr(color, start, i - start);
	start = skip_until_digit(color, i);
	i = get_color_char(color, start);
	if (start == i)
		error_color(data, _color->r, _color->g, _color->b);
	_color->b = ft_substr(color, start, i - start);
	assign_color(data, _color);
	return (_color);
}

void	get_color(t_data *data)
{
	int		x;
	int		y;
	t_color	*color;

	if (check_is_rgb_color(data->file.color_floor))
	{
		color = isolate_color_param(data, data->file.color_floor);
		data->file.c_floor = color;
	}
	if (check_is_rgb_color(data->file.color_ceiling))
	{
		color = isolate_color_param(data, data->file.color_ceiling);
		data->file.c_ceiling = color;
	}
}

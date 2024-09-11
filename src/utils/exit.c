/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:39:55 by lagea             #+#    #+#             */
/*   Updated: 2024/09/11 14:01:06 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	clear_xpm(t_data *data)
{
	clear_xpm_menu(data);
	clear_xpm_menu_2(data);
	clear_xpm_letters(data);
	clear_xpm_texture(data);
	clear_xpm_enemy(data);
}

void	clear_data(t_data *data)
{
	clear_struct_file(data);
	clear_xpm(data);
}

void	ft_error(char *str, t_data *data)
{
	if (str)
		printf("Error :\n%s\n", str);
	clear_data(data);
	handle_input(0, data);
	exit(1);
}

void	exit_error(void)
{
	perror("Error");
	exit(1);
}

void	exit_malloc(void)
{
	write(2, "Error memory allocation\n", 24);
	exit(1);
}

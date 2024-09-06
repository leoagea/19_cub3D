/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:49:18 by lagea             #+#    #+#             */
/*   Updated: 2024/09/06 17:35:21 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	check_file_extension(char *file, t_data *data)
{
	char	*ext;

	ext = ft_strrchr(file, '.');
	if (ft_strncmp(ext, ".cub", INT_MAX) != 0)
		ft_error(ERR_EXT, data);
}

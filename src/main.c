/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:14:57 by lagea             #+#    #+#             */
/*   Updated: 2024/08/18 18:07:36 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int main(int ac, char **av)
{
    t_data *data;

    data = malloc(sizeof(t_data));
    if (!data)
        exit_malloc();
    parsing(ac, av, data);
    create_window(data);
    mlx_key_hook(data->mlx_window, &handle_key, data);
    mlx_loop(data->mlx_connection);
    return 0;
}
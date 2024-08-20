/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:51:59 by lagea             #+#    #+#             */
/*   Updated: 2024/08/20 12:46:02 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void assign_dir(t_player *player, char **map, int i, int j)
{
    if (map[i][j] == 'N')
    {
        player->dir_x = 0;
        player->dir_y = -1 * (float)K;
    }
    else if (map[i][j] == 'S')
    {
        player->dir_x = 0;
        player->dir_y = 1 * (float)K;
    }
    else if (map[i][j] == 'E')
    {
        player->dir_x = 1 * (float)K;
        player->dir_y = 0;
    }
    else if (map[i][j] == 'W')
    {
        player->dir_x = -1 * (float)K;
        player->dir_y = 0;
    }
}

static void assign_plane(t_player *player, char **map, int i, int j)
{
    if (map[i][j] == 'N')
    {
        player->plane_x = ((float)FOV / 100) * (float)K;
        player->plane_y = 0;
    }
    else if (map[i][j] == 'S')
    {
        player->plane_x = ((float)FOV / 100) * (float)K;
        player->plane_y = 0;
    }
    else if (map[i][j] == 'E')
    {
        player->plane_x = 0;
        player->plane_y = -1.0 * ((float)FOV / 100) * (float)K;
    }
    else if (map[i][j] == 'W')
    {
        player->plane_x = 0;
        player->plane_y = -1.0 * ((float)FOV / 100) * (float)K;
    }
}

static int    assing_coord(t_data *data, float i, float j, int count)
{
    data->player->pos_x = (float) j;
    data->player->pos_y = (float) i;
    count++;
    return count;
}
void get_player_pos(t_data *data)
{
    int i;
    int j;
    int count;
    char **map;
    
    i = 0;
    count = 0;
    map = data->file->map;
    while (map[i])
    {
        j = 0;
        while (map[i][j] && map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W')
            j++;
        if (map[i][j] && (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W'))
            count = assing_coord(data, (float) i, (float) j, count);
        i++;
    }
    if (count != 1)
        ft_error(ERR_PLAY, data);
    assign_dir(data->player, map, (int) data->player->pos_y, (int) data->player->pos_x);
    assign_plane(data->player, map, (int) data->player->pos_y, (int) data->player->pos_x);
    // printf("pos x : %f\n", data->player->pos_x);
    // printf("pos y : %f\n", data->player->pos_y);
    // printf("dir x : %f\n", data->player->dir_x);
    // printf("dir y : %f\n", data->player->dir_y);
}

#include "../../inc/cub3d.h"

void	raycasting(t_player *player)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		ray_direction(i, player);
		delta_distance(player);
		i++;
	}
}

void	ray_direction(int i, t_player *player)
{
	int w = WIDTH;
	player->camera_x = 2.0 * (i / (double)w) - 1.0;
	player->ray_dir_x =  player->dir_x + player->plane_x * player->camera_x;
	player->ray_dir_y =  player->dir_y + player->plane_y * player->camera_x;
}

void	delta_distance(t_player *player)
{
	player->map_x = (int) player->pos_x;
	player->map_y = (int) player->pos_y;
	player->delta_dist_x = fabs(1 / player->ray_dir_x);
	player->delta_dist_y = fabs(1 / player->ray_dir_y);
}
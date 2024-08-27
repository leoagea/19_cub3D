#include "../../inc/cub3d.h"

void	raycasting(t_player *player, t_data *data)
{
	int	i;
	char *fps_str;

	i = 0;
	player->column = 0;
	data->img->img_ptr = mlx_new_image(data->mlx_connection, WIDTH, HEIGHT);
	data->img->img_pixels_ptr = mlx_get_data_addr(data->img->img_ptr,
			&(data->img->bits_per_pixel), &(data->img->size_line),
			&(data->img->endian));
	while (i < WIDTH)
	{
		ray_direction(i, player);
		delta_distance(player);
		init_dda(player);
		dda_algorithm(player, data);
		wall_height(player);
		draw(data, player);
		wall_texture(data, player, i);
		draw_crosshair(data);
		i++;
	}
	mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
		(data)->img->img_ptr, 0, 0);
	render_weapon(data);
	mlx_string_put(data->mlx_connection, data->mlx_window, 35, 700, 16777215, "Speed :");
	mlx_string_put(data->mlx_connection, data->mlx_window, 90, 700, 16777215, ft_itoa(data->player->speed * 100));
}

void	ray_direction(int i, t_player *player) // Calculation of Ray vector
{
	int w = WIDTH;
	player->camera_x = 2.0 * (i / (double)w) - 1.0;
	player->ray_dir_x =  player->dir_x + player->plane_x * player->camera_x;
	player->ray_dir_y =  player->dir_y + player->plane_y * player->camera_x;
}

void	delta_distance(t_player *player) // Calculation of dx and dy that represent the distance between 2 x or y axes in the ray_dir_x / ray_dir_y direction
{
	player->map_x = (int) player->pos_x;
	player->map_y = (int) player->pos_y;
	if (player->ray_dir_x == 0) // Avoid division by 0
		player->delta_dist_x = 1e30;
	else
		player->delta_dist_x = fabs(1 / player->ray_dir_x);
	if (player->ray_dir_y == 0)
		player->delta_dist_y = 1e30;
	else
		player->delta_dist_y = fabs(1 / player->ray_dir_y);
}

void	init_dda(t_player *player)
{
	if (player->ray_dir_x < 0)
	{
		player->step_x = -1;
		player->side_dist_x = (player->pos_x - player->map_x) * player->delta_dist_x;
	}
	else
	{
		player->step_x = 1;
		player->side_dist_x = (player->map_x + 1.0 - player->pos_x) * player->delta_dist_x;
	}
	if (player->ray_dir_y < 0)
	{
		player->step_y = -1;
		player->side_dist_y = (player->pos_y - player->map_y) * player->delta_dist_y;
	}
	else
	{
		player->step_y = 1;
		player->side_dist_y = (player->map_y + 1.0 - player->pos_y) * player->delta_dist_y;
	}
}

void	dda_algorithm(t_player *player, t_data *data)
{
	while (1)
	{
		if (player->side_dist_x < player->side_dist_y)
		{
			player->side_dist_x += player->delta_dist_x;
			player->map_x += player->step_x;
			player->side = 0;
		}
		else
		{
			player->side_dist_y += player->delta_dist_y;
			player->map_y += player->step_y;
			player->side = 1;		
		}
		if (data->file->map[player->map_y][player->map_x] == '1')
			break ;
	}
	if (player->side == 0)
		player->perp_wall_dist = player->side_dist_x - player->delta_dist_x;
	else
		player->perp_wall_dist = player->side_dist_y - player->delta_dist_y;
}

void	wall_height(t_player *player)
{
	player->wall_height = (int)(HEIGHT / player->perp_wall_dist);
	player->draw_start = -1 * player->wall_height / 2 + HEIGHT / 2 + player->pitch;
	if (player->draw_start < 0)
		player->draw_start = 0;
	player->draw_end = player->wall_height / 2 + HEIGHT / 2 + player->pitch;
	if (player->draw_end >= HEIGHT)
		player->draw_end = HEIGHT - 1;
}
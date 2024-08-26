#include "../../inc/cub3d.h"

void	move_forward(t_data *data)
{
	double new_pos_x;
    double new_pos_y;

	new_pos_x = data->player->pos_x + data->player->dir_x * 0.1;
	new_pos_y = data->player->pos_y + data->player->dir_y * 0.1;
	if (data->file->map[(int)(new_pos_y)][(int)(new_pos_x)] == '0' ||
		data->file->map[(int)(new_pos_y)][(int)(new_pos_x)] == 'W' ||
		data->file->map[(int)(new_pos_y)][(int)(new_pos_x)] == 'S' ||
		data->file->map[(int)(new_pos_y)][(int)(new_pos_x)] == 'N' ||
		data->file->map[(int)(new_pos_y)][(int)(new_pos_x)] == 'E')
	{
		data->player->pos_x = new_pos_x;
        data->player->pos_y = new_pos_y;
		mlx_destroy_image(data->mlx_connection , data->img->img_ptr);
		raycasting(data->player, data);
	}
}

void	move_backward(t_data *data)
{
	double new_pos_x;
    double new_pos_y;

	new_pos_x = data->player->pos_x - data->player->dir_x * 0.1;
	new_pos_y = data->player->pos_y - data->player->dir_y * 0.1;

	if (data->file->map[(int)(new_pos_y)][(int)(new_pos_x)] == '0' ||
		data->file->map[(int)(new_pos_y)][(int)(new_pos_x)] == 'W' ||
		data->file->map[(int)(new_pos_y)][(int)(new_pos_x)] == 'S' ||
		data->file->map[(int)(new_pos_y)][(int)(new_pos_x)] == 'N' ||
		data->file->map[(int)(new_pos_y)][(int)(new_pos_x)] == 'E')
	{
		data->player->pos_x = new_pos_x;
        data->player->pos_y = new_pos_y;
		mlx_destroy_image(data->mlx_connection , data->img->img_ptr);
		raycasting(data->player, data);
	}
	mlx_destroy_image(data->mlx_connection , data->img->img_ptr);
	raycasting(data->player, data);
}
// void	move_left(t_data *data)
// {
// 	double new_pos_x;
//     double new_pos_y;

// 	new_pos_x =
// }

int	player_movement(t_data *data)
{
	if (data->player->key_left)
		rotate_left(data);
	if (data->player->key_right)
		rotate_right(data);
	if (data->player->key_forward)
		move_forward(data);
	if (data->player->key_backward)
		move_backward(data);
	if (data->player->minimap)
		create_minimap(data);
	else
		raycasting(data->player, data);
	return (0);
}
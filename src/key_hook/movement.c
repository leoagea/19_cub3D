#include "../../inc/cub3d.h"

void	move_forward(t_data *data)
{
	data->player->pos_x += data->player->dir_x * 0.1;
	data->player->pos_y += data->player->dir_y * 0.1;
	mlx_destroy_image(data->mlx_connection , data->img->img_ptr);
	raycasting(data->player, data);
}

void	move_backward(t_data *data)
{
	data->player->pos_x += -data->player->dir_x * 0.1;
	data->player->pos_y += -data->player->dir_y * 0.1;
	mlx_destroy_image(data->mlx_connection , data->img->img_ptr);
	raycasting(data->player, data);
}

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
	return (0);
}
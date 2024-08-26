#include "../../inc/cub3d.h"

void	move_forward(t_data *data)
{
	double new_pos_x;
    double new_pos_y;

	new_pos_x = data->player->pos_x + data->player->dir_x * data->player->speed;
	new_pos_y = data->player->pos_y + data->player->dir_y * data->player->speed;
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

	new_pos_x = data->player->pos_x - data->player->dir_x * data->player->speed;
	new_pos_y = data->player->pos_y - data->player->dir_y * data->player->speed;

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

void	move_right(t_data *data)
{
	double new_pos_x;
    double new_pos_y;
	double new_vect_x;
	double new_vect_y;

	new_vect_x = data->player->dir_x * cos(PI / 2) - data->player->dir_y * sin(PI / 2);
	new_vect_y = data->player->dir_x * sin(PI / 2) + data->player->dir_y * cos(PI / 2);
	new_pos_x = data->player->pos_x + new_vect_x * data->player->speed;
	new_pos_y = data->player->pos_y + new_vect_y * data->player->speed;
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

void	move_left(t_data *data)
{
	double new_pos_x;
    double new_pos_y;
	double new_vect_x;
	double new_vect_y;

	new_vect_x = data->player->dir_x * cos(PI / 2) - data->player->dir_y * sin(PI / 2);
	new_vect_y = data->player->dir_x * sin(PI / 2) + data->player->dir_y * cos(PI / 2);
	new_pos_x = data->player->pos_x - new_vect_x * data->player->speed;
	new_pos_y = data->player->pos_y - new_vect_y * data->player->speed;
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
	if (data->player->key_move_left)
		move_left(data);
	if (data->player->key_move_right)
		move_right(data);
	mouse_rotation(data);
	return (0);
}
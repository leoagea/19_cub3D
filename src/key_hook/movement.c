#include "../../inc/cub3d.h"

void	move_forward(t_data *data)
{
	double new_pos_x;
    double new_pos_y;

	new_pos_x = data->player.pos_x + data->player.dir_x * data->player.speed;
	new_pos_y = data->player.pos_y + data->player.dir_y * data->player.speed;
	if (data->file.map[(int)(new_pos_y)][(int)(new_pos_x)] == '0' ||
		data->file.map[(int)(new_pos_y)][(int)(new_pos_x)] == 'W' ||
		data->file.map[(int)(new_pos_y)][(int)(new_pos_x)] == 'S' ||
		data->file.map[(int)(new_pos_y)][(int)(new_pos_x)] == 'N' ||
		data->file.map[(int)(new_pos_y)][(int)(new_pos_x)] == 'E')
	{
		data->player.pos_x = new_pos_x;
        data->player.pos_y = new_pos_y;
	}
}

void	move_backward(t_data *data)
{
	double new_pos_x;
    double new_pos_y;

	new_pos_x = data->player.pos_x - data->player.dir_x * data->player.speed;
	new_pos_y = data->player.pos_y - data->player.dir_y * data->player.speed;

	if (data->file.map[(int)(new_pos_y)][(int)(new_pos_x)] == '0' ||
		data->file.map[(int)(new_pos_y)][(int)(new_pos_x)] == 'W' ||
		data->file.map[(int)(new_pos_y)][(int)(new_pos_x)] == 'S' ||
		data->file.map[(int)(new_pos_y)][(int)(new_pos_x)] == 'N' ||
		data->file.map[(int)(new_pos_y)][(int)(new_pos_x)] == 'E')
	{
		data->player.pos_x = new_pos_x;
        data->player.pos_y = new_pos_y;
	}
}

void	move_right(t_data *data)
{
	double new_pos_x;
    double new_pos_y;
	double new_vect_x;
	double new_vect_y;

	new_vect_x = data->player.dir_x * cos(PI / 2) - data->player.dir_y * sin(PI / 2);
	new_vect_y = data->player.dir_x * sin(PI / 2) + data->player.dir_y * cos(PI / 2);
	new_pos_x = data->player.pos_x + new_vect_x * data->player.speed;
	new_pos_y = data->player.pos_y + new_vect_y * data->player.speed;
	if (data->file.map[(int)(new_pos_y)][(int)(new_pos_x)] == '0' ||
		data->file.map[(int)(new_pos_y)][(int)(new_pos_x)] == 'W' ||
		data->file.map[(int)(new_pos_y)][(int)(new_pos_x)] == 'S' ||
		data->file.map[(int)(new_pos_y)][(int)(new_pos_x)] == 'N' ||
		data->file.map[(int)(new_pos_y)][(int)(new_pos_x)] == 'E')
	{
		data->player.pos_x = new_pos_x;
        data->player.pos_y = new_pos_y;
		// mlx_destroy_image(data->mlx_connection , data->img->img_ptr);
		// raycasting(&data->player, data);
	}
	// mlx_destroy_image(data->mlx_connection , data->img->img_ptr);
	// raycasting(&data->player, data);
}

void	move_left(t_data *data)
{
	double new_pos_x;
    double new_pos_y;
	double new_vect_x;
	double new_vect_y;

	new_vect_x = data->player.dir_x * cos(PI / 2) - data->player.dir_y * sin(PI / 2);
	new_vect_y = data->player.dir_x * sin(PI / 2) + data->player.dir_y * cos(PI / 2);
	new_pos_x = data->player.pos_x - new_vect_x * data->player.speed;
	new_pos_y = data->player.pos_y - new_vect_y * data->player.speed;
	if (data->file.map[(int)(new_pos_y)][(int)(new_pos_x)] == '0' ||
		data->file.map[(int)(new_pos_y)][(int)(new_pos_x)] == 'W' ||
		data->file.map[(int)(new_pos_y)][(int)(new_pos_x)] == 'S' ||
		data->file.map[(int)(new_pos_y)][(int)(new_pos_x)] == 'N' ||
		data->file.map[(int)(new_pos_y)][(int)(new_pos_x)] == 'E')
	{
		data->player.pos_x = new_pos_x;
        data->player.pos_y = new_pos_y;
		// mlx_destroy_image(data->mlx_connection , data->img->img_ptr);
		// raycasting(&data->player, data);
	}
	// mlx_destroy_image(data->mlx_connection , data->img->img_ptr);
	// raycasting(&data->player, data);
}

int player_movement(t_data *data)
{
	int i = 0;
    if (data->menu == 0)
        create_menu(data);
    else if (data->menu == 1)
    {
		mlx_mouse_hide(data->mlx_window);
        if (data->player.key_left)
            rotate_left(data);
        if (data->player.key_right)
            rotate_right(data);
        if (data->player.key_forward)
            move_forward(data);
        if (data->player.key_backward)
            move_backward(data);
		if (data->player.key_move_left)
            move_left(data);
        if (data->player.key_move_right)
            move_right(data);
        if (data->player.minimap)
            create_minimap(data);
		if (verif_all_dead(data, data->enemy)) // A ameliorer !
		{
			ft_putstr_fd("YOU WON !\n", 2);
			exit (1);
		}
		mouse_rotation(data);
		mlx_destroy_image(data->mlx_connection , data->img->img_ptr);
		raycasting(&data->player, data);
		if (data->player.is_firing == 0)
		{
			reset_shot(data, data->enemy);
			mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->player.weapon[data->player.anim.current_frame].img_ptr,((WIDTH - data->player.weapon[SIMPLE].width) / 2) + 100, 400);
		}
		else
			render_weapon(data);
    }
    return (0);
}
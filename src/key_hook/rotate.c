#include "../../inc/cub3d.h"

void	rotate_right(t_data *data)
{
	double old_dir_x;
    double old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	data->player.dir_x =  ((data->player.dir_x * cos(ROTATE_SPEED * ONEDEG)) - (data->player.dir_y  * sin(ROTATE_SPEED * ONEDEG)));
	data->player.dir_y = ((old_dir_x * sin(ROTATE_SPEED * ONEDEG)) + (data->player.dir_y  * cos(ROTATE_SPEED * ONEDEG)));
	data->player.plane_x = ((data->player.plane_x * cos(ROTATE_SPEED * ONEDEG)) - (data->player.plane_y  * sin(ROTATE_SPEED * ONEDEG)));
	data->player.plane_y = ((old_plane_x * sin(ROTATE_SPEED * ONEDEG)) + (data->player.plane_y  * cos(ROTATE_SPEED * ONEDEG)));
	// mlx_destroy_image(data->mlx_connection , data->img->img_ptr);
	// raycasting(&data->player, data);
}

void	rotate_left(t_data *data)
{
	double old_dir_x;
    double old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	data->player.dir_x =  ((data->player.dir_x * cos(ROTATE_SPEED * ONEDEG)) + (data->player.dir_y  * sin(ROTATE_SPEED * ONEDEG)));
	data->player.dir_y = ((old_dir_x * (-1) *sin(ROTATE_SPEED * ONEDEG)) + (data->player.dir_y  * cos(ROTATE_SPEED * ONEDEG)));
	data->player.plane_x = ((data->player.plane_x * cos(ROTATE_SPEED * ONEDEG)) + (data->player.plane_y  * sin(ROTATE_SPEED * ONEDEG)));
	data->player.plane_y = ((old_plane_x * (-1) * sin(ROTATE_SPEED * ONEDEG)) + (data->player.plane_y  * cos(ROTATE_SPEED * ONEDEG)));
	// mlx_destroy_image(data->mlx_connection , data->img->img_ptr);
	// raycasting(&data->player, data);
}

#include "../../inc/cub3d.h"

int	 shoot_event(int keysym, int x, int y, t_data *data)
{
	if (keysym == 1)
	{
		data->player.is_firing = 1;
		data->player.fire_frame = 0;
	}
	return (0);
}

void	render_weapon(t_data *data)
{
	if (data->player.is_firing)
	{
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->player.weapon[data->player.fire_frame].img_ptr, ((WIDTH - data->player.weapon[data->player.fire_frame].width) / 2) + 100, 400);
		data->player.fire_frame++;
	}
	if (data->player.fire_frame >= 4)
	{
		data->player.fire_frame = 0;
		data->player.is_firing = 0;
	}
	else
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->player.weapon[0].img_ptr, ((WIDTH - data->player.weapon[SIMPLE].width) / 2) + 100, 400);
}
#include "../../inc/cub3d.h"

void	render_weapon(t_data *data)
{
	struct timeval current_time;
	long		   delta_time;
	gettimeofday(&current_time, NULL);
	delta_time =(current_time.tv_sec - data->player.anim.last_update.tv_sec) * 1000000 + (current_time.tv_usec - data->player.anim.last_update.tv_usec);
	if (delta_time >= ANIM)
	{
		data->player.anim.current_frame++;
		if (data->player.anim.current_frame >= 4)
		{
			data->player.anim.current_frame = 0;
			data->player.is_firing = 0;
		}
		data->player.anim.last_update = current_time;
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->player.weapon[data->player.anim.current_frame].img_ptr,((WIDTH - data->player.weapon[SIMPLE].width) / 2) + 100, 400);
	}
	mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->player.weapon[data->player.anim.current_frame].img_ptr,((WIDTH - data->player.weapon[SIMPLE].width) / 2) + 100, 400);
}
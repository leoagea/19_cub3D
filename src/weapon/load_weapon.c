#include "../../inc/cub3d.h"

void	load_weapon(t_data *data)
{
	int i;

	i = 0;
	data->player.weapon[SIMPLE].img_ptr = mlx_xpm_file_to_image(data->mlx_connection, "./weapon/gun1.xpm", &data->player.weapon[SIMPLE].width, &data->player.weapon[SIMPLE].width);
	data->player.weapon[SHOOT].img_ptr = mlx_xpm_file_to_image(data->mlx_connection, "./weapon/gun2.xpm", &data->player.weapon[SHOOT].width, &data->player.weapon[SHOOT].width);
	data->player.weapon[RECOIL].img_ptr = mlx_xpm_file_to_image(data->mlx_connection, "./weapon/gun3.xpm", &data->player.weapon[RECOIL].width, &data->player.weapon[RECOIL].width);
	data->player.weapon[REPLACE].img_ptr = mlx_xpm_file_to_image(data->mlx_connection, "./weapon/gun4.xpm", &data->player.weapon[REPLACE].width, &data->player.weapon[REPLACE].width);
	while (i < 4)
	{
		if (data->player.weapon[i].img_ptr == NULL)
			exit (1);  //LEAK !!!!
		i++;
	}
	i = 0;
	while (i < 1)
	{
		data->player.weapon[i].img_pixels_ptr = mlx_get_data_addr(data->player.weapon[i].img_ptr, &data->player.weapon[i].bits_per_pixel, &data->player.weapon[i].size_line, &data->player.weapon[i].endian);
		i++;
	}
}

void	draw_weapon(t_data *data, int weapon_pos)
{
	int x_start;
	int y_start;

	x_start = ((WIDTH - data->player.weapon[weapon_pos].width) / 2) + 100;
	y_start = 400;
	mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->player.weapon[weapon_pos].img_ptr, x_start, y_start);
}
#include "../../inc/cub3d.h"

void	load_weapon(t_data *data)
{
	int i;

	i = 0;
	data->player.weapon[SIMPLE].img_ptr = mlx_xpm_file_to_image(data->mlx_connection, "assets/weapon/gun1.xpm", &data->player.weapon[SIMPLE].width, &data->player.weapon[SIMPLE].width);
	data->player.weapon[SHOOT].img_ptr = mlx_xpm_file_to_image(data->mlx_connection, "assets/weapon/gun2.xpm", &data->player.weapon[SHOOT].width, &data->player.weapon[SHOOT].width);
	data->player.weapon[RECOIL].img_ptr = mlx_xpm_file_to_image(data->mlx_connection, "assets/weapon/gun3.xpm", &data->player.weapon[RECOIL].width, &data->player.weapon[RECOIL].width);
	data->player.weapon[REPLACE].img_ptr = mlx_xpm_file_to_image(data->mlx_connection, "assets/weapon/gun4.xpm", &data->player.weapon[REPLACE].width, &data->player.weapon[REPLACE].width);
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
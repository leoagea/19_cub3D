#include "../../inc/cub3d.h"

void	wall_texture(t_data *data, t_player *player, int i)
{
	int	j;
	uint32_t color;
	int pixel_index;
	unsigned char *pixel;

	if (player->side == 0)
		data->wall.wall_coord = player->pos_y + player->perp_wall_dist * player->ray_dir_y;
	else
		data->wall.wall_coord = player->pos_x + player->perp_wall_dist * player->ray_dir_x;
	data->wall.wall_coord -= floor(data->wall.wall_coord);
	data->wall.tex_x = (int) (data->wall.wall_coord * (double)(TEXWIDTH));
	if ((player->side == 0 && player->ray_dir_x > 0) || (player->side == 1 && player->ray_dir_y > 0))
		data->wall.tex_x = TEXWIDTH - data->wall.tex_x - 1;
	data->wall.step = 1.0 * TEXHEIGHT / player->wall_height;
	data->wall.tex_pos = (player->draw_start - HEIGHT / 2 + player->wall_height / 2) * data->wall.step;
	j = player->draw_start;
	while (j < player->draw_end)
	{
		data->wall.tex_y = (int) data->wall.tex_pos & (TEXHEIGHT - 1);
		data->wall.tex_pos += data->wall.step;
		side_view(player);
		pixel_index = (data->wall.tex_y * TEXWIDTH + data->wall.tex_x) * (data->texture[player->side_view].bits_per_pixel / 8);
		pixel = (unsigned char *)&data->texture[player->side_view].img_pixels_ptr[pixel_index];
        color = (pixel[2] << 16) | (pixel[1] << 8) | pixel[0];  // RGB
		draw_point(data, i, j, color);
		j++;
	}
}

void	side_view(t_player *player)
{
	if (player->side == 1 && player->ray_dir_y < 0)
		player->side_view = NO;
	if (player->side == 1 && player->ray_dir_y > 0)
		player->side_view = SO;
	if (player->side == 0 && player->ray_dir_x < 0)
		player->side_view = WE;
	if (player->side == 0 && player->ray_dir_x > 0)
		player->side_view = EA;
}
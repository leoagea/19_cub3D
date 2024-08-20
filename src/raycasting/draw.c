#include "../../inc/cub3d.h"

void	draw(t_data *data, t_player *player)
{
	int	i;
	int	total;

	i = 0;
	total = HEIGHT * WIDTH;
	while (i < HEIGHT)
	{
		if (i >= player->draw_start && i <= player->draw_end)
			draw_point(data, player->column, i, 255);
		else
			draw_point(data, player->column, i, 0);
		i++;
	}
	player->column++;
}

void	draw_point(t_data *data, int x, int y, int color)
{
	int	pixel;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel = (y * data->img->size_line) + (x * (data->img->bits_per_pixel
					/ 8));
		if (data->img->endian == 0)
		{
			data->img->img_pixels_ptr[pixel + 0] = (color & 0xFF);
			data->img->img_pixels_ptr[pixel + 1] = (color >> 8) & 0xFF;
			data->img->img_pixels_ptr[pixel + 2] = (color >> 16) & 0xFF;
			data->img->img_pixels_ptr[pixel + 3] = (color >> 24) & 0xFF;
		}
		else
		{
			data->img->img_pixels_ptr[pixel + 0] = (color >> 24) & 0xFF;
			data->img->img_pixels_ptr[pixel + 1] = (color >> 16) & 0xFF;
			data->img->img_pixels_ptr[pixel + 2] = (color >> 8) & 0xFF;
			data->img->img_pixels_ptr[pixel + 3] = (color & 0xFF);
		}
	}
}

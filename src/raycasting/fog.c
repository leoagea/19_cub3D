#include "../../inc/cub3d.h"

float calculate_fog(float distance, float max_fog_dist)
{
	if (distance >= max_fog_dist)
		return (1.0);
	return (distance / max_fog_dist);
}

uint32_t apply_fog(uint32_t color, float fog_factor)
{
    uint8_t color_r = (color >> 16) & 0xFF;
    uint8_t color_g = (color >> 8) & 0xFF;
    uint8_t color_b = color & 0xFF;

    uint8_t fogged_r = (1 - fog_factor) * color_r + fog_factor * FOG_R;
    uint8_t fogged_g = (1 - fog_factor) * color_g + fog_factor * FOG_G;
    uint8_t fogged_b = (1 - fog_factor) * color_b + fog_factor * FOG_B;

    return (fogged_r << 16) | (fogged_g << 8) | fogged_b;
}

void draw_with_fog(t_data *data, int x, int y, uint32_t color, float distance)
{
    float fog_factor;
    uint32_t fogged_color;

	fog_factor = calculate_fog(distance, FOG_DIST);
	fogged_color = apply_fog(color, fog_factor);
    *(uint32_t *)(data->img->img_pixels_ptr + y * data->img->size_line + x * (data->img->bits_per_pixel / 8)) = fogged_color;
}

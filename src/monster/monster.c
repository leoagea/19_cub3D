#include "../../inc/cub3d.h"

void	init_enemy(t_data *data, t_enemy *enemy)
{
	int i;
	int j;
	char tab[6][100] = {"monster/SlayerSimple.xpm", "monster/SlayerShoot.xpm", "monster/SlayerDeath1.xpm",
		   			 "monster/SlayerDeath2.xpm", "monster/SlayerDeath3.xpm", "monster/SlayerDeath4.xpm"};
	j = 0;
	while (j < data->nb_enemy)
	{
		i = -1;
		enemy[j].current_frame = 0;
		enemy[j].number_frames = 6;
		enemy[j].hp = 2;
		enemy[j].has_shot = 0;
		enemy[j].was_shot = 0;
		enemy[j].died = 0;
		enemy[j].cadavre = 0;
		gettimeofday(&enemy[i].last_update, NULL);
		while (++i < 6)
		{
			enemy[j].img_frames[i].img_ptr = mlx_xpm_file_to_image(data->mlx_connection, tab[i], &enemy[j].width, &enemy[j].height);
			if (enemy[j].img_frames[i].img_ptr == NULL)
				exit(1); //LEAK
			enemy[j].img_frames[i].img_pixels_ptr = mlx_get_data_addr(enemy[j].img_frames[i].img_ptr, &enemy[j].img_frames[i].bits_per_pixel, &enemy[j].img_frames[i].size_line, &enemy[j].img_frames[i].endian);
		}
		enemy[j].last_shoot_time = time(NULL);
		j++;
	}
	data->player.sprite_order = malloc(sizeof(int) * data->nb_enemy);
	data->player.sprite_dist = malloc(sizeof(double) * data->nb_enemy);
}

void sort_sprites(t_data * data, t_player *player)
{
	int		i;
	int		j;
	double  tmp;
	int 	is_sort;

	i = data->nb_enemy;
	while (i > 0)
	{
		j = 0;
		while (j < i - 1)
		{
			if (player->sprite_dist[j] < player->sprite_dist[j + 1])
			{
				tmp = player->sprite_dist[j];
				player->sprite_dist[j] =  player->sprite_dist[j + 1];
				player->sprite_dist[j + 1] = tmp;
				tmp = player->sprite_order[j];
				player->sprite_order[j] =  player->sprite_order[j + 1];
				player->sprite_order[j + 1] = tmp;
			}
			j++;
		}
		i--;
	}
}

void	enemy_calculation(t_data *data, t_player *player, t_enemy *enemy)
{
	int i;

	i = 0;
	while (i < data->nb_enemy)
	{
		player->sprite_order[i] = i;
		player->sprite_dist[i] = sqrt(((player->pos_x - enemy[i].pos_x) * (player->pos_x - enemy[i].pos_x)) + ((player->pos_y - enemy[i].pos_y) * (player->pos_y - enemy[i].pos_y)));
		i++;
	}
	sort_sprites(data, player);
	i = 0;
	while (i < data->nb_enemy)
	{
		enemy_raycast(player, enemy, i);
		enemy_draw(data, player, enemy, i);
		i++;
	}
}

void	enemy_raycast(t_player *player, t_enemy *enemy, int i)
{
	enemy[player->sprite_order[i]].pos_x_cam = enemy[player->sprite_order[i]].pos_x - player->pos_x;
	enemy[player->sprite_order[i]].pos_y_cam = enemy[player->sprite_order[i]].pos_y - player->pos_y;
	enemy[player->sprite_order[i]].inverse_matrix = 1.0 / (player->plane_x * player->dir_y - player->plane_y * player->dir_x);
	enemy[player->sprite_order[i]].transform_x = enemy[player->sprite_order[i]].inverse_matrix * (player->dir_y * enemy[player->sprite_order[i]].pos_x_cam - player->dir_x * enemy[player->sprite_order[i]].pos_y_cam);
	enemy[player->sprite_order[i]].transform_y = enemy[player->sprite_order[i]].inverse_matrix * (-player->plane_y * enemy[player->sprite_order[i]].pos_x_cam + player->plane_x * enemy[player->sprite_order[i]].pos_y_cam);
	enemy[player->sprite_order[i]].sprite_screen_x = (int)((WIDTH / 2) * (1 + enemy[player->sprite_order[i]].transform_x / enemy[player->sprite_order[i]].transform_y));
	enemy[player->sprite_order[i]].height = abs((int)(HEIGHT / enemy[player->sprite_order[i]].transform_y));
	enemy[player->sprite_order[i]].draw_start_y = -enemy[player->sprite_order[i]].height / 2 + HEIGHT / 2;
	if (enemy[player->sprite_order[i]].draw_start_y < 0)
		enemy[player->sprite_order[i]].draw_start_y = 0;
	enemy[player->sprite_order[i]].draw_end_y = enemy[player->sprite_order[i]].height / 2 + HEIGHT / 2;
	if (enemy[player->sprite_order[i]].draw_end_y >= HEIGHT)
		enemy[player->sprite_order[i]].draw_end_y = HEIGHT - 1;
	enemy[player->sprite_order[i]].width = abs((int)(HEIGHT / enemy[player->sprite_order[i]].transform_y));
	enemy[player->sprite_order[i]].draw_start_x = -enemy[player->sprite_order[i]].width / 2 + enemy[player->sprite_order[i]].sprite_screen_x;
	if (enemy[player->sprite_order[i]].draw_start_x < 0)
		enemy[player->sprite_order[i]].draw_start_x = 0;
	enemy[player->sprite_order[i]].draw_end_x = enemy[player->sprite_order[i]].width / 2 + enemy[player->sprite_order[i]].sprite_screen_x;
	if (enemy[player->sprite_order[i]].draw_end_x >= WIDTH)
		enemy[player->sprite_order[i]].draw_end_x = WIDTH - 1;
}

void	enemy_draw(t_data *data, t_player* player, t_enemy *enemy, int i)
{
	int	tex_x;
	int tex_y;
	uint32_t color;
	int	pix;
	int l;
	time_t current_time;
    double elapsed_time;

    current_time = time(NULL);
    elapsed_time = difftime(current_time, enemy[player->sprite_order[i]].last_shoot_time);

	player->col = enemy[player->sprite_order[i]].draw_start_x;
    if (elapsed_time < SHOOT_DURATION)
	{
        enemy[player->sprite_order[i]].current_frame = SHOOT;
		if (enemy[player->sprite_order[i]].transform_y > 0
            && enemy[player->sprite_order[i]].sprite_screen_x > 0
            && enemy[player->sprite_order[i]].sprite_screen_x < WIDTH
			&& enemy[player->sprite_order[i]].transform_y < player->z_buffer[player->col]
            && !enemy[player->sprite_order[i]].has_shot) 
		{
            take_damage(player); 
            enemy[player->sprite_order[i]].has_shot = 1;
        }
	}
	else if (elapsed_time < SHOOT_DURATION + STOP_DURATION)
	{
        enemy[player->sprite_order[i]].current_frame = STAND;
		enemy[player->sprite_order[i]].has_shot = 0;
	}
	else 
	{
        enemy[player->sprite_order[i]].last_shoot_time = current_time;
        enemy[player->sprite_order[i]].current_frame = SHOOT;
		enemy[player->sprite_order[i]].has_shot = 0;
    }
	while (player->col < enemy[player->sprite_order[i]].draw_end_x)
	{
		tex_x = (int) (256 * (player->col - (-enemy[player->sprite_order[i]].width / 2 + enemy[player->sprite_order[i]].sprite_screen_x)) * TEXWIDTH / enemy[player->sprite_order[i]].width) / 256;
		pix = enemy[player->sprite_order[i]].draw_start_y;
		if (enemy[player->sprite_order[i]].transform_y > 0 && player->col > 0
			&& player->col < WIDTH && enemy[player->sprite_order[i]].transform_y < player->z_buffer[player->col])
		{
			while (pix < enemy[player->sprite_order[i]].draw_end_y)
			{
				l = pix * 256 - HEIGHT * 128 + enemy[player->sprite_order[i]].height * 128;
				tex_y = ((l * TEXHEIGHT) / enemy[player->sprite_order[i]].height) / 256;
				color = *(uint32_t *)(enemy[player->sprite_order[i]].img_frames[enemy[player->sprite_order[i]].current_frame].img_pixels_ptr 
									+ (tex_y * enemy[player->sprite_order[i]].img_frames[enemy[player->sprite_order[i]].current_frame].size_line 
									+ tex_x * (enemy[player->sprite_order[i]].img_frames[enemy[player->sprite_order[i]].current_frame].bits_per_pixel / 8)));
				if ((color & 0x00FFFFFF) != 0)
					*(uint32_t *)(data->img->img_pixels_ptr + pix * data->img->size_line + player->col * (data->img->bits_per_pixel / 8)) = color;
				pix++;
			}
		}
		player->col++;
	}
}

void	enemy_draw_dead(t_data *data, t_player *player, t_enemy *enemy, int i)
{
	int	tex_x;
	int tex_y;
	uint32_t color;
	int	pix;
	int l;

	player->col = enemy[player->sprite_order[i]].draw_start_x;
	while (player->col < enemy[player->sprite_order[i]].draw_end_x)
	{
		tex_x = (int) (256 * (player->col - (-enemy[player->sprite_order[i]].width / 2 + enemy[player->sprite_order[i]].sprite_screen_x)) * TEXWIDTH / enemy[player->sprite_order[i]].width) / 256;
		pix = enemy[player->sprite_order[i]].draw_start_y;
		if (enemy[player->sprite_order[i]].transform_y > 0 && player->col > 0
			&& player->col < WIDTH && enemy[player->sprite_order[i]].transform_y < player->z_buffer[player->col])
		{
			while (pix < enemy[player->sprite_order[i]].draw_end_y)
			{

				l = pix * 256 - HEIGHT * 128 + enemy[player->sprite_order[i]].height * 128;
				tex_y = ((l * TEXHEIGHT) / enemy[player->sprite_order[i]].height) / 256;
				color = *(uint32_t *)(enemy[player->sprite_order[i]].img_frames[enemy[player->sprite_order[i]].current_frame].img_pixels_ptr 
									+ (tex_y * enemy[player->sprite_order[i]].img_frames[enemy[player->sprite_order[i]].current_frame].size_line 
									+ tex_x * (enemy[player->sprite_order[i]].img_frames[enemy[player->sprite_order[i]].current_frame].bits_per_pixel / 8)));
				if ((color & 0x00FFFFFF) != 0)
					*(uint32_t *)(data->img->img_pixels_ptr + pix * data->img->size_line + player->col * (data->img->bits_per_pixel / 8)) = color;
				pix++;
			}
		}
		player->col++;
	}
}
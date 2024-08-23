/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:18:48 by lagea             #+#    #+#             */
/*   Updated: 2024/08/23 02:03:30 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void draw_minimap(t_data *data)
{
	int i;
	int j;
	char **map;
	
	int start_x;
	int start_y;
	i = 0;
	map = data->file->map;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == '1')
			{
				start_x = data->minimap->start_x + (data->minimap->cell_width * j);
				start_y = data->minimap->start_y + (data->minimap->cell_height * i);
				draw_cell(data, start_x, start_y, 5984850);
			}
			j++;
		}
		i++;
	}
	draw_cell(data,(data->minimap->cell_width * (int)data->player->pos_x) + data->minimap->start_x, (data->minimap->cell_height * (int) data->player->pos_y ) + data->minimap->start_y, 12779520);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->img->img_ptr, 0, 0);
}

// void	draw_zone_4x4(t_data *data, char **arr, int x, int y)
// {
//     int	start_x = x - 2;  // Position de départ en x pour un carré 4x4
//     int	start_y = y - 2;  // Position de départ en y pour un carré 4x4
//     int	color;
//     int i, j;

//     for (i = 0; i < 4; i++)  // Boucle pour la hauteur (4 pixels)
//     {
//         for (j = 0; j < 4; j++)  // Boucle pour la largeur (4 pixels)
//         {
//             if (start_x + j >= 0 && start_y + i >= 0)  // Vérifier les limites
//             {
//                 if (arr[start_y + i][start_x + j] == '1')
//                     color = 5984850;  // Blanc pour les murs
//                 else
//                     color = 16777215;  // Noir pour les espaces vides
//                 draw_point(data, start_x + j, start_y + i, color);
//             }
//         }
//     }
// }	

void	draw_square(t_data *data, int x, int y, int size, int color)
{
    int	i;
    int	j;

    for (i = 0; i < size; i++)  // Pour chaque ligne de 25 pixels
    {
        for (j = 0; j < size; j++)  // Pour chaque colonne de 25 pixels
        {
            draw_point(data, x + j, y + i, color);
        }
    }
}

// Fonction pour dessiner une zone de 4x4 cellules autour de la position (x, y)
void	draw_zone_4x4(t_data *data, char **arr, int x, int y, int cell_size)
{
    int	start_x = (x - 2) * cell_size;  // Position de départ en x pour le carré 4x4
    int	start_y = (y - 2) * cell_size;  // Position de départ en y pour le carré 4x4
    int	color;
    int i, j;

    for (i = 0; i < 4; i++)  // Boucle pour 4 cellules verticales
    {
        for (j = 0; j < 4; j++)  // Boucle pour 4 cellules horizontales
        {
            if ((x - 2 + j) >= 0 && (y - 2 + i) >= 0 && arr[y - 2 + i] != NULL)  // Vérification des limites
            {
                if (arr[y - 2 + i][x - 2 + j] == '1')
                    color = 5984850;  // Blanc pour les murs
                else
                    color = 16777215;  // Noir pour les espaces vides

                // Dessiner une cellule 25x25 pixels
                draw_square(data, start_x + j * cell_size, start_y + i * cell_size, cell_size, color);
            }
        }
    }
}

void create_minimap(t_data *data)
{
    init_minimap_struct(data);
	// draw_minimap(data);
	// int start_x;
	// int start_y;

	// draw_square(data, (int)data->player->pos_x, (int)data->player->pos_y, 25, 5984850);
	// start_y = (int) data->player->pos_y - 2;
	// for(int start_y = (int) data->player->pos_y - 2; start_y < data->player->pos_y + 2; start_y++)
	for(int i = -2; i < 4; i++)
	{
		for(int j = -2; j < 4; j++)
		{
			if (data->file->map[(int) data->player->pos_y - i][(int) data->player->pos_x - j] && data->file->map[(int) data->player->pos_y - i][(int) data->player->pos_x - j] == '1')
				draw_square(data, (j * 25) + data->minimap->start_x, (i * 25) + data->minimap->start_y, 25, 5984850);
		}
	}
	draw_square(data, (int) data->minimap->start_x + 6, (int)data->player->pos_y + 50, 12, 1653652);
	// draw_zone_4x4(data,data->file->map, (int)data->player->pos_x, (int)data->player->pos_y, 25);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->img->img_ptr, 0, 0);
}

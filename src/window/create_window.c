#include "../../inc/cub3d.h"

void	create_window(t_data *data)
{
	data->img = malloc(sizeof(t_img));
	if (!data->img)
	{
		free(data);
		exit(1);
	}
	data->mlx_connection = mlx_init();
	if (!data->mlx_connection)
		exit_malloc();
	data->mlx_window = mlx_new_window(data->mlx_connection, WIDTH, HEIGHT,
			"Cub3D");
	if (!data->mlx_window)
		error_window(data);
}

void	error_window(t_data *data)
{
	free(data->mlx_connection);
	free(data->img);
	free(data);
	write(2, "Error while creating new window\n", 33);
	mlx_destroy_image(data->mlx_connection, data->img->img_ptr);
	mlx_destroy_window(data->mlx_connection, data->mlx_window);
	exit(1);
}
#include "../../inc/cub3d.h"

t_data	*create_window(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		exit(1);
	data->img = malloc(sizeof(t_img));
	if (!data->img)
	{
		free(data);
		exit(1);
	}
	data->mlx_connection = mlx_init();
	if (!data->mlx_connection)
	{
		free(data->img);
		free(data);
		exit_malloc();
	}
	data->mlx_window = mlx_new_window(data->mlx_connection, WIDTH, HEIGHT,
			"Fdf");
	if (!data->mlx_window)
		error_window(data);
	return (data);
}
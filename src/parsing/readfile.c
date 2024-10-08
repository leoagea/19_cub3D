/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:19:12 by lagea             #+#    #+#             */
/*   Updated: 2024/09/06 17:50:50 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	count_lines(int fd)
{
	int		count;
	char	*line;

	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	return (count);
}

static void	get_file_data(t_data *data, int fd)
{
	int		i;
	char	*line;

	line = get_next_line(fd);
	if (line)
	{
		data->file.file[0] = ft_strdup(line);
		if (!data->file.file[0])
		{
			free(line);
			ft_error(ERR_ALLOC, data);
		}
		free(line);
	}
	i = 1;
	while (line != NULL)
	{
		line = get_next_line(fd);
		data->file.file[i] = ft_strdup(line);
		if (!data->file.file[i])
			ft_error(ERR_ALLOC, data);
		i++;
		free(line);
	}
}

void	open_file(t_data *data, char *file)
{
	int	fd;

	(void)data;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Scene description file, ");
		printf("%s\n", strerror(errno));
		exit(1);
	}
	data->file.line = count_lines(fd);
	close(fd);
	if (data->file.line == 0)
		ft_error(ERR_EMPTY, data);
	data->file.file = malloc(sizeof(char *) * (data->file.line + 1));
	ft_memset(data->file.file, 0, sizeof(char *) * (data->file.line + 1));
	if (!data->file.file)
		ft_error(ERR_ALLOC, data);
	fd = open(file, O_RDONLY);
	get_file_data(data, fd);
	close(fd);
}

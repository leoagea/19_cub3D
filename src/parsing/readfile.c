/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:19:12 by lagea             #+#    #+#             */
/*   Updated: 2024/08/16 17:38:48 by lagea            ###   ########.fr       */
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

static	void get_file_data(t_data *data, int fd)
{
    int i;
    char *line;
    
    i = 0;
    line = get_next_line(fd);
    if (line)
        data->file.file[i] = ft_strdup(line);
    i++;
    while (line)
    {
        line = get_next_line(fd);
        data->file.file[i] = ft_strdup(line);
        i++;
    }
	data->file.file[i] = NULL;
}

void	open_file(t_data *data, char *file)
{
	int	fd;
	int	count;

	(void)data;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Scene description file, ");
		printf("%s\n", strerror(errno));
		exit(1);
	}
	count = count_lines(fd);
	close(fd);
    if (count == 0)
		ft_error(ERR_EMPTY);
	data->file.file = malloc(sizeof(char *) * count + 1);
	if (!data->file.file)
		ft_error(ERR_ALLOC);
	fd = open(file, O_RDONLY);
	get_file_data(data, fd);
	close(fd);
}

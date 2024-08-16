/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:20:15 by lagea             #+#    #+#             */
/*   Updated: 2024/08/16 19:47:40 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int rgb2(int r, int g, int b) {
    return (r << 16) | (g << 8) | b;
}

void    parsing(int ac, char **av, t_data *data)
{
    if (ac != 2)
        ft_error(ERR_ARG, data);
    check_file_extension(av[1], data);
    init_struct_file(data);
    open_file(data, av[1]);
    data->file->wall_no = ft_strchr(data->file->file[0], '.');
    data->file->wall_so = ft_strchr(data->file->file[1], '.');
    data->file->wall_we = ft_strchr(data->file->file[2], '.');
    data->file->wall_ea = ft_strchr(data->file->file[3], '.');
    data->file->color_floor = data->file->file[4];
    data->file->color_ceiling = data->file->file[5];
    data->file->map = malloc(sizeof(char *) * data->file->line - 5 + 1);
    int i = 6;
    int j = 0;
    // printf("line : %d", data->file->line);
    while(data->file->file[i] && j < data->file->line - 5)
    {
        // printf("t\n");
        data->file->map[j] = ft_strdup(data->file->file[i]);
        // printf("%s", data->file->map[j]);
        i++;
        j++;
    }
    // printf("test\n");
    // data->file->map[j - 1] = NULL;
    data->file->wall_no = ft_strtrim(data->file->wall_no, "\n");
    data->file->wall_so = ft_strtrim(data->file->wall_so, "\n");
    data->file->wall_we = ft_strtrim(data->file->wall_we, "\n");
    data->file->wall_ea = ft_strtrim(data->file->wall_ea, "\n");
    data->file->color_floor = ft_strtrim(data->file->color_floor, "\n");
    data->file->color_ceiling = ft_strtrim(data->file->color_ceiling, "\n");
    char *r = ft_substr(data->file->color_floor, 2,3);
    char *g = ft_substr(data->file->color_floor, 6,3);
    char *b = ft_substr(data->file->color_floor, 9,1);
    int r_ = ft_atoi(r);
    int g_ = ft_atoi(g);
    int b_ = ft_atoi(b);
    data->file->c_floor = rgb2(r_, g_, b_);
    r = ft_substr(data->file->color_ceiling, 2,3);
    g = ft_substr(data->file->color_ceiling, 6,2);
    b = ft_substr(data->file->color_ceiling, 9,1);
    r_ = ft_atoi(r);
    g_ = ft_atoi(g);
    b_ = ft_atoi(b);
    data->file->c_ceiling= rgb2(r_, g_, b_);
    printf("test 3\n"); 
    printf("r : %s, g : %s, b : %s\n",r ,g ,b );
    printf("wall no : %s\n", data->file->wall_no); 
    printf("wall so : %s\n", data->file->wall_so);  
    printf("wall we : %s\n", data->file->wall_we);
    printf("wall ew : %s\n", data->file->wall_ea);
    printf("color f : %s\n", data->file->color_floor);
    printf("color c : %s\n", data->file->color_ceiling);
    printf("int color f : %d\n", data->file->c_floor);
    printf("int color f : %d\n", data->file->c_ceiling);
    int p = 0;
    while (p < data->file->line - 6)
    {
        printf("%s", data->file->map[p]);
        p++;
    }
}
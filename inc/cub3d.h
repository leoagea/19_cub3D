/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:15:25 by lagea             #+#    #+#             */
/*   Updated: 2024/08/16 14:59:13 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../libft/libft.h"

#define ERR_ARG "Error: Wrong number of arguments, expected only 2 arguments"
#define ERR_EXT "Error: Wrong file extension, expected only .cub extension"

/*========================Parsing=========================*/
/*-----------------------check_arg------------------------*/

void check_file_extension(char *file);

/*=========================Utils==========================*/
/*-----------------------Utils_exit-----------------------*/

void ft_error(char *str);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:17:31 by rohidalg          #+#    #+#             */
/*   Updated: 2024/03/08 19:53:45 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_check_outline(t_map *data)
{
    int i;
    int fail;

    i = 0;
    fail = 0;
    while (i < data->width)
    {
        if (data->map[i][0] != '1' || data->map[i][data->hight - 1] != '1')
            fail = 1;
        i++;
    }
    i = 0;
    while (i < data->hight)
    {
        if (data->map[0][i] != '1' || data->map[data->width - 1][i] != '1')
            fail = 1;
        i++;
    }
    if (fail != 0)
    {
        write(2, "\n\nOUTLINE_FAILED\n\n", 19);
        exit(EXIT_FAILURE);
    }
}

void ft_check_ber(t_map *data)
{
    if (ft_strcmp(&data->txt[ft_strlen(data->txt) - 4], ".ber") != 0 || ft_strlen(data->txt) <= 4)
    {
        write(2, "\n\n.ber_FAILED\n\n", 16);
        exit(EXIT_FAILURE);
    }
}

void ft_check_char(t_map *data)
{
    int i;
    int j;

    j = 0;
    while(data->map[j])
    {
        i = 0;
        while(data->map[i][j])
        {
            if (data->map[i][j] != '1' && data->map[i][j] != '0' && 
            data->map[i][j] != 'P' && data->map[i][j] != 'E' && data->map[i][j] != 'C')
            {
                write(2, "\n\nCHAR_ERROR\n\n", 15);
                exit(EXIT_FAILURE);
            }
            else
            i++;
        }
        j++;
    }
}

void ft_check_double(t_map *data)
{
    int i;
    int j;
    int end;

    j = -1;
    end = 0;
    while(data->map[j++])
    {
        i = -1;
        while(data->map[i++][j])
        {
            if (data->map[i][j] == 'P')
                data->player++;
            if (data->map[i][j] == 'E')
                end++;
            if (data->map[i][j] == 'C')
                data->count++;
        }
    }
    if (data->player != 1 || end != 1 || data->count < 1)
    {
        write(2, "\n\nDOUBLE_ERROR\n\n", 17);
        exit(EXIT_FAILURE);
    }
}



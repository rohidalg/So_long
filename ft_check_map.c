/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:17:31 by rohidalg          #+#    #+#             */
/*   Updated: 2024/03/06 19:11:18 by rohidalg         ###   ########.fr       */
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
        write(2, "OUTLINE FAILED\n", 16);
        exit(EXIT_FAILURE);
    }
}

void ft_check_ber(t_map *data)
{
    if (ft_strcmp(&data->txt[ft_strlen(data->txt) - 4], ".ber") != 0 || ft_strlen(data->txt) <= 4)
    {
        write(2, ".ber FAILED", 12);
        exit(EXIT_FAILURE);
    }
}

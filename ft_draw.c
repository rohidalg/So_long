/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:50:25 by rohidalg          #+#    #+#             */
/*   Updated: 2024/02/20 17:15:45 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_draw()
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    
    while(map)
    {
        while(i != '\0')
        {
            if (i == 1)
                wall.xpm;
            else if (i == 0)
                floor.xpm;
            else if (i == p)
                character.xpm;
            else if (i == c)
                object.xpm;
            else if (i == e)
                exit.xpm;
            i++;
        }
        j++;
    }
}

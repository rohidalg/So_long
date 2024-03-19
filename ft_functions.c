/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:55:27 by rohidalg          #+#    #+#             */
/*   Updated: 2024/03/19 18:29:10 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// char *ft_strcpy(char *s1, char *s2)
// {
//     int i;

//     i = -1;
//     while (s2[i++])
//     {
//         s1[i] = s2[i];
//     s1[i] = '\0';
//     return (s1);
//     }
// }

// char *ft_strdup(char *s)
// {
//     char *dup;
//     int i;

//     dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
//     i = 0;
//     if (!dup)
//         return(0);
//     ft_strcpy(dup, s);
//     return (dup);
// }

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_itoa(unsigned int n)
{
	char	c;

	if (n >= 10)
		ft_itoa(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

// void	ft_write_itoa(unsigned int n)
// {
// 	write(1, "Number of steps: ", 17);
// 	ft_itoa(n);
// 	write(1, "\n", 1);
// }

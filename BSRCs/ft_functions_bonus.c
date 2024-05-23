/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:55:27 by rohidalg          #+#    #+#             */
/*   Updated: 2024/05/23 18:33:16 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_numlen(int n, int base)
{
	int	count;

	count = 0;
	if (n <= 0)
		++count;
	while (n && ++count)
		n /= base;
	return (count);
}

char	*ft_itoa_bonus(int n)
{
	int			len;
	char		*ret;
	const char	*digits;

	digits = "0123456789";
	len = ft_numlen(n, 10);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ret[len] = 0;
	if (n == 0)
		ret[0] = '0';
	if (n < 0)
		ret[0] = '-';
	while (n)
	{
		if (n > 0)
			ret[--len] = digits[n % 10];
		else
			ret[--len] = digits[n % 10 * -1];
		n /= 10;
	}
	return (ret);
}

void	ft_write_bonus(t_map *data)
{
	char	*movements;

	movements = ft_itoa_bonus(data->move);
	mlx_string_put(data->mlx, data->win, 34, 34, 0x00000000, "Movements: ");
	mlx_string_put(data->mlx, data->win, 107, 34, 0x00000000, movements);
	mlx_string_put(data->mlx, data->win, 33, 33, 0xFFFFFFFF, "Movements: ");
	mlx_string_put(data->mlx, data->win, 106, 33, 0xFFFFFFFF, movements);
	free(movements);
}

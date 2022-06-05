/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:08:28 by labenall          #+#    #+#             */
/*   Updated: 2022/06/03 19:40:56 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	handler_enemy(t_mlx **g_mlx, int k)
{
	void	*img_m;
	void	*img_0;

	(*g_mlx)->map->map_array[(*g_mlx)->x[k]][(*g_mlx)->y[k] + 1] = 'M';
	(*g_mlx)->map->map_array[(*g_mlx)->x[k]][(*g_mlx)->y[k]] = '0';
	img_m = mlx_xpm_file_to_image((*g_mlx)->mlx_ptr, \
			(*g_mlx)->image->m, &(*g_mlx)->width, &(*g_mlx)->height);
	mlx_put_image_to_window((*g_mlx)->mlx_ptr, (*g_mlx)->window_ptr, img_m, \
			((*g_mlx)->y[k] + 1) * 64, ((*g_mlx)->x[k]) * 64);
	img_0 = mlx_xpm_file_to_image((*g_mlx)->mlx_ptr, \
			(*g_mlx)->image->k, &(*g_mlx)->width, &(*g_mlx)->height);
	mlx_put_image_to_window((*g_mlx)->mlx_ptr, (*g_mlx)->window_ptr, img_0, \
			((*g_mlx)->y[k]) * 64, (*g_mlx)->x[k] * 64);
	(*g_mlx)->y[k]++;
}

void	handler_enemy_miroir(t_mlx **g_mlx, int k)
{
	void	*img_m;
	void	*img_0;

	(*g_mlx)->map->map_array[(*g_mlx)->x[k]][(*g_mlx)->y[k] - 1] = 'M';
	(*g_mlx)->map->map_array[(*g_mlx)->x[k]][(*g_mlx)->y[k]] = '0';
	img_m = mlx_xpm_file_to_image((*g_mlx)->mlx_ptr, \
			(*g_mlx)->image->m_r, &(*g_mlx)->width, &(*g_mlx)->height);
	mlx_put_image_to_window((*g_mlx)->mlx_ptr, (*g_mlx)->window_ptr, img_m, \
			((*g_mlx)->y[k] - 1) * 64, ((*g_mlx)->x[k]) * 64);
	img_0 = mlx_xpm_file_to_image((*g_mlx)->mlx_ptr, \
			(*g_mlx)->image->k, &(*g_mlx)->width, &(*g_mlx)->height);
	mlx_put_image_to_window((*g_mlx)->mlx_ptr, (*g_mlx)->window_ptr, img_0, \
			((*g_mlx)->y[k]) * 64, (*g_mlx)->x[k] * 64);
	(*g_mlx)->y[k]--;
}

void	move_enemy(t_mlx **g_mlx, int n)
{
	int	k;

	k = -1;
	while (++k < n)
	{
		if ((*g_mlx)->t[k] == 0)
			help_animation_1(g_mlx, k);
		else
			help_animation_2(g_mlx, k);
	}
}

void	try_to_move_animy(t_mlx **g_mlx)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while ((*g_mlx)->map->map_array[i])
	{
		j = 0;
		while ((*g_mlx)->map->map_array[i][j])
		{
			if ((*g_mlx)->map->map_array[i][j] == 'M')
			{
				(*g_mlx)->x[n] = i;
				(*g_mlx)->y[n] = j;
				n++;
			}
			j++;
		}
		i++;
	}
	move_enemy(g_mlx, n);
}

int	animation(t_mlx **g_mlx)
{
	if ((*g_mlx)->animation == 2000)
	{
		try_to_move_animy(g_mlx);
		(*g_mlx)->animation = 0;
	}
	(*g_mlx)->animation++;
	return (0);
}

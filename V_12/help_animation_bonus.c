/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_animation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:25:35 by labenall          #+#    #+#             */
/*   Updated: 2022/06/04 21:25:38 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	help_animation_1(t_mlx **g_mlx, int k)
{
	if ((*g_mlx)->map->map_array[(*g_mlx)->x[k]][(*g_mlx)->y[k] + 1] \
	== '0')
		handler_enemy(g_mlx, k);
	else if ((*g_mlx)->map->map_array[(*g_mlx)->x[k]][(*g_mlx)->y[k] + 1] \
	== 'P')
		ft_exit(g_mlx, "chadak lboliss", 0);
	else
		(*g_mlx)->t[k] = 1;
}

void	help_animation_2(t_mlx **g_mlx, int k)
{
	if ((*g_mlx)->map->map_array[(*g_mlx)->x[k]][(*g_mlx)->y[k] - 1] \
	== '0')
		handler_enemy_miroir(g_mlx, k);
	else if ((*g_mlx)->map->map_array[(*g_mlx)->x[k]][(*g_mlx)->y[k] - 1] \
	== 'P')
		ft_exit(g_mlx, "chadak lboliss", 0);
	else
		(*g_mlx)->t[k] = 0;
}

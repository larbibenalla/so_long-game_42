/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:04:42 by labenall          #+#    #+#             */
/*   Updated: 2022/06/03 19:19:30 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	get_position(t_mlx **g_mlx)
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
				n++;
			j++;
		}
		i++;
	}
	return (n);
}

size_t	ft_arrylen(char **s)
{
	size_t	i;

	i = 0;
	while (s[i] != NULL)
	{
		i++;
	}
	return (i);
}

void	ft_malloc_image(t_mlx **mlx)
{
	(*mlx)->image = NULL;
	(*mlx)->image = malloc(sizeof(t_image));
	if ((*mlx)->image == NULL)
		ft_exit(mlx, "Error in allocation to image\n", 0);
	(*mlx)->image->e = NULL;
	(*mlx)->image->c = NULL;
	(*mlx)->image->p = NULL;
	(*mlx)->image->w = NULL;
	(*mlx)->image->k = NULL;
	(*mlx)->image->m = NULL;
	(*mlx)->image->m_r = NULL;
	(*mlx)->image->e = ft_strdup(mlx, "img_bonus/airplane.xpm");
	(*mlx)->image->c = ft_strdup(mlx, "img_bonus/dolar_maroc.xpm");
	(*mlx)->image->p = ft_strdup(mlx, "img_bonus/player.xpm");
	(*mlx)->image->w = ft_strdup(mlx, "img_bonus/black.XPM");
	(*mlx)->image->k = ft_strdup(mlx, "img_bonus/maroc.xpm");
	(*mlx)->image->m = ft_strdup(mlx, "img_bonus/police.xpm");
	(*mlx)->image->m_r = ft_strdup(mlx, "img_bonus/mir_police.xpm");
}

void	ft_calloc_animation(t_mlx **mlx)
{
	int	i;

	i = 0;
	while (i < (*mlx)->nbr_enemy)
	{
		(*mlx)->t[i] = 0;
		i++;
	}
}

void	ft_malloc(t_mlx **mlx)
{
	(*mlx) = malloc(sizeof(t_mlx));
	if (mlx == NULL)
		ft_exit(mlx, "Error in malloc mlx", 0);
	(*mlx)->map = NULL;
	(*mlx)->map = malloc(sizeof(t_map));
	if ((*mlx)->map == NULL)
		ft_exit(mlx, "Eroor in malloc mlx->map", 0);
	(*mlx)->player = NULL;
	(*mlx)->player = malloc(sizeof(t_player));
	if ((*mlx)->player == NULL)
		ft_exit(mlx, "Errer in allocation in player", 0);
	(*mlx)->map->map_str = NULL;
	(*mlx)->map->map_array = NULL;
	(*mlx)->x = NULL;
	(*mlx)->y = NULL;
	(*mlx)->t = NULL;
	(*mlx)->map->c = 0;
	(*mlx)->map->e = 0;
	(*mlx)->map->p = 0;
	(*mlx)->move = 0;
	(*mlx)->animation = 0;
	ft_malloc_image(mlx);
}

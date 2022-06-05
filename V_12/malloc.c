/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:46:35 by labenall          #+#    #+#             */
/*   Updated: 2022/06/02 11:53:00 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	(*mlx)->image->e = ft_strdup(mlx, "img/airplane.xpm");
	(*mlx)->image->c = ft_strdup(mlx, "img/dolar_maroc.xpm");
	(*mlx)->image->p = ft_strdup(mlx, "img/player.xpm");
	(*mlx)->image->w = ft_strdup(mlx, "img/wall.XPM");
	(*mlx)->image->k = ft_strdup(mlx, "img/maroc.xpm");
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
	(*mlx)->map->c = 0;
	(*mlx)->map->e = 0;
	(*mlx)->map->p = 0;
	(*mlx)->move = 0;
	ft_malloc_image(mlx);
}

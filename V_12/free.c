/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:25:50 by labenall          #+#    #+#             */
/*   Updated: 2022/06/02 14:35:17 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_array(t_mlx **mlx)
{
	int	i;

	i = 0;
	if ((*mlx)->map->map_array != NULL)
	{
		while ((*mlx)->map->map_array[i] != NULL)
		{
			free((*mlx)->map->map_array[i]);
			(*mlx)->map->map_array[i] = NULL;
			i++;
		}
		free((*mlx)->map->map_array[i]);
		(*mlx)->map->map_array[i] = NULL;
		free((*mlx)->map->map_array);
		(*mlx)->map->map_array = NULL;
	}
	if ((*mlx)->map->map_str != NULL)
	{
		free((*mlx)->map->map_str);
		(*mlx)->map->map_str = NULL;
	}
	free((*mlx)->map);
}

void	free_image(t_mlx **mlx)
{
	if ((*mlx)->image != NULL)
	{
		if ((*mlx)->image->c != NULL)
			free((*mlx)->image->c);
		(*mlx)->image->c = NULL;
		if ((*mlx)->image->e != NULL)
			free((*mlx)->image->e);
		(*mlx)->image->e = NULL;
		if ((*mlx)->image->k != NULL)
			free((*mlx)->image->k);
		(*mlx)->image->k = NULL;
		if ((*mlx)->image->p != NULL)
			free((*mlx)->image->p);
		(*mlx)->image->p = NULL;
		if ((*mlx)->image->w != NULL)
			free((*mlx)->image->w);
		(*mlx)->image->w = NULL;
		free((*mlx)->image);
		(*mlx)->image = NULL;
	}
}

void	ft_free(t_mlx **mlx)
{
	if (*mlx != NULL)
	{
		if ((*mlx)->map != NULL)
		{
			free_map_array(mlx);
			if ((*mlx)->player != NULL)
			{
				free((*mlx)->player);
				(*mlx)->player = NULL;
			}
			free_image(mlx);
		}
		free(*mlx);
		*mlx = NULL;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:00:10 by labenall          #+#    #+#             */
/*   Updated: 2022/06/02 19:00:15 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	if ((*mlx)->image->m != NULL)
		free((*mlx)->image->m);
	(*mlx)->image->m = NULL;
	if ((*mlx)->image->m_r != NULL)
		free((*mlx)->image->m_r);
	(*mlx)->image->m_r = NULL;
	free((*mlx)->image);
	(*mlx)->image = NULL;
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
			if ((*mlx)->image != NULL)
				free_image(mlx);
		}
		if ((*mlx)->x != NULL)
			free((*mlx)->x);
		(*mlx)->x = NULL;
		if ((*mlx)->y != NULL)
			free((*mlx)->y);
		(*mlx)->y = NULL;
		if ((*mlx)->t != NULL)
			free((*mlx)->t);
		(*mlx)->t = NULL;
		free(*mlx);
		*mlx = NULL;
	}
}

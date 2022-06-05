/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:11:57 by labenall          #+#    #+#             */
/*   Updated: 2022/06/02 00:09:25 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_images(t_mlx **g_mlx, void **img, int i, int j)
{
	int	w;
	int	h;

	if ((*g_mlx)->map->map_array[i][j] == 'E')
				*img = mlx_xpm_file_to_image((*g_mlx)->mlx_ptr, \
				(*g_mlx)->image->e, &w, &h);
	else if ((*g_mlx)->map->map_array[i][j] == 'C')
		*img = mlx_xpm_file_to_image((*g_mlx)->mlx_ptr, \
		(*g_mlx)->image->c, &w, &h);
	else if ((*g_mlx)->map->map_array[i][j] == '1')
		*img = mlx_xpm_file_to_image((*g_mlx)->mlx_ptr, \
		(*g_mlx)->image->w, &w, &h);
	else if ((*g_mlx)->map->map_array[i][j] == 'P')
	{
		*img = mlx_xpm_file_to_image((*g_mlx)->mlx_ptr, \
		(*g_mlx)->image->p, &w, &h);
		(*g_mlx)->player->x = i;
		(*g_mlx)->player->y = j;
	}
	else if ((*g_mlx)->map->map_array[i][j] == '0')
		*img = mlx_xpm_file_to_image((*g_mlx)->mlx_ptr, \
		(*g_mlx)->image->k, &w, &h);
}

int	ft_display(t_mlx **g_mlx)
{
	void	*img;
	int		i;
	int		j;

	i = 0;
	while ((*g_mlx)->map->map_array[i])
	{
		j = 0;
		while ((*g_mlx)->map->map_array[i][j])
		{
			get_images(g_mlx, &img, i, j);
			if (img == NULL)
				ft_exit(g_mlx, "error images not found", 0);
			mlx_put_image_to_window((*g_mlx)->mlx_ptr, \
			(*g_mlx)->window_ptr, img, j * 64, i * 64);
			j++;
		}
		i++;
	}
	return (0);
}

int	close_window(t_mlx **g_mlx)
{
	mlx_destroy_window((*g_mlx)->mlx_ptr, (*g_mlx)->window_ptr);
	ft_exit(g_mlx, "quit game\n", 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	*g_mlx;

	g_mlx = NULL;
	if (ac == 2)
	{
		ft_malloc(&g_mlx);
		cheak_map(&g_mlx, av);
		g_mlx->mlx_ptr = mlx_init();
		if (g_mlx->mlx_ptr == NULL)
			ft_exit(&g_mlx, "error in set_up connection", 0);
		g_mlx->window_ptr = mlx_new_window(g_mlx->mlx_ptr, \
				64 * g_mlx->map->nbr_col, 64 * g_mlx->map->nbr_row, "So_long");
		ft_display(&g_mlx);
		mlx_hook (g_mlx->window_ptr, 02, 0, key_hook, &g_mlx);
		mlx_hook(g_mlx->window_ptr, 17, 0, close_window, &g_mlx);
		mlx_loop(g_mlx->mlx_ptr);
		ft_free(&g_mlx);
	}
	else
		ft_exit(&g_mlx, "Errer :[./so_long] [map.ber]", 0);
	return (0);
}

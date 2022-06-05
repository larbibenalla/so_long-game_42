/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:11 by labenall          #+#    #+#             */
/*   Updated: 2022/06/03 19:20:05 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	else if ((*g_mlx)->map->map_array[i][j] == 'M')
		*img = mlx_xpm_file_to_image((*g_mlx)->mlx_ptr, \
		(*g_mlx)->image->m, &w, &h);
}

int	ft_display(t_mlx **g_mlx)
{
	char	*nbr;

	display_image(g_mlx);
	mlx_string_put((*g_mlx)->mlx_ptr, \
			(*g_mlx)->window_ptr, 0, 32, 16777215, "move :");
	nbr = ft_itoa((*g_mlx)->move);
	mlx_string_put((*g_mlx)->mlx_ptr, \
			(*g_mlx)->window_ptr, 64, 32, 16777215, nbr);
	free(nbr);
	return (0);
}

int	close_window(t_mlx **g_mlx)
{
	mlx_destroy_window((*g_mlx)->mlx_ptr, (*g_mlx)->window_ptr);
	ft_exit(g_mlx, "quit game\n", 0);
	return (0);
}

void	ft_malloc_animation(t_mlx **mlx)
{
	(*mlx)->nbr_enemy = get_position(mlx);
	(*mlx)->x = malloc(sizeof(int) * (*mlx)->nbr_enemy);
	if (!(*mlx)->x)
		ft_exit(mlx, "errrur in malloc", 0);
	(*mlx)->y = malloc(sizeof(int) * (*mlx)->nbr_enemy);
	if (!(*mlx)->y)
		ft_exit(mlx, "errrur in malloc", 0);
	(*mlx)->t = malloc(sizeof(int) * (*mlx)->nbr_enemy);
	if (!(*mlx)->t)
		ft_exit(mlx, "errrur in malloc", 0);
	ft_calloc_animation(mlx);
}

int	main(int ac, char **av)
{
	t_mlx	*g_mlx;

	g_mlx = NULL;
	if (ac == 2)
	{
		ft_malloc(&g_mlx);
		cheak_map(&g_mlx, av);
		ft_malloc_animation(&g_mlx);
		g_mlx->mlx_ptr = mlx_init();
		if (g_mlx->mlx_ptr == NULL)
			ft_exit(&g_mlx, "error in set_up connection", 0);
		g_mlx->window_ptr = mlx_new_window(g_mlx->mlx_ptr, \
				64 * g_mlx->map->nbr_col, 64 * g_mlx->map->nbr_row, "So_long");
		ft_display(&g_mlx);
		mlx_hook (g_mlx->window_ptr, 02, 0, key_hook, &g_mlx);
		mlx_hook(g_mlx->window_ptr, 17, 0, close_window, &g_mlx);
		mlx_loop_hook(g_mlx->mlx_ptr, animation, &g_mlx);
		mlx_loop(g_mlx->mlx_ptr);
		ft_free(&g_mlx);
	}
	else
		ft_exit(&g_mlx, "Errer :[./so_long] [map.ber]", 0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_a_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:00:44 by labenall          #+#    #+#             */
/*   Updated: 2022/06/02 19:00:47 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	handler_a_0(t_mlx **g_mlx)
{
	void	*img_p;
	void	*img_0;

	(*g_mlx)->map->map_array[(*g_mlx)->player->x] \
		[(*g_mlx)->player->y - 1] = 'P';
	(*g_mlx)->map->map_array[(*g_mlx)->player->x] \
		[(*g_mlx)->player->y] = '0';
	(*g_mlx)->move++;
	write(1, "move :", 6);
	ft_putnbr((*g_mlx)->move);
	write(1, "\n", 1);
	write_move(g_mlx);
	img_p = mlx_xpm_file_to_image((*g_mlx)->mlx_ptr, \
			(*g_mlx)->image->p, &(*g_mlx)->width, &(*g_mlx)->height);
	mlx_put_image_to_window((*g_mlx)->mlx_ptr, (*g_mlx)->window_ptr, img_p, \
			((*g_mlx)->player->y - 1) * 64, (*g_mlx)->player->x * 64);
	img_0 = mlx_xpm_file_to_image((*g_mlx)->mlx_ptr, \
			(*g_mlx)->image->k, &(*g_mlx)->width, &(*g_mlx)->height);
	mlx_put_image_to_window((*g_mlx)->mlx_ptr, (*g_mlx)->window_ptr, img_0, \
			((*g_mlx)->player->y) * 64, (*g_mlx)->player->x * 64);
	(*g_mlx)->player->y--;
}

void	handler_a_c(t_mlx **g_mlx)
{
	void	*img_p;
	void	*img_0;

	(*g_mlx)->map->map_array[(*g_mlx)->player->x] \
		[(*g_mlx)->player->y - 1] = 'P';
	(*g_mlx)->map->map_array[(*g_mlx)->player->x] \
		[(*g_mlx)->player->y] = '0';
	(*g_mlx)->map->c--;
	(*g_mlx)->move++;
	write(1, "move :", 6);
	ft_putnbr((*g_mlx)->move);
	write(1, "\n", 1);
	img_p = mlx_xpm_file_to_image((*g_mlx)->mlx_ptr, \
			(*g_mlx)->image->p, &(*g_mlx)->width, &(*g_mlx)->height);
	mlx_put_image_to_window((*g_mlx)->mlx_ptr, (*g_mlx)->window_ptr, img_p, \
			((*g_mlx)->player->y - 1) * 64, (*g_mlx)->player->x * 64);
	img_0 = mlx_xpm_file_to_image((*g_mlx)->mlx_ptr, \
			(*g_mlx)->image->k, &(*g_mlx)->width, &(*g_mlx)->height);
	mlx_put_image_to_window((*g_mlx)->mlx_ptr, (*g_mlx)->window_ptr, img_0, \
			((*g_mlx)->player->y) * 64, (*g_mlx)->player->x * 64);
	(*g_mlx)->player->y--;
	write_move(g_mlx);
}

void	handler_a_e(t_mlx **g_mlx)
{
	void	*img_p;
	void	*img_0;

	if ((*g_mlx)->map->c == 0)
	{
		(*g_mlx)->map->map_array[(*g_mlx)->player->x] \
			[(*g_mlx)->player->y - 1] = 'P';
		(*g_mlx)->map->map_array[(*g_mlx)->player->x] \
			[(*g_mlx)->player->y] = '0';
		write(1, "move :", 6);
		ft_putnbr(++(*g_mlx)->move);
		write(1, "\n", 1);
		img_p = mlx_xpm_file_to_image((*g_mlx)->mlx_ptr, \
				(*g_mlx)->image->p, &(*g_mlx)->width, &(*g_mlx)->height);
		mlx_put_image_to_window((*g_mlx)->mlx_ptr, (*g_mlx)->window_ptr, img_p, \
				((*g_mlx)->player->y - 1) * 64, (*g_mlx)->player->x * 64);
		img_0 = mlx_xpm_file_to_image((*g_mlx)->mlx_ptr, \
				(*g_mlx)->image->k, &(*g_mlx)->width, &(*g_mlx)->height);
		mlx_put_image_to_window((*g_mlx)->mlx_ptr, (*g_mlx)->window_ptr, \
				img_0, ((*g_mlx)->player->y) * 64, (*g_mlx)->player->x * 64);
		(*g_mlx)->player->y--;
		ft_exit(g_mlx, "Bravo\n", 0);
		write_move(g_mlx);
	}
}

void	handler_a_m(t_mlx **g_mlx)
{
	void	*img_p;
	void	*img_0;

	(*g_mlx)->map->map_array[(*g_mlx)->player->x] \
		[(*g_mlx)->player->y - 1] = 'P';
	(*g_mlx)->map->map_array[(*g_mlx)->player->x] \
		[(*g_mlx)->player->y] = '0';
	write(1, "move :", 6);
	ft_putnbr(++(*g_mlx)->move);
	write(1, "\n", 1);
	img_p = mlx_xpm_file_to_image((*g_mlx)->mlx_ptr, \
			(*g_mlx)->image->p, &(*g_mlx)->width, &(*g_mlx)->height);
	mlx_put_image_to_window((*g_mlx)->mlx_ptr, (*g_mlx)->window_ptr, img_p, \
			((*g_mlx)->player->y - 1) * 64, (*g_mlx)->player->x * 64);
	img_0 = mlx_xpm_file_to_image((*g_mlx)->mlx_ptr, \
			(*g_mlx)->image->k, &(*g_mlx)->width, &(*g_mlx)->height);
	mlx_put_image_to_window((*g_mlx)->mlx_ptr, (*g_mlx)->window_ptr, \
			img_0, ((*g_mlx)->player->y) * 64, (*g_mlx)->player->x * 64);
	(*g_mlx)->player->y--;
	ft_exit(g_mlx, "khasarti\n", 0);
	write_move(g_mlx);
}

void	handler_a(t_mlx **g_mlx)
{
	if ((*g_mlx)->map->map_array[(*g_mlx)->player->x] \
			[(*g_mlx)->player->y - 1] == '0')
		handler_a_0(g_mlx);
	else if ((*g_mlx)->map->map_array[(*g_mlx)->player->x] \
			[(*g_mlx)->player->y - 1] == 'C')
		handler_a_c(g_mlx);
	else if ((*g_mlx)->map->map_array[(*g_mlx)->player->x] \
			[(*g_mlx)->player->y - 1] == 'E')
		handler_a_e(g_mlx);
	else if ((*g_mlx)->map->map_array[(*g_mlx)->player->x] \
			[(*g_mlx)->player->y - 1] == 'M')
		handler_a_m(g_mlx);
}

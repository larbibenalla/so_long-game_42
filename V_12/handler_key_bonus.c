/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_key_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:01:34 by labenall          #+#    #+#             */
/*   Updated: 2022/06/03 18:43:44 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_image(t_mlx	**g_mlx)
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
			img = NULL;
			get_images(g_mlx, &img, i, j);
			if (img == NULL)
				ft_exit(g_mlx, "error images not found", 0);
			mlx_put_image_to_window((*g_mlx)->mlx_ptr, \
			(*g_mlx)->window_ptr, img, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	write_move(t_mlx **g_mlx)
{
	void	*img;
	char	*nbr;
	int		w;
	int		h;

	img = mlx_xpm_file_to_image((*g_mlx)->mlx_ptr, \
				(*g_mlx)->image->w, &w, &h);
	mlx_put_image_to_window((*g_mlx)->mlx_ptr, \
			(*g_mlx)->window_ptr, img, 1 * 64, 0 * 64);
	nbr = ft_itoa((*g_mlx)->move);
	mlx_string_put((*g_mlx)->mlx_ptr, (*g_mlx)->window_ptr, \
			64, 32, 16777215, nbr);
	free(nbr);
}

void	ft_putnbr(int n)
{
	unsigned int	un;
	char			c;

	if (n < 0)
	{
		write(1, "-", 1);
		un = n * (-1);
	}
	else
		un = n;
	if (un >= 10)
		ft_putnbr(un / 10);
	c = un % 10 + '0';
	write(1, &c, 1);
}

int	key_hook(int keycode, t_mlx **g_mlx)
{
	if (keycode == 0)
		handler_a(g_mlx);
	else if (keycode == 13)
		handler_w(g_mlx);
	else if (keycode == 2)
		handler_d(g_mlx);
	else if (keycode == 1)
		handler_s(g_mlx);
	else if (keycode == 53)
		ft_exit(g_mlx, "you quit game\n", 0);
	return (0);
}

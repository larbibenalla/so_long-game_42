/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:25:29 by labenall          #+#    #+#             */
/*   Updated: 2022/06/02 19:03:13 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

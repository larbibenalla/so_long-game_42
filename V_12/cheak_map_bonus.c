/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheak_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:59:45 by labenall          #+#    #+#             */
/*   Updated: 2022/06/02 18:59:50 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_read(t_mlx **g_mlx, int fd)
{
	int		rd;
	char	*map;
	char	*buff;

	buff = malloc(2);
	if (buff == NULL)
		ft_exit(g_mlx, "Error in malloc buff", 0);
	rd = read(fd, buff, BUFFER_SIZE);
	buff[rd] = 0;
	map = ft_strjoin((*g_mlx)->map->map_str, buff);
	free((*g_mlx)->map->map_str);
	free(buff);
	(*g_mlx)->map->map_str = map;
	return (rd);
}

void	read_map(t_mlx **g_mlx, char **av)
{
	int	fd;
	int	rd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_exit(g_mlx, "file can't open", 0);
	(*g_mlx)->map->map_str = ft_strdup(g_mlx, "");
	while (1)
	{
		rd = ft_read(g_mlx, fd);
		if (rd <= 0)
			break ;
	}
	close(fd);
}

int	str_finish_with_ber(char *str)
{
	int	len;
	int	r;

	r = 0;
	len = ft_strlen(str);
	if (str[len - 1] == 'r')
		if (str[len - 2] == 'e')
			if (str[len - 3] == 'b')
				if (str[len - 4] == '.')
					r = 1;
	return (r);
}

void	cheak_map(t_mlx **g_mlx, char **av)
{
	if (str_finish_with_ber(av[1]) == 0)
		ft_exit(g_mlx, "type de file is not type .ber", 0);
	read_map(g_mlx, av);
	verified_map(g_mlx);
}

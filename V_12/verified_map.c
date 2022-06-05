/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verified_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:22:14 by labenall          #+#    #+#             */
/*   Updated: 2022/06/02 15:24:51 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cheak_returaline(t_mlx **g_mlx)
{
	int	i;

	i = 0;
	while ((*g_mlx)->map->map_str[i])
	{
		if ((*g_mlx)->map->map_str[0] == '\n')
			ft_exit(g_mlx, "Ereur : empty line in map\n", 0);
		if ((*g_mlx)->map->map_str[i] == '\n' \
				&& (*g_mlx)->map->map_str[i + 1] == '\n')
			ft_exit(g_mlx, "Ereur : empty line in map\n", 0);
		i++;
	}
}

int	is_not_map_char(char c)
{
	if (c != 'E' && c != 'P' && c != 'C' && c != '1' && c != '0')
		return (0);
	else
		return (1);
}

void	verified_line(t_mlx **g_mlx, int i)
{
	size_t	j;

	if (ft_strlen((*g_mlx)->map->map_array[i]) != (*g_mlx)->map->nbr_col)
		ft_exit(g_mlx, "Numbre of colons not equal", 0);
	j = 0;
	while ((*g_mlx)->map->map_array[i][j])
	{
		if ((i == 0 || j == 0) && (*g_mlx)->map->map_array[i][j] != '1')
			ft_exit(g_mlx, "Error : Wall non complete", 0);
		if ((*g_mlx)->map->map_array[i + 1] == NULL \
				&& (*g_mlx)->map->map_array[i][j] != '1')
			ft_exit(g_mlx, "Error in Map: Wall non complete in Bas", 0);
		if (j == ((*g_mlx)->map->nbr_col - 1) \
				&& (*g_mlx)->map->map_array[i][j] != '1')
			ft_exit(g_mlx, "Error in Map: Wall non complete in Droite", 0);
		if (is_not_map_char((*g_mlx)->map->map_array[i][j]) == 0)
			ft_exit(g_mlx, "this map contains incorecte charactere", 0);
		if ((*g_mlx)->map->map_array[i][j] == 'E')
			(*g_mlx)->map->e++;
		if ((*g_mlx)->map->map_array[i][j] == 'P')
			(*g_mlx)->map->p++;
		if ((*g_mlx)->map->map_array[i][j] == 'C')
			(*g_mlx)->map->c++;
		j++;
	}
}

void	verified_map(t_mlx **g_mlx)
{
	size_t	i;

	i = 0;
	if ((*g_mlx)->map->map_str[0] == 0)
		ft_exit(g_mlx, "Erreur: map is empty ", 0);
	if ((*g_mlx)->map->map_str[ft_strlen((*g_mlx)->map->map_str) - 1] == '\n')
		ft_exit(g_mlx, "Erreur: empty line in end of map ", 0);
	cheak_returaline(g_mlx);
	(*g_mlx)->map->map_array = split_map((*g_mlx)->map->map_str, '\n');
	if ((*g_mlx)->map->map_array == NULL)
		ft_exit(g_mlx, "Error in allocation split", 0);
	(*g_mlx)->map->nbr_col = ft_strlen((*g_mlx)->map->map_array[0]);
	(*g_mlx)->map->nbr_row = ft_arrylen((*g_mlx)->map->map_array);
	if ((*g_mlx)->map->nbr_col < 2 || (*g_mlx)->map->nbr_row < 2)
		ft_exit(g_mlx, "maps has contains at least 3 clone and 3 row", 0);
	while ((*g_mlx)->map->map_array[i] != NULL)
	{
		verified_line(g_mlx, i);
		i++;
	}
	if ((*g_mlx)->map->e < 1 || (*g_mlx)->map->p != 1 || (*g_mlx)->map->c < 1)
		ft_exit(g_mlx, "incorect map ", 0);
}

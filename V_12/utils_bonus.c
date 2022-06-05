/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:38:59 by labenall          #+#    #+#             */
/*   Updated: 2022/06/02 19:09:01 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0')
	{
		n++;
	}
	return (n);
}

void	ft_putstr(char *s)
{
	int	len;

	len = ft_strlen(s);
	write(1, s, len);
}

void	ft_exit(t_mlx **g_mlx, char *s, int type)
{
	ft_free(g_mlx);
	ft_putstr(s);
	exit(type);
}

char	*ft_strdup(t_mlx **g_mlx, char *s)
{
	char	*r;
	size_t	len;
	size_t	n;

	len = ft_strlen(s) + 1;
	r = (char *)malloc(len);
	if (r == NULL)
		ft_exit(g_mlx, "error in alocation to name image", 0);
	n = -1;
	while (++n < len)
		r[n] = s[n];
	return (r);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*r;
	size_t	size;
	int		i;
	int		j;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	r = (char *)malloc(sizeof(char) * (size));
	if (r == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		r[i] = s1[i];
	j = -1;
	while (s2[++j])
		r[i + j] = s2[j];
	r[i + j] = 0;
	return (r);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:42 by labenall          #+#    #+#             */
/*   Updated: 2022/06/02 19:06:59 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define BUFFER_SIZE 1
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>

typedef struct s_image
{
	char	*e;
	char	*c;
	char	*p;
	char	*w;
	char	*k;
	char	*m;
	char	*m_r;

}				t_image;

typedef struct s_player
{
	int	x;
	int	y;
	int	coins;
}				t_player;

typedef struct s_map
{
	char	*map_str;
	char	**map_array;
	int		e;
	int		p;
	int		c;
	size_t	nbr_col;
	size_t	nbr_row;
}				t_map;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*window_ptr;
	int			*x;
	int			*y;
	int			*t;
	int			nbr_enemy;
	int			move;
	int			animation;
	int			width;
	int			height;
	t_player	*player;
	t_map		*map;
	t_image		*image;
}				t_mlx;

void	ft_putnbr(int n);
void	ft_putstr(char *s);
void	ft_exit(t_mlx **mlx, char *s, int type_exit);
void	ft_free(t_mlx **mlx);
void	ft_malloc(t_mlx **mlx);
void	cheak_map(t_mlx **g_mlx, char **av);
void	verified_map(t_mlx **g_mlx);
void	handler_a(t_mlx **g_mlx);
void	handler_w(t_mlx **g_mlx);
void	handler_s(t_mlx **g_mlx);
void	handler_d(t_mlx **g_mlx);
void	write_move(t_mlx **g_mlx);
void	ft_calloc_animation(t_mlx **mlx);
void	get_images(t_mlx **g_mlx, void **img, int i, int j);
void	display_image(t_mlx	**g_mlx);
void	help_animation_1(t_mlx **g_mlx, int k);
void	help_animation_2(t_mlx **g_mlx, int k);
void	handler_enemy(t_mlx **g_mlx, int k);
void	handler_enemy_miroir(t_mlx **g_mlx, int k);
int		key_hook(int keycode, t_mlx **g_mlx);
int		animation(t_mlx **g_mlx);
int		get_position(t_mlx **g_mlx);
char	*ft_strdup(t_mlx **g_mlx, char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**split_map(const char *s, char c);
char	*ft_itoa(int n);
size_t	ft_arrylen(char **s);
size_t	ft_strlen(char *s);
#endif

#ifndef CUB3D_H
# define CUB3D_H

# include "../includes/GETNEXTLINE/get_next_line.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>

# define WINDOW_WIDTH	1024
# define WINDOW_HEIGHT	768

/************KEYBINDS***********/
# define ARROW_R	65363
# define ARROW_L	65361
# define KEY_W		119
# define KEY_S		115
# define KEY_A		97
# define KEY_D		100
# define KEY_ESC	65307

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		win_w;
	int		win_h;
	char	**map;
	t_ray	ray;
	t_img	image;

}		t_data;

typedef struct	s_img
{
	void	*img;
	void	*addr;
	int		bits_p_pxl;
	int		line_length;
	int		endian;
}		t_img;


typedef struct s_ray
{
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	posX;
	double	posY;
	double	move_speed;
	double	rotate_speed;
}		t_ray;

typedef struct s_map_data
{
	int		c;
	int		p;
	int		e;
	int		y;
	int		x;
}		t_map_data;

void	mv_fw(t_data *data);
void	mv_bw(t_data *data);
void	strafe_left(t_data *data);
void	strafe_right(t_data *data);
void	rotate_left(t_data *data);
void	rotate_right(t_data *data);
void	check_surr_walls(t_data **data);
void	free_resources(t_data *data);
void 	free_images(t_data *data);
int		close_win(t_data *data);

void	put_image(t_data ***data, int x, int y, char *img);
void	check_map(t_data *data);
void	clean_map(t_data ***data);

# endif

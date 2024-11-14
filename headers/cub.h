#ifndef CUB3D_H
# define CUB3D_H

# include "../includes/GETNEXTLINE/get_next_line.h"
# include "../includes/libft/libft.h"
# include "../mlx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 768

/************KEYBINDS***********/
# define ARROW_R 65363
# define ARROW_L 65361
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_ESC 65307
# define PATH_MAX 200
# define MAP_WIDTH 12
# define MAP_HEIGHT 5

typedef struct s_texture
{
	void		*img;
	char		*addr;
	char		*path;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_texture;

typedef struct s_img
{
	void		*img;
	void		*addr;
	int			bits_p_pxl;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_ray
{
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		pos_x;
	double		pos_y;
	double		move_speed;
	double		rotate_speed;
}				t_ray;

typedef struct s_dda
{
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			side;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
}				t_dda;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_w;
	int			win_h;
	char		**map;
	int			floor_color;
	int			ceiling_color;
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
	t_ray		ray;
	t_img		image;
}				t_data;

void	init_data(t_data *data);
void	mv_fw(t_data *data);
void	mv_bw(t_data *data);
void	strafe_left(t_data *data);
void	strafe_right(t_data *data);
void	rotate_left(t_data *data);
void	parse_textures(t_data *data, char **lines);
void	rotate_right(t_data *data);
void	check_map(t_data *data);
void	check_surr_walls(t_data **data);
int		render(t_data *data);
void	free_resources(t_data *data);
void	free_img(t_data *data);
void	free_map(t_data *data);
void	free_win(t_data *data);
void	free_textures(t_data *data);
void	free_mlx(t_data *data);
int		close_win(t_data *data);
int		load_texture(t_data *data, t_texture *texture, char *path);
void	parse_config(t_data *data, char *file);
void	cast_rays(t_data *data);
void	draw_floor_ceiling(t_data *data);
void	validate_player_position(t_data *data);
void	validate_map_elements(t_data *data);
char	**parse_map(char *map);
void	free_split(char **split);
void	init_dda(double ray_dir_x, double rary_dir_y, t_data *data,
			t_dda *dda);
void	calculate_step(t_dda *dda, double ray_dir_x, double rary_dir_y,
					t_data *data);
void	calculate_ray(t_data *data, int x, double *ray_dir_x,
			double *rary_dir_y);
void	perform_dda(t_data *data, t_dda *dda);
void	draw_wall(t_data *data, t_dda *dda, int x,
			double perp_wall_dist);
int		map_height(char **map);
void	clean_map(t_data ***data);
void	check_file(char *file);    // verify .cub extension
void	exit_error(char *message); // error handling

#endif

#ifndef RTV1_H
# define RTV1_H
# include "../srcs/libft/libft.h"
# include "macro_key_mlx.h"
# include "../srcs/minilibx_macos/mlx.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <math.h>
// A DELETE
#include <stdio.h>

# include <errno.h>
# include <pthread.h>
# include "vector.h"
#include "parser.h"
# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# define WIN_WIDTH_HALF 500
# define WIN_HEIGHT_HALF 500
# define WIN_WIDTH_QUART 250
# define WIN_HEIGHT_QUART 250
# define WIN_WIDTH_OCT 125
# define WIN_HEIGHT_OCT 125
# define B 0x00FFFFFF
# define NBR_OBJECT 6 // cette macro decrit le nomre d'objet du RT incluant light et camera
# define NBR_DESCRIPTION 12
# define ZERO 0.000000001
# define LIGHT_PTR ((t_light*)(tmp_light->content))

typedef struct	s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}				t_color;

typedef struct		s_ray
{
	t_vector		org;
	t_vector		dir;
	double			t;
}					t_ray;

typedef struct		s_light
{
	t_vector	org;
	double		intensity;
	double		specular;
	double		diffuse;
	int			(*hit_light)(struct s_light light, t_ray *ray, double *t);
}					t_light;

typedef struct	s_matrix_rot
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	e;
	double	f;
	double	ad;
	double	bd;
}				t_matrix_rot;

enum {

	SPHERE,
	PLAN,
	CONE,
	CYLINDRE,
	CAMERA,
	LIGHT
};

typedef struct	s_obj
{
	t_vector	pos;
	double		r;
	int			mat;
	double		albedo;
	t_vector	n;
	t_color		color;
	int			(*func_obj)(struct s_obj tmp, t_ray *ray, double *t);
	int			etat;
	t_vector	axis;
	t_vector	apex;
	t_vector	rotation;
	double		angle;
	double		height;
	int			brillance;
	double		size;
	double		specular;
	double		diffuse;
}				t_obj;

typedef struct	s_z
{
	double	re;
	double	im;
}				t_z;

typedef struct	s_limit
{
	int			x;
	int			y;
	int			max_x;
	int			max_y;
	int			tmp_x;
}				t_limit;

typedef struct	s_camera
{
	int				num;
	t_vector		pos;
	t_vector		to;
	double			*matrix;
	struct s_camera *next;
}				t_camera;

typedef struct s_select
{
	t_obj	*o;
	t_camera *c;
}				t_select;

typedef struct	s_surface
{
	t_vector	intersection;
	t_vector	n;
	double		spec;
	double		diffuse;
}				t_surface;

typedef	struct	s_env
{
	void		*mlx;
	void		*win;
	t_vector	cursor;
	int			fd;
	int			thread_index;
	double		imageAspectRatio;
	double		scale;
	int			command;
	int			lock;
	int			bpp;
	int			sizeline;
	int			endian;
	int			width;
	int			height;
	double		zoom;
	void		*img;
	char		*data;
	t_list		*light;
	double		k;
	t_ray		*tab_ray;
// pour les objets
	char		**tab_str_object;
	int			(*set_object[NBR_OBJECT])(struct s_env *env);
// pour les objets

// pour les descriptions
	char		**tab_str_description;
	int			(*check_description[NBR_DESCRIPTION])(struct s_env *env, char *str, t_obj *new, t_pars_object *index);
// pour les descriptions
	t_list		*list;
	t_list		*trash;
	// camera
	t_list		*camera;
	int			nbr_cam;
	double		fov;
	double		image_aspect_ratio;
	t_select		*select;
	int			nb_t;
	// camera
}				t_env;

// parsing
int     set_color(t_env *env, char *tmp, t_obj *new, t_pars_object *index);
int     set_axis(t_env *env, char *tmp, t_obj *new, t_pars_object *index);
int     set_apex(t_env *env, char *tmp, t_obj *new, t_pars_object *index);
int     set_position(t_env *env, char *tmp, t_obj *new, t_pars_object *index);
int     set_angle(t_env *env, char *tmp, t_obj *new, t_pars_object *index);
int     set_brillance(t_env *env, char *tmp, t_obj *new, t_pars_object *index);
int     set_rayon(t_env *env, char *tmp, t_obj *new, t_pars_object *index);
int     set_normal(t_env *env, char *tmp, t_obj *new, t_pars_object *index);
int     set_rotation(t_env *env, char *tmp, t_obj *new, t_pars_object *index);
int     set_size(t_env *env, char *tmp, t_obj *new, t_pars_object *index);
int     set_diffuse(t_env *env, char *tmp, t_obj *new, t_pars_object *index);
int     set_specular(t_env *env, char *tmp, t_obj *new, t_pars_object *index);

int		set_camera(t_env *env);
int		set_light(t_env *env);
int		set_cone(t_env *env);
int		set_cylinder(t_env *env);
int		set_sphere(t_env *env);
int		set_plan(t_env *env);
int		parser(t_env *env);

void    init_tab_str_description(t_env *env);
void    init_tab_function_description(t_env *env);
void    init_tab_str_object(t_env *env);
void    init_tab_function_object(t_env *env);

//parsing
void			free_data(void *content, size_t size);
void			free_tab(char ***tab, size_t size);
t_vector		get_surface_normal(t_vector intersection, t_obj *tmp, t_ray ray);
void			rotate_object(t_obj *object, t_vector *vector);
void			init_default_camera(t_env *env);
void			sort_camera(t_env *env);
void			recycle(char **old_ptr, char *new_ptr);
void			init_thread(t_env env);
t_limit			ft_limit_thread(int nb);
void			ft_put_pos_select(t_env *env);
int				sphere(t_obj sphere, t_ray *ray, double *t);
int				hit_light(t_light light, t_ray *ray, double *t);
int				cylindre(t_obj cylindre, t_ray *ray, double *t);
int				plan(t_obj plan, t_ray *ray, double *t);
void			*raytracing(void *env);
int				cone(t_obj cone, t_ray *ray, double *t);
t_color			split_color(unsigned long color);
void			mlx_put_pixel_to_image(t_env *env, int x, int y, t_color color);
int				hit_light(t_light light, t_ray *ray, double *t);
int				error(t_env *env, char *str);
int				key_press(int keycode, t_env *env);
int				ft_mouse(int button, int x, int y, t_env *env);
int				red_cross(void *param);
void			set_camera_data(t_camera *camera);
void			end_program(t_env *env);
double      shadow(t_env *env, t_ray ray, double norme);
int				merror(void);
double	get_specularity(t_vector intersection , t_vector n, t_vector light_dir, t_obj *obj);
double  get_diffuse(t_vector n, t_vector light_dir);
void	get_surface_caracter(t_env *env, t_ray ray, t_obj *tmp, double *t);
#endif

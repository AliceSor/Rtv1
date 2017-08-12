/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 19:52:00 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/22 14:51:34 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# define HEIGHT 800
# define WIDTH 1000
# define RAD 3.14166667/180
# define HUGE 214748364.0
# define EYE rt->screen->eye
# define REYE rt->screen->r_eye
# define A rt->screen->alpha
# define B rt->screen->beta
# define G rt->screen->gamma
# define NV new_vector
# define CC create_color
# define CR obj->color->r * 100
# define CB obj->color->b * 100
# define CG obj->color->g * 100
# define DIRS rt->screen->directions
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

typedef struct		s_abc
{
	double			a;
	double			b;
	double			c;
	double			t0;
	double			t1;
	double			d;
}					t_abc;

typedef struct		s_mlx
{
	void			*win;
	void			*mlx;
	void			*im;
	int				*imdata;
	int				ls;
}					t_mlx;

typedef struct		s_v
{
	double			x;
	double			y;
	double			z;
}					t_v;

typedef struct		s_color
{
	double			r;
	double			b;
	double			g;
}					t_color;

typedef struct		s_flags
{
	int				chosen;
	int				for_light;
	int				is_visible;
}					t_flags;

typedef struct		s_sphere
{
	t_v				*center;
	double			radius;
}					t_sphere;

typedef struct		s_plane
{
	t_v				*c;
	t_v				*n;
	double			dist;
}					t_plane;

typedef struct		s_cylinder
{
	t_v				*c;
	t_v				*n;
	double			r;
}					t_cylinder;

typedef struct		s_cone
{
	t_v				*c;
	t_v				*n;
	double			sin_a;
	double			cos_a;
	double			sin_a2;
	double			cos_a2;
	t_v				*sub_1;
	t_v				*sub_2;
}					t_cone;

typedef struct		s_light
{
	t_v				*c;
}					t_light;

typedef struct		s_obj
{
	int				type_obj;
	t_sphere		*s;
	t_plane			*p;
	t_cylinder		*cl;
	t_cone			*cn;
	t_light			*l;
	struct s_obj	*next;
	t_flags			*f;
	t_color			*color;
}					t_obj;

typedef struct		s_screen
{
	t_v				*eye;
	t_v				*r_eye;
	t_v				*center;
	t_v				*points;
	t_v				*r_points;
	t_v				*directions;
	double			alpha;
	double			beta;
	double			gamma;
}					t_screen;

typedef struct		s_rt
{
	t_mlx			*mlx;
	t_screen		*screen;
	t_obj			*obj;
	t_obj			*lights;
	t_obj			*chosen;
	double			speed;
	int				costul;
	double			speed_move;
	double			speed_rotate;
	t_obj			*l_sphere;
	int				is_light;
	t_v				*hit_point;
	t_v				*light_ray;
	t_v				*temp_sub;
	t_obj			**objects;
}					t_rt;

t_mlx				*create_win(void);
void				create_image(t_mlx *mlx);
void				fill_objects(t_rt *rt);
void				put_pixel(int i, int color, t_mlx *mlx);
void				add(t_v *v1, t_v *v2, t_v *res);
void				sub(t_v *v1, t_v *v2, t_v *res);
double				module(t_v *v);
void				normal(t_v *v1, t_v *res);
void				mult(t_v *v1, double n, t_v *res);
void				division(t_v *v1, double d, t_v *res);
void				v_copy(t_v *dest, t_v *src);
t_v					*new_vector(double x, double y, double z);
double				scalar_mult(t_v *v1, t_v *v2);
int					discriminant(double *t, t_abc abc);
int					destroy(void);
void				put_image(t_rt *rt);
int					buttons(int keycode, t_rt *rt);
void				move_plane(int keycode, t_rt *rt);
void				move_sphere(int keycode, t_rt *rt);
void				move_cylinder(int keycode, t_rt *rt);
void				move_cone(int keycode, t_rt *rt);
t_color				*create_color(double r, double g, double b);
int					integrate_color(double r, double g, double b);
t_obj				*create_obj(int type_obj);
void				add_obj(t_obj *first, t_obj *new);
t_plane				*create_plane(t_v *n, double dist);
t_cylinder			*create_cylinder(t_v *c, t_v *n);
t_cone				*create_cone(t_v *c, t_v *n, double angle);
t_sphere			*create_sphere(t_v *c, double r);
t_light				*create_light(t_v *c);
int					identify_obj(t_v *d, t_v *p0, t_obj *obj, double *t);
void				find_hit_point(double t, t_v *d, t_v *p0, t_v *res);
void				find_nrml_light_ray(t_v *hit_p, t_v *light_p, t_v *res);
double				find_diffuse(t_obj *obj, t_v *hit_p, t_v *light_ray);
int					intersect_cone(t_v *d, t_v *p0, t_cone *cn, double *t);
int					intersect_cylinder(t_v *d, t_v *p0,
										t_cylinder *s, double *t);
int					intersect_plane(t_v *d, t_v *p0, t_plane *p, double *t);
int					intersect_sphere(t_v *d, t_v *p0, t_sphere *s, double *t);
int					calc_color(t_obj *obj, double diffuse, int is_shadow,
								double specular);
t_obj				*intersect(t_rt *rt, t_v *d, double *t);
t_screen			*init_pos_screen(t_rt *rt);
void				fill_directions(t_v *p, t_v *directions,
									t_screen *screen, t_rt *rt);
void				ray_trace(t_rt *rt);
void				for_each_point(t_rt *rt, void(*f)(t_v *, t_rt *));
void				move_z_point(t_v *p, t_rt *rt);
void				move_y_point(t_v *p, t_rt *rt);
void				move_x_point(t_v *p, t_rt *rt);
void				move_z_point_b(t_v *p, t_rt *rt);
void				move_y_point_b(t_v *p, t_rt *rt);
void				move_x_point_b(t_v *p, t_rt *rt);
void				rotate_z_point(t_v *p, t_rt *rt, t_v *res);
void				find_normal(t_obj *obj, t_v *hit_p, t_v *res);
double				find_specular(t_obj *obj, t_v *hit_p, t_v *dir_ray,
									t_v *light_ray);
void				fill_r_points(t_v *r_p, t_v *p, t_rt *rt);
void				move_x(int keycode, t_rt *rt);
void				move_y(int keycode, t_rt *rt);
void				move_z(int keycode, t_rt *rt);
void				absolute_rotate(t_v *p, t_rt *rt, t_v *res);
void				change_size(int kc, t_rt *rt);
void				calc_cylinder(t_abc *abc, t_v *d, t_v *p0,
								t_cylinder *s);
void				calc_cone(t_abc *abc, t_v *d, t_v *p0, t_cone *cn);
void				change_speed(int keycode, t_rt *rt);
void				simple_move(int keycode, t_rt *rt);

#endif

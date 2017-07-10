
#ifndef RTV1_H
# define RTV1_H
# define HEIGHT 800
# define WIDTH 1000
# define RAD 3.14166667/180
# define HUGE 214748364.0

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

/////
#include <stdio.h>
/////

typedef struct		s_abc
{
	double			a;
	double	  		b;
	double			c;
	double			t0;
	double			t1;
	double			d;
}					t_abc;

//typedef	union		u_c
//{
//	int				color;
//	char			c[4];
//}					t_c;

typedef struct		s_mlx
{
	void				*win;
	void				*mlx;
	void				*im;
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
//	double			a;
}					t_color;

typedef struct 		s_flags
{
	int 				change_pos;
	int 				l_change_pos;
	int 				chosen;
	int 				for_light;
}					t_flags;

/* type_obj = 0 */

typedef struct		s_sphere
{
	t_v				*center;
	double			radius;
	int				color;
}					t_sphere;

/* type_obj = 1 */

typedef struct 		s_plane
{
	t_v				*c;
	t_v				*n;
	int 				color;
	double			dist;
}					t_plane;

/* type_obj = 2 */

typedef struct		s_cylinder
{
	t_v				*c;
	t_v				*n;
	double			r;
	int				color;
}					t_cylinder;

/* type_obj = 3 */

typedef struct 		s_cone
{
	t_v				*c;
	t_v				*n;
	double 			sin_a;
	double 			cos_a;
	double 			sin_a2;
	double 			cos_a2;
	int 				color;
}					t_cone;

/* type_obj = 4 */

typedef struct 		s_light
{
	t_v				*c;
	double 			brightness;
}					t_light;

typedef struct		s_obj
{
	int				type_obj;
	t_sphere			*s;
	t_plane			*p;
	t_cylinder		*cl;
	t_cone			*cn;
	t_light			*l;
	t_v				**intersects;
	double 			*is_intersects;
	t_v				**l_intersct;
	double 			*l_is_intersct;
	struct s_obj		*next;
	t_flags			*f;
	t_color			*color;
}					t_obj;

typedef struct		s_srceen
{
	t_v				*eye;
	t_v				*center;
	t_v				*points;
	t_v	   			*directions;
}					t_screen;

typedef struct		s_rt
{
	t_mlx			*mlx;
	t_screen			*screen;
	t_obj			*obj;
	t_obj			*lights;
	t_obj			*chosen;
	double 			speed;
	double 			dist;
}					t_rt;

//typedef struct		s_thrd
//{
//	int				y_min;
//	int				y_max;
//}					t_thrd;

t_mlx				*create_win(void);
void					create_image(t_mlx *mlx);
t_screen				*init_pos_screen(void);
void 				fill_objects(t_rt *rt);
void					put_pixel(int i, int color, t_mlx *mlx);
//v_oper
void					add(t_v *v1, t_v *v2, t_v *res);
void					sub(t_v *v1, t_v *v2, t_v *res);
double				module(t_v *v);
void					normal(t_v *v1, t_v *res);
void					mult(t_v *v1, double n, t_v *res);
void					division(t_v *v1, double d, t_v *res);
void					v_copy(t_v *dest, t_v *src);
t_v					*new_vector(double x, double y, double z);
double				scalar_mult(t_v *v1, t_v *v2);
//double				compare(t_v *v1, t_v *v2);


void					emit_rays(t_rt *rt);

t_v					*intersect_ray_sphere(t_v *d, t_v *p0, t_sphere *s, double *t);
t_v					*intersect_ray_plane(t_v *d,t_v *p0, t_plane *plane, double *t);
t_v					*intersect_ray_cylinder(t_v *d, t_v *p0, t_cylinder *s, double *t);
t_v       	      	*intersect_cone(t_v *d, t_v *p0, t_cone *cn, double *t);
int					discriminant(double *t, t_abc abc);

int					intersect(t_rt *rt, t_v *d, int i);
t_obj				*find_intersect(t_rt *rt, t_v *d, t_v *p0, int i);
t_obj				*find_light_intersect(t_rt *rt, t_v *d, t_v *p0, int i);
//buttons
int					destroy(void);
void 				change_pos(t_obj *obj);
void					put_image(t_rt *rt);
int					buttons(int keycode, t_rt *rt);
void 				move_plane(int keycode, t_rt *rt);
void 				move_sphere(int keycode, t_rt *rt);
void 				move_cylinder(int keycode, t_rt *rt);
void 				move_cone(int keycode, t_rt *rt);

t_color				*create_color(double r, double g, double b);
int 					pull_color(t_obj *o0, t_obj *o1, t_light *l, int i);
int 					integrate_color(double r, double g, double b);

t_obj				*create_obj(int type_obj);
void					add_obj(t_obj *first, t_obj *new);
void 				for_each_obj(t_rt *rt, void(*f)(t_obj *));
t_plane				*create_plane(t_v *c, t_v *n, int color, double dist);
t_cylinder			*create_cylinder(t_v *c, t_v *n, int color);
t_cone				*create_cone(t_v *c, t_v *n, int color, double angle);
t_sphere				*create_sphere(t_v *c, double r, int color);
t_light				*create_light(t_v *c, double brightness);

#endif
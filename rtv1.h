
#ifndef RTV1_H
# define RTV1_H
# define HEIGHT 800
# define WIDTH 1000

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

typedef	union		u_c
{
	int				color;
	char			c[4];
}					t_c;

typedef struct			s_mlx
{
	void				*win;
	void				*mlx;
	void				*im;
	int					*imdata;
	int					ls;
}						t_mlx;

typedef struct			s_v
{
	double				x;
	double				y;
	double				z;
}						t_v;

typedef struct			s_color
{
	int					r;
	int					b;
	int					g;
	int					a;
}						t_color;

/* 0 */

typedef struct			s_sphere
{
	t_v					*center;
	double				radius;
	int					color;
}						t_sphere;

/* 1 */

typedef struct 			s_plane
{
	t_v					*c;
	t_v					*n;
	int 					color;
}						t_plane;

/* 2 */

typedef struct			s_cylinder
{
	t_v *c;
	t_v *n;
	double r;
	int color;
}						t_cylinder;

typedef struct			s_obj
{
	int					type_obj;
	t_sphere				*s;
	t_plane				*p;
	t_cylinder			*cl;
	t_v					*intersects;
	struct s_obj			*next;
}						t_obj;

typedef struct			s_srceen
{
	t_v					*eye;
	t_v					*center;
	t_v					*points;
	t_v	   				*directions;
}						t_screen;

typedef struct			s_rt
{
	t_mlx				*mlx;
	t_screen				*screen;
	t_obj				*obj;
}						t_rt;

typedef struct			s_thrd
{
	int					y_min;
	int					y_max;
}						t_thrd;

t_mlx			*create_win(void);
void			create_image(t_mlx *mlx);
t_screen		*init_pos_screen(void);
void 			fill_objects(t_rt *rt);
void			put_pixel(int i, int color, t_mlx *mlx);
//v_oper
t_v				*add(t_v *v1, t_v *v2);
t_v				*sub(t_v *v1, t_v *v2);
double			module(t_v *v);
t_v				*normal(t_v *v1);
t_v				*mult(t_v *v1, double n);
t_v				*division(t_v *v1, double d);
void			v_copy(t_v *dest, t_v *src);
t_v				*new_vector(double x, double y, double z);
double			scalar_mult(t_v *v1, t_v *v2);


void			emit_rays(t_rt *rt);

t_v				*intersect_ray_sphere(t_v *d, t_v *p0, t_sphere *s, double *t);
t_v				*intersect_ray_plane(t_v *d,t_v *p0, t_plane *plane, double *t);
t_v				*intersect_ray_cylinder(t_v *d, t_v *p0, t_cylinder *s, double *t);
int				discriminant(double *t, t_abc abc);

int				intersect(t_rt *rt, t_v *d);
//buttons
int				destroy(void);
int				buttons(int keycode, t_rt *rt);

t_obj			*create_obj(int type_obj);
void			*add_obj(t_obj *first, t_obj *new);

t_plane			*create_plane(t_v *c, t_v *n, int color);
t_cylinder		*create_cylinder(t_v *c, t_v *n, int color);
t_sphere		*create_sphere(t_v *c);

#endif

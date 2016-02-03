/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 20:34:17 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/03 17:08:36 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "framework_shape/fk_type.h"
#include "framework_collision/fk_collision.h"
#include "framework_light/fk_normal_sphere.h"
#include "framework_shape/fk_objects.h"
#include "framework_shape/fk_listobj.h"
#include "framework_light/fk_light.h"
#include "framework_math/fk_math.h"

#define VECTOR_UP ((t_vector3) { .x = 0, .y = 1, .z = 0 })


inline t_vertex3	vector_to_vertex(t_vector3 vec)
{
	t_vertex3	tmp;

	tmp.x = vec.x;
	tmp.y = vec.y;
	tmp.z = vec.z;
	return (tmp);
}

t_vector3	vertex_to_vector(t_vertex3 vec)
{
	t_vector3	tmp;

	tmp.x = vec.x;
	tmp.y = vec.y;
	tmp.z = vec.z;
	return (tmp);
}

static	void	create_scene(t_object *light, t_object *arr)
{
	ft_memcpy(	arr + 0,
				&(t_sphere){	SPHERE,
								(t_rgba) {255, 139, 24, 0},
								0.2f,
								(t_vertex3) {0, 0, 20},
								1.00},
				sizeof(t_sphere));

	ft_memcpy(	arr + 1, //plafond
				&(t_plan){	PLANE,
								(t_rgba) {255, 100, 0, 0},
								0.0f,
								(t_vertex3) {0, 10, 0},
								vector_unit((t_vector3) {0, 40, 5})},
				sizeof(t_plan));

	ft_memcpy(	arr + 2,	// sol
				&(t_plan){	PLANE,
								(t_rgba) {200, 255, 0, 0},
								0.0f,
								(t_vertex3) {0, -10, 0},
								vector_unit((t_vector3) {0, -40, 5})},
				sizeof(t_plan));

	ft_memcpy(	arr + 3,	//Mur Gauche
				&(t_plan){	PLANE,
								(t_rgba) {200, 255, 100, 0},
								0.0f,
								(t_vertex3) {-10, 0, 0},
								vector_unit((t_vector3) {-100, 0, 5})},
				sizeof(t_plan));

	ft_memcpy(	arr + 4,	// mur droite
				&(t_plan){	PLANE,
								(t_rgba) {200, 255, 100, 0},
								0.0f,
								(t_vertex3) {10, 0, 0},
								vector_unit((t_vector3) {100, 0, 5})},
				sizeof(t_plan));

	ft_memcpy(	arr + 5,	// Sphere 2
				&(t_sphere){	SPHERE,
								(t_rgba) {200, 255, 200, 0},
								1.0f,
								(t_vertex3) {1, 0, 2},
								0.20},
				sizeof(t_sphere));

	ft_memcpy(light + 0,
				&(t_spotlight){	SPOTLIGHT,
								(t_rgba) {255, 255, 255, 0},
								0.0f,
								(t_vertex3) {-3, -1.79233, 0},
								(t_vector3) {1, 0, 0},
								1.},
				sizeof(t_spotlight));

	ft_memcpy(light + 1,
				&(t_spotlight){	SPOTLIGHT,
								(t_rgba) {255, 255, 255, 0},
								0.0f,
								(t_vertex3) {3, 2.688572153, 0},
								(t_vector3) {1, 2, 0},
								0.00},
				sizeof(t_spotlight));
	arr[6].type = DEFAULT;
}


static	t_rgba	getfinalcolor(t_object *light, t_intersect inter)
{
	t_rgba			color;
	t_rgba			color2;

	if (inter.obj)
	{
//		return inter.obj->color;
		color = iter_light(inter, (t_spotlight *)&light[0]);
		color2 = iter_light(inter, (t_spotlight *)&light[1]);
		return ((t_rgba) {
			(color.r + color2.r) / 2,
			(color.g + color2.g) / 2,
			(color.b + color2.b) / 2, 0
		});
	}
	return ((t_rgba) { 17, 25, 37, 0 });
}

t_ray	create_reflection(t_ray ray, t_intersect inter)
{
	t_ray		newray;
	t_vector3	 norm;

	norm = inter.v_normal;
	newray.dir = vector_substract(ray.dir,
			vector_scale(norm, 2.0f * vector_dotproduct(ray.dir, norm)));
	newray.pos = inter.pos;
	return (newray);
}

t_rgba	ft_trace_ray(t_env env, t_ray ray, int depth, float *dist_out)
{
	t_object		arr[16];
	t_object		light[16];
	t_intersect		inter;
	t_rgba			outcolor;
	t_rgba			refl_color;
	int				i;
	float			dist;
	float			_dist_out;

	if (dist_out == NULL)
		dist_out = &_dist_out;
	*dist_out = INFINITY;
	i = -1;
	create_scene(light, arr);
	inter.obj = NULL;
	while (++i < 16 && arr[i].type != DEFAULT)
	{
		if (env.fctinter[arr[i].type](ray, arr + i, &dist))
			if ((!inter.obj || dist < *dist_out) && dist > 0.1)
			{
				inter.obj = &arr[i];
				*dist_out = dist;
			}
	}
	outcolor = (t_rgba) { 17, 25, 37, 0 };
	if (inter.obj)
	{
		inter.pos = create_intersect(ray, *dist_out);
		inter.v_normal = env.fctnormal[inter.obj->type](inter.pos, inter.obj);
		outcolor = getfinalcolor(light, inter);
		if (inter.obj->reflection_index != 0.0 && depth < 3) {
			refl_color = ft_trace_ray(env, create_reflection(ray, inter), depth + 1, NULL);
			outcolor = color_sum(outcolor, color_mul(refl_color, inter.obj->reflection_index));
		}
	}
	return outcolor;
}

void			ft_put_pixel_to_image(t_img img, int x, int y, t_rgba color)
{
	int				addr;

	addr = y * img.sizeline + x * (img.bpp / 8);
	img.data[addr + 0] = color.b;
	img.data[addr + 1] = color.g;
	img.data[addr + 2] = color.r;
}

void		ft_render2(t_env env)
{
	t_rgba	rgba;
	t_ray	ray;
	float	y;
	float	x;
	float invW = 1 / (float)env.resolution.width;
	float invH = 1 / (float)env.resolution.height;
	float ratio = env.resolution.width / (float)env.resolution.height;
	float angle = tanf(M_PI * 0.5f * env.fov / 180.);

	// TODO : Put ray.dir.z = -1 here, it's more fun :D
	y = 0;
	while (y < env.resolution.height)
	{
		x = 0;
		while (x < env.resolution.width)
		{
			ray.pos = (t_vertex3) {0, 0, 0};
			ray.dir.x = (2. *(x * invW) - 1.) * angle * ratio;
			ray.dir.y = (1. - 2. * (y * invH)) * angle;
			ray.dir.z = 1;
			ray.dir = vector_unit(ray.dir);
			rgba = ft_trace_ray(env, ray, 0, NULL);
			ft_put_pixel_to_image(env.img, x, y, color_moy(1, rgba));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env.mlx, env.win, env.img.ptr, 0, 0);
}

void		ft_render(t_env env)
{
	ft_render2(env);
}

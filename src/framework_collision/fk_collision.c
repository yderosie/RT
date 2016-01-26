/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 20:34:17 by mbarbari          #+#    #+#             */
/*   Updated: 2016/01/25 12:36:51 by yderosie         ###   ########.fr       */
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
								(t_vertex3) {-1, 0, -13.5},
								2.00},
				sizeof(t_sphere));

	ft_memcpy(	arr + 1, //Plafont
				&(t_plan){	PLANE,
								(t_rgba) {255, 0, 0, 0},
								(t_vertex3) {2, 2, 0},
								vector_unit((t_vector3) {0, 3, 1})},
				sizeof(t_plan));

	ft_memcpy(	arr + 2,	//Mur Gauche
				&(t_plan){	PLANE,
								(t_rgba) {200, 255, 0, 0},
								(t_vertex3) {-1, 0, 0},
								vector_unit((t_vector3) {-10, 0, 4})},
				sizeof(t_plan));

	ft_memcpy(	arr + 3,	// sol
				&(t_plan){	PLANE,
								(t_rgba) {200, 255, 0, 0},
								(t_vertex3) {3,-3, 0},
								vector_unit((t_vector3) {0, -5, 1.5})},
				sizeof(t_plan));

	ft_memcpy(	arr + 4,	// mur droite
				&(t_plan){	PLANE,
								(t_rgba) {200, 255, 0, 0},
								(t_vertex3) {8, 0, 0},
								vector_unit((t_vector3) {10, 0, 5})},
				sizeof(t_plan));

	ft_memcpy(	arr + 5,
				&(t_sphere){	SPHERE,
								(t_rgba) {255, 55, 55, 0},
								(t_vertex3) {1, 0.79233, -10.9},
								1.00},
				sizeof(t_sphere));

	ft_memcpy(	arr + 6,
				&(t_cylinder){	CYLINDER,
								(t_rgba) {200, 155, 85, 0},
								(t_vertex3) {0, 1.79233, -7.9},
								(t_vector3) {0, 1, 0},
								1.00},
				sizeof(t_cylinder));

	ft_memcpy(light + 0,
				&(t_spotlight){	SPOTLIGHT,
								(t_rgba) {255, 55, 255, 0},
								(t_vertex3) {3, -1.79233, -17.9},
								(t_vector3) {1, 0, 0},
								1.},
				sizeof(t_spotlight));

	ft_memcpy(light + 1,
				&(t_spotlight){	SPOTLIGHT,
								(t_rgba) {255, 255, 255, 0},
								(t_vertex3) {3, 2.688572153, -10},
								(t_vector3) {1, 2, 0},
								1.00},
				sizeof(t_spotlight));
	arr[7].type = DEFAULT;
}


static	t_rgba	getfinalcolor(t_object *light, t_intersect inter)
{
	t_rgba			color;
	t_rgba			color2;

	if (inter.obj)
	{
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

//static	t_rgba	luminance(t_env env, t_ray ray, t_object *light, t_intersect i)
//{
//	t_rgba			color;
//	t_vector3		dirray;
//	t_vector3		normal;
//	t_vector3		dirlight;
//	t_ray			newray;
//	unsigned int	i;
//
//	i = 0;
//	dirray = vector_substract(i.pos, ray.pos);
//	vector_dotproduct(dirray, i.v_normal) < 0 ? -i.v_normal : i.v_normal;
//	while (light[i] != NULL)
//	{
//		if (vector_dotproduct(light->dir, normal) > 0) //Eclairage par reflexion
//		{
//			newray.pos = inter.pos;
//			newray.dir =
//			ft_trace_ray(env, (t_ray){
//		}
//
//	}
//
//}

void		ft_trace_ray(t_env env, t_ray ray, t_rgba *color)
{
	t_object		arr[16];
	t_object		light[16];
	t_intersect		inter;
	int				i;
	float			dist;
	float			old_dist;

	i = -1;
	create_scene(light, arr);
	inter.obj = NULL;
	while (++i < 16)
	{
		if (arr[i].type == DEFAULT)
			break ;
		if (env.fctinter[arr[i].type](ray, arr + i, &dist))
			if (!inter.obj || dist < old_dist)
			{
				inter.obj = &arr[i];
				old_dist = dist;
			}
	}
	if (inter.obj)
	{
		inter.pos = create_intersect(ray, old_dist);
		inter.v_normal = env.fctnormal[inter.obj->type](inter.pos, inter.obj);
	}
	*color = getfinalcolor(light, inter);
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
	int		y;
	int		x;
	float invW = 1 / (float)env.resolution.width;
	float invH = 1 / (float)env.resolution.height;
	float ratio = env.resolution.width / (float)env.resolution.height;
	float angle = tanf(M_PI * 0.5f * env.fov / 180.);

	y = 0;
	while (y < env.resolution.height)
	{
		x = 0;
		while (x < env.resolution.width)
		{

			ray.pos = (t_vertex3) {0, 0, 0};
			ray.dir.x = (2 *((x) * invW) - 1) * angle * ratio;
			ray.dir.y = (1 - 2 *((y) * invH)) * angle;
			ray.dir.z = -1;
			ray.dir = vector_unit(ray.dir);
			ft_trace_ray(env, ray, &rgba);
			ft_put_pixel_to_image(env.img, x, y, rgba);
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

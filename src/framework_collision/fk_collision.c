/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 20:34:17 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/04 21:03:04 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "parser.h"
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

static void		fill_arr(t_value val, int idx, t_object *data)
{
	if (ft_strequ(json_get(val.data.obj, "type").data.s, "SPHERE"))
	{
		ft_memcpy(data + idx, &(t_sphere){
			SPHERE,
			(t_rgba){json_get(val.data.obj, "color.red").data.number, json_get(val.data.obj, "color.green").data.number, json_get(val.data.obj, "color.blue").data.number, 0},
			json_get(val.data.obj, "reflection_index").data.number,
			(t_vertex3){json_get(val.data.obj, "pos.x").data.number, json_get(val.data.obj, "pos.y").data.number, json_get(val.data.obj, "pos.z").data.number},
			json_get(val.data.obj, "radius").data.number
		}, sizeof(t_sphere));
	}
	if (ft_strequ(json_get(val.data.obj, "type").data.s, "PLANE"))
	{
		ft_memcpy(data + idx, &(t_plan){
			PLANE,
			(t_rgba){json_get(val.data.obj, "color.red").data.number, json_get(val.data.obj, "color.green").data.number, json_get(val.data.obj, "color.blue").data.number, 0},
			json_get(val.data.obj, "reflection_index").data.number,
			(t_vertex3){json_get(val.data.obj, "pos.x").data.number, json_get(val.data.obj, "pos.y").data.number, json_get(val.data.obj, "pos.z").data.number},
			(t_vector3){json_get(val.data.obj, "normal.x").data.number, json_get(val.data.obj, "normal.y").data.number, json_get(val.data.obj, "normal.z").data.number}
		}, sizeof(t_plan));
	}
	if (ft_strequ(json_get(val.data.obj, "type").data.s, "CYLINDER"))
	{
		ft_memcpy(data + idx, &(t_cylinder){
			CYLINDER,
			(t_rgba){json_get(val.data.obj, "color.red").data.number, json_get(val.data.obj, "color.green").data.number, json_get(val.data.obj, "color.blue").data.number, 0},
			json_get(val.data.obj, "reflection_index").data.number,
			(t_vertex3){json_get(val.data.obj, "pos.x").data.number, json_get(val.data.obj, "pos.y").data.number, json_get(val.data.obj, "pos.z").data.number},
			(t_vector3){json_get(val.data.obj, "normal.x").data.number, json_get(val.data.obj, "normal.y").data.number, json_get(val.data.obj, "normal.z").data.number},
			json_get(val.data.obj, "radius").data.number
		}, sizeof(t_cylinder));
	}
	if (ft_strequ(json_get(val.data.obj, "type").data.s, "CONE"))
	{
		ft_memcpy(data + idx, &(t_cone){
			CONE,
			(t_rgba){json_get(val.data.obj, "color.red").data.number, json_get(val.data.obj, "color.green").data.number, json_get(val.data.obj, "color.blue").data.number, 0},
			(t_vertex3){json_get(val.data.obj, "pos.x").data.number, json_get(val.data.obj, "pos.y").data.number, json_get(val.data.obj, "pos.z").data.number},
			(t_vector3){json_get(val.data.obj, "normal.x").data.number, json_get(val.data.obj, "normal.y").data.number, json_get(val.data.obj, "normal.z").data.number},
			json_get(val.data.obj, "radius").data.number
		}, sizeof(t_cone));
	}
		if (ft_strequ(json_get(val.data.obj, "type").data.s, "SPOTLIGHT"))
	{
		ft_memcpy(data + idx, &(t_spotlight){
			SPOTLIGHT,
			(t_rgba){json_get(val.data.obj, "color.red").data.number, json_get(val.data.obj, "color.green").data.number, json_get(val.data.obj, "color.blue").data.number, 0},
			json_get(val.data.obj, "reflection_index").data.number,
			(t_vertex3){json_get(val.data.obj, "pos.x").data.number, json_get(val.data.obj, "pos.y").data.number, json_get(val.data.obj, "pos.z").data.number},
			(t_vector3){json_get(val.data.obj, "dir.x").data.number, json_get(val.data.obj, "dir.y").data.number, json_get(val.data.obj, "dir.z").data.number},
			json_get(val.data.obj, "intensity").data.number
		}, sizeof(t_spotlight));
	}
}

static	void	create_scene(t_value val, t_object *arr, t_object *light)
{
	json_foreach_arr(json_get(val.data.obj, "scene").data.arr, &fill_arr, arr);
	arr[json_arr_length(json_get(val.data.obj, "scene").data.arr)].type = DEFAULT;
	json_foreach_arr(json_get(val.data.obj, "lights").data.arr, &fill_arr, light);
	light[json_arr_length(json_get(val.data.obj, "lights").data.arr)].type = DEFAULT;
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

t_rgba	ft_trace_ray(t_object arr[16], t_object light[16], t_ray ray, int depth, float *dist_out, t_env env)
{
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
			refl_color = ft_trace_ray(arr, light, create_reflection(ray, inter), depth + 1, NULL, env);
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
	t_object arr[16];
	t_object light[16];
	float invW = 1 / (float)env.resolution.width;
	float invH = 1 / (float)env.resolution.height;
	float ratio = env.resolution.width / (float)env.resolution.height;
	float angle = tanf(M_PI * 0.5f * env.fov / 180.);

	// TODO : Put ray.dir.z = -1 here, it's more fun :D
	ft_bzero(arr, sizeof(t_object) * 16);
	ft_bzero(light, sizeof(t_object) * 16);
	create_scene(parser(env.file), arr, light);
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
			rgba = ft_trace_ray(arr, light, ray, 0, NULL, env);
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

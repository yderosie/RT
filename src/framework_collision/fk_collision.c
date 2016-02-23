/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 20:34:17 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/15 16:18:31 by barbare          ###   ########.fr       */
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
#include "framework_math/fk_vector.h"

#define VECTOR_UP ((t_vector3) { .x = 0, .y = 1, .z = 0 })
#define COLOR_ZERO ((t_color3) { .r = 0, .g = 0, .b = 0 })

int	g_death;


static void		fill_arr(t_value val, int idx, t_object *data)
{
	if (ft_strequ(json_get(val.data.obj, "type").data.s, "SPHERE"))
	{
		ft_memcpy(data + idx, &(t_sphere){
			SPHERE,
			color_new(json_get(val.data.obj, "color.red").data.number, json_get(val.data.obj, "color.green").data.number, json_get(val.data.obj, "color.blue").data.number),
			json_get(val.data.obj, "reflection_index").data.number,
			json_get(val.data.obj, "diffuse").data.number,
			vector_new(json_get(val.data.obj, "pos.x").data.number, json_get(val.data.obj, "pos.y").data.number, json_get(val.data.obj, "pos.z").data.number),
			json_get(val.data.obj, "radius").data.number
		}, sizeof(t_sphere));
	}
	if (ft_strequ(json_get(val.data.obj, "type").data.s, "PLANE"))
	{
		ft_memcpy(data + idx, &(t_plan){
			PLANE,
			color_new(json_get(val.data.obj, "color.red").data.number, json_get(val.data.obj, "color.green").data.number, json_get(val.data.obj, "color.blue").data.number),
			json_get(val.data.obj, "reflection_index").data.number,
			json_get(val.data.obj, "diffuse").data.number,
			vector_new(json_get(val.data.obj, "pos.x").data.number, json_get(val.data.obj, "pos.y").data.number, json_get(val.data.obj, "pos.z").data.number),
			vector_unit(vector_new(json_get(val.data.obj, "normal.x").data.number, json_get(val.data.obj, "normal.y").data.number, json_get(val.data.obj, "normal.z").data.number))
		}, sizeof(t_plan));
	}
	if (ft_strequ(json_get(val.data.obj, "type").data.s, "CYLINDER"))
	{
		ft_memcpy(data + idx, &(t_cylinder){
			CYLINDER,
			color_new(json_get(val.data.obj, "color.red").data.number, json_get(val.data.obj, "color.green").data.number, json_get(val.data.obj, "color.blue").data.number),
			json_get(val.data.obj, "reflection_index").data.number,
			json_get(val.data.obj, "diffuse").data.number,
			vector_new(json_get(val.data.obj, "pos.x").data.number, json_get(val.data.obj, "pos.y").data.number, json_get(val.data.obj, "pos.z").data.number),
			vector_unit(vector_new(json_get(val.data.obj, "normal.x").data.number, json_get(val.data.obj, "normal.y").data.number, json_get(val.data.obj, "normal.z").data.number)),
			json_get(val.data.obj, "radius").data.number
		}, sizeof(t_cylinder));
	}
	if (ft_strequ(json_get(val.data.obj, "type").data.s, "CONE"))
	{
		ft_memcpy(data + idx, &(t_cone){
			CONE,
			color_new(json_get(val.data.obj, "color.red").data.number, json_get(val.data.obj, "color.green").data.number, json_get(val.data.obj, "color.blue").data.number),
			json_get(val.data.obj, "reflection_index").data.number,
			json_get(val.data.obj, "diffuse").data.number,
			vector_new(json_get(val.data.obj, "pos.x").data.number, json_get(val.data.obj, "pos.y").data.number, json_get(val.data.obj, "pos.z").data.number),
			vector_unit(vector_new(json_get(val.data.obj, "normal.x").data.number, json_get(val.data.obj, "normal.y").data.number, json_get(val.data.obj, "normal.z").data.number)),
			json_get(val.data.obj, "radius").data.number,
			0
		}, sizeof(t_cone));
	}
	if (ft_strequ(json_get(val.data.obj, "type").data.s, "SPOTLIGHT"))
	{
		ft_memcpy(data + idx, &(t_spotlight){
			SPOTLIGHT,
			color_new(json_get(val.data.obj, "color.red").data.number, json_get(val.data.obj, "color.green").data.number, json_get(val.data.obj, "color.blue").data.number),
			json_get(val.data.obj, "reflection_index").data.number,
			json_get(val.data.obj, "diffuse").data.number,
			vector_new(json_get(val.data.obj, "pos.x").data.number, json_get(val.data.obj, "pos.y").data.number, json_get(val.data.obj, "pos.z").data.number),
			vector_new(json_get(val.data.obj, "dir.x").data.number, json_get(val.data.obj, "dir.y").data.number, json_get(val.data.obj, "dir.z").data.number),
			0.7
		}, sizeof(t_spotlight));
	}
}

static	void	create_scene(t_value val, t_object *arr, t_object *light)
{
	json_foreach_arr(json_get(val.data.obj, "scene").data.arr, &fill_arr, arr);
	arr[json_arr_length(json_get(val.data.obj, "scene").data.arr)].type = DEFAULT;
	json_foreach_arr(json_get(val.data.obj, "lights").data.arr, &fill_arr, light);
	light[json_arr_length(json_get(val.data.obj, "lights").data.arr)].type = DEFAULT;
	g_death = (int)json_get(val.data.obj, "death").data.number;
}

static	t_color3	getfinalcolor(t_object *arr, t_object *light, t_intersect inter, t_env env)
{
	t_color3			color;
	t_color3			color_tmp;
	float				diff;
	float				dot;
	float				dist[2];
	t_ray 				newray;
	float				shade;
	t_vector3		l;

	unsigned int		i;
	int k;
	unsigned int 		a;

	color_tmp = color_new(0, 0, 0);
	shade = 1.0;
	if (inter.obj)
	{
		i = 0;
		a = 0;
		while(light[i].type != DEFAULT)
		{
			if ((((t_spotlight *)(light + i))->intensity < 0.0f))
			{
				dprintf(2, "on passe la lumiere bordel\n");
				++i;
				continue ;
			}
			//check shade
			l = vector_substract(((t_spotlight *)(light + i))->pos, inter.pos);
			dist[0] = vector_magnitude(l);
			newray.pos = vector_substract(inter.pos, vector_mul(inter.v_normal, 1e-4f));	//vector_sum(inter.pos, vector_mul(inter.v_normal, 0.00001));
			newray.dir = vector_unit(l);
			if (dist[0] < 1000.)
			{
				k = -1;
				//shade2 = test(arr, newray, dist_out, env, shade, dist, inter);
				while (++k < 16 && arr[k].type != DEFAULT)
					if (env.fctinter[arr[k].type](newray, arr + k, &dist[1]))
						if (dist[1] < dist[0])/* && inter.obj->type != SPOTLIGHT)*/
						{
							shade = 0.0;
							break ;
						}
			}
			//check end shade
			//Create shading
			/*if (inter.obj->diffuse > 0)
			{
				dot = vector_dotproduct(vector_unit(vector_substract(((t_spotlight *)(light + 0))->pos, inter.pos)), inter.v_normal);
				if (dot > 0)
				{
					diff = dot * inter.obj->diffuse * shade;
					color_tmp = vector_product(((t_spotlight *)(light + 0))->color, inter.obj->color);
					color_tmp = vector_mul(color_tmp, diff);
				}
			}*/
			//end create shading
			color_tmp = iter_light(inter, ((t_spotlight *)&light[i]), shade);
			++i;
			++a;
		}
		
		if (shade == TRUE)
		{
			/*if (inter.obj->diffuse > 0)
			{
				dot = vector_dotproduct(vector_unit(vector_substract(((t_spotlight *)(light + 0))->pos, inter.pos)), inter.v_normal);
				if (dot > 0)
				{
					diff = dot * inter.obj->diffuse * shade;
					color_tmp = vector_product(((t_spotlight *)(light + 0))->color, inter.obj->color);
					color_tmp = vector_mul(color_tmp, diff);
				}
			}*/
		//	color_tmp = vector_div(vector_sum(color_tmp, color_new(0,0,0)), 2);
		}
		return (color_tmp);
		//return (vector_div(color_tmp, a));
	}
	return (color_new(17, 25, 37));
}

t_ray	create_reflection(t_ray ray, t_intersect inter)
{
	t_ray		newray;
	t_vector3	 norm;

	norm = inter.v_normal;
	newray.dir = vector_substract(ray.dir,
			vector_mul(norm, 2.0f * vector_dotproduct(ray.dir, norm)));
	newray.pos = inter.pos;
	return (newray);
}

t_bool	test(t_object arr[16], t_ray newray, float *dist_out, t_env env, t_bool shade, float dist, t_intersect inter)
{
	int i;

	i = -1;
	while (++i < 16 && arr[i].type != DEFAULT)
		if (env.fctinter[arr[i].type](newray, arr + i, &dist))
		{
			if (dist < (*dist_out - 1e-4f) && inter.obj->type != SPOTLIGHT)
			{
				shade = TRUE;
				break ;
			}
		}
	return (shade);
}

#include <stdio.h>
t_color3	ft_trace_ray(t_object arr[16], t_object light[16], t_ray ray, int depth, float *dist_out, t_env env)
{
	t_intersect		inter;
	t_color3		outcolor;
	t_color3		refl_color;
	int				i;
	float			dist;
	float			_dist_out;

	if (dist_out == NULL)
		dist_out = &_dist_out;
	*dist_out = INFINITY;
	outcolor = color_new(17, 25, 37);
	i = -1;
	inter.obj = NULL;
	while (++i < 16 && arr[i].type != DEFAULT)
		if (env.fctinter[arr[i].type](ray, arr + i, &dist))
			if ((!inter.obj || dist < *dist_out) && dist > 0.00001)
			{
				inter.obj = &arr[i];
				*dist_out = dist;
			}
	if (inter.obj)
	{
		inter.pos = create_intersect(ray, *dist_out);
		inter.v_normal = env.fctnormal[inter.obj->type](ray, inter.pos, inter.obj);
		inter.ray = ray;

		//start shadow is exist
		/*shade = FALSE;
		j = -1;
		while(++j < 16 && ((t_spotlight *)light)[j].type != DEFAULT)
		{
			
		}*/
		//end shadow is exist

		outcolor = getfinalcolor(arr, light, inter, env);
		if (inter.obj->reflection_index != 0.0 && depth < g_death)
		{
			refl_color = ft_trace_ray(arr, light, create_reflection(ray, inter), depth + 1, NULL, env);
			outcolor = vector_sum(outcolor, vector_mul(refl_color, inter.obj->reflection_index));
		}
	}
	return outcolor;
}

void			ft_put_pixel_to_image(t_img img, int x, int y, t_color3 color)
{
	int				addr;

	addr = y * img.sizeline + x * (img.bpp / 8);
	img.data[addr + 0] = FT_MAX(FT_MIN(color.b * 255, 255), 0);
	img.data[addr + 1] = FT_MAX(FT_MIN(color.g * 255, 255), 0);
	img.data[addr + 2] = FT_MAX(FT_MIN(color.r * 255, 255), 0);
}

void		ft_render2(t_env env)
{
	t_color3	rgba;
	t_ray	ray;
	float	y;
	float	x;
	t_object arr[16];
	t_object light[16];
	float invW = 1 / (float)env.resolution.width;
	float invH = 1 / (float)env.resolution.height;
	float ratio = env.resolution.width / (float)env.resolution.height;
	float angle = tanf(M_PI * 0.5f * env.fov / 180.);

	ft_bzero(arr, sizeof(t_object) * 16);
	ft_bzero(light, sizeof(t_object) * 16);
	create_scene(parser(env.file), arr, light);
	y = 0;
	while (y < env.resolution.height)
	{
		x = 0;
		while (x < env.resolution.width)
		{
			ray.pos = env.pos_absolute_camera;
			ray.dir.x = (2. *(x * invW) - 1.) * angle * ratio;
			ray.dir.y = (1. - 2. * (y * invH)) * angle;
			ray.dir.z = 1;
			ray.dir = vector_unit(ray.dir);
			rgba = ft_trace_ray(arr, light, ray, 0, NULL, env);
			ft_put_pixel_to_image(env.img, x, y, rgba);
			x++;
		}
		y++;
	}
	dprintf(2, "The end\n");
	mlx_put_image_to_window(env.mlx, env.win, env.img.ptr, 0, 0);
}

void		ft_render(t_env env)
{
	ft_render2(env);
}

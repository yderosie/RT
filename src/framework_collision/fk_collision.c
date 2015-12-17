/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 20:34:17 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/17 19:16:04 by mbarbari         ###   ########.fr       */
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

static t_intersect	nearest_vertex(t_ray ray, t_intersect new, t_intersect old)
{
	float	lengthv1;
	float	lengthv2;

	lengthv1 = vector_magnitude(vector_substract(new.pos, ray.pos));
	lengthv2 = vector_magnitude(vector_substract(old.pos, ray.pos));
	if (FT_MIN(lengthv1, lengthv2) == lengthv1)
		return (new);
	return (old);
}

static	void	create_scene(t_object *light, t_object *arr)
{
	ft_memcpy(	arr + 0,
				&(t_sphere){	SPHERE,
								(t_rgba) {255, 0, 125, 0},
								(t_vertex3) {600., 400.5, -3.5},
								200.00},
				sizeof(t_sphere));

	ft_memcpy(	arr + 1,
				&(t_plan){	PLANE,
								(t_rgba) {0, 255, 0, 0},
								(t_vertex3) {500, 0., 0.},
								vector_unit((t_vector3) {0, -1.5, 0})},
				sizeof(t_plan));

	ft_memcpy(	arr + 2,
				&(t_sphere){	SPHERE,
								(t_rgba) {255, 55, 55, 0},
								(t_vertex3) {-5.09824, -4.79233, 10.9},
								1.00},
				sizeof(t_sphere));

	ft_memcpy(light + 0,
				&(t_spotlight){	SPOTLIGHT,
								(t_rgba) {0, 0, 255, 0},
								(t_vertex3) {0., 240., -100},
								0.45,
								1.0},
				sizeof(t_spotlight));

	ft_memcpy(light + 1,
				&(t_spotlight){	SPOTLIGHT,
								(t_rgba) {255, 221, 13, 0},
								(t_vertex3) {-2.1876005426, 2.688572153, 6.4295767343},
								0.45,
								1.0},
				sizeof(t_spotlight));
	arr[1].type = DEFAULT;
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
			(color.b + color2.b) / 2
		});
	}
	return ((t_rgba) { 17, 25, 37, 0 });
}

void		ft_trace_ray(t_env env, t_ray ray, t_rgba *color)
{
	t_object		arr[16];
	t_object		light[16];
	t_intersect		inter;
	t_bool			already_has_radius;
	int				i;
	float			dist;
	float			old_dist;
	t_rgba			color;
	t_rgba 			color2;

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
		t_ray newray;
		newray.pos = inter.pos;
		newray.dir = vector_substract(ray.dir, vector_scale(inter.v_normal, -2 * vector_dotproduct(ray.dir, inter.v_normal)));
		newray.refracted = ray.refracted - 1;
		if (newray.refracted > 0)
			color = color_sum(*color, ft_trace_ray(env, newray));
	}
	inter.color = color_div(color, );
	color = getfinalcolor(light, inter);
}

static		void ft_render1(t_env env)
{
	t_rgba			rgba;
	t_ray			ray;
	int				y;
	int				x;
	t_vector3		vpRight;
	t_vector3		vpUp;
	float			halfWidth;
	float			halfHeight;
	float			pixelWidth;
	float			pixelHeight;

	halfWidth = tan(M_PI * (env.fov / 2.) / 180.);
	halfHeight = env.resolution.height / env.resolution.width * halfWidth;
	pixelWidth = halfWidth * 2 / ((env.resolution.width - 1) * 1.);
	pixelHeight = halfHeight * 2 / ((env.resolution.height - 1) * 1.);
	vpRight = vector_unit(vector_product(env.dir_camera, VECTOR_UP));
	vpUp = vector_unit(vector_product(vpRight, env.dir_camera));
	ray.pos = env.pos_absolute_camera;
	y = 0;
	while (y <= env.resolution.height)
	{
		x = 0;
		while (x <= env.resolution.width)
		{
			ray.dir = env.dir_camera;
			ray.dir = vector_sum(ray.dir, vector_scale(vpRight, (x * pixelWidth) - halfWidth));
			ray.dir = vector_sum(ray.dir, vector_scale(vpUp, (y * pixelHeight) - halfHeight));
			ray.dir = vector_unit(ray.dir);
			rgba = ft_trace_ray(env, ray);
			mlx_pixel_put(env.mlx, env.win, x, y, rgba_to_dword(rgba));
			x++;
		}
		y++;
	}
	dprintf(2, "THE END\n");
}

static void ft_render2(t_env env)
{
	t_rgba	rgba;
	t_ray	ray;
	int		y = -1;
	int		x;

	while (++y < env.resolution.height)
	{
		x = -1;
		while (++x < env.resolution.width)
		{
			ray.refracted = 4;
			ray.pos = (t_vertex3) {(float)x, (float)y, -1.};
			ray.dir = (t_vector3) {0., 0., 1.};
			rgba = ft_trace_ray(env, ray);
			mlx_pixel_put(env.mlx, env.win, x, y, rgba_to_dword(rgba));
		}
	}
}

static t_vector3	vector_add3(t_vector3 a, t_vector3 b, t_vector3 c)
{
	return ((t_vector3){a.x + b.x + c.x, a.y + b.y + c.y, a.z + b.z + c.z});
}

static void ft_render3(t_env env)
{
	t_rgba	rgba;
	t_ray	ray;
	int		y = -1;
	int		x;
	float	heightWidthRatio = env.resolution.height / (float)env.resolution.width;
	float	halfWidth = tanf(PI * (env.fov / 2.) / 180.);
	float	halfHeight = heightWidthRatio * halfWidth;
	float	camerawidth = halfWidth * 2.;
	float	cameraheight = halfHeight * 2.;
	float	pixelWidth = camerawidth / (float)(env.resolution.width - 1);
	float	pixelHeight = cameraheight / (float)(env.resolution.height -1);
	t_vector3	vpRight = vector_unit(vector_product(env.dir_camera, VECTOR_UP));
	t_vector3	vpUp = vector_unit(vector_product(vpRight, env.dir_camera));

	ray.pos = env.pos_absolute_camera;
	while (++y < env.resolution.height)
	{
		x = -1;
		while (++x < env.resolution.width)
		{
			t_vector3 a = vector_scale(vpRight, (x * pixelWidth) - halfWidth);
			t_vector3 b = vector_scale(vpUp, (y * pixelHeight) - halfHeight);
			ray.dir = vector_unit(vector_add3(env.dir_camera, a, b));
			rgba = ft_trace_ray(env, ray);
			mlx_pixel_put(env.mlx, env.win, x, y, rgba_to_dword(rgba));
		}
	}
}

void		ft_render(t_env env)
{
	ft_render2(env);
}

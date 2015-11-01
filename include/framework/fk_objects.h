/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_objects.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 12:32:17 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/01 20:46:49 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_OBJECTS_H
# define FK_OBJECTS_H

typedef struct		s_objects t_objects;
typedef struct		s_sphere t_sphere;

typedef float		*(*t_fctinter)(t_ray ray, void *obj, t_intersect *inter);

typedef enum		e_type
{
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
	DEFAULT
};

struct				s_material
{
	char			*tile;
}

struct				t_object
{
	e_type			type;
	char			stuff[128];
};

struct				s_sphere
{
	e_type			type;
	t_vertex3		position;
	float			radius;
};

struct				s_cone
{
	e_type			type;
	t_material		material;
	t_vertex3		position;
	t_vector3		height;
	float			radius;
};

t_bool			intersect_sphere(t_ray ray, void* obj, t_intersect *inter);
t_sphere		*new_sphere(t_vector pos, unsigned int radius);

#endif

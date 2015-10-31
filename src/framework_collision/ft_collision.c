/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 22:28:10 by mbarbari          #+#    #+#             */
/*   Updated: 2015/10/31 23:46:08 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void		rec_throw_y(unsigned int x, unsigned int y, t_objects objs)
{
	t_objects	objects;

	objects = &objs;
	while (objs)
	{
		objects->object->fctinter(ray, objects->object, inter);
		objects = objects->nextobj;
	}
	if (y > 0)
		rec_throw_y(x, --y, objs);
}

void		ft_throwing_ray(t_resolution resolution, t_objects objs)
{
	
}

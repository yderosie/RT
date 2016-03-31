/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 11:22:23 by mbarbari          #+#    #+#             */
/*   Updated: 2016/03/31 13:28:00 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdlib.h"
#include "framework_event/fk_event.h"
#include "framework_collision/fk_collision.h"

int		file_is_modified(const char *path, time_t *oldtime, int i)
{
	struct stat	file_stat;
	int			err;
	int			ismodified;

	err = stat(path, &file_stat);
	if (err == -1)
	{
		ft_printf("Fichier %s errone\n", path);
		exit(0);
	}
	if (i == 1)
		*oldtime = file_stat.st_mtime;
	else
	{
		ismodified = file_stat.st_mtime > *oldtime;
		*oldtime = file_stat.st_mtime;
		return (ismodified);
	}
	return (0);
}

int		loop_hook(t_env *env)
{
	if (file_is_modified(env->file, &env->oldtime, 0))
		ft_render(*env);
	return (0);
}

int		rt_expose_hook(t_env *env)
{
	if (file_is_modified(env->file, &env->oldtime, 0))
		ft_render(*env);
	mlx_put_image_to_window(env->mlx, env->win, env->img.ptr, 0, 0);
	return (0);
}

int		key_press(int key, t_env *env)
{
	if (key == 53 || key == 65307)
		exit(0);
	env->anglex += (key == 124) ? 0.1 : 0.0;
	env->anglex -= (key == 123) ? 0.1 : 0.0;
	env->angley += (key == 126) ? 0.1 : 0.0;
	env->angley -= (key == 125) ? 0.1 : 0.0;
	env->pos_absolute_camera.z += (key == 13) ? 1.0 : 0.0;
	env->pos_absolute_camera.z -= (key == 1) ? 1.0 : 0.0;
	ft_render(*env);
	return (0);
}

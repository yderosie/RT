/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 21:03:28 by roblabla          #+#    #+#             */
/*   Updated: 2015/12/08 11:42:59 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"
#include <mlx.h>
#include "ft_printf.h"
#include "framework_math/fk_vector.h"
#include <stdlib.h>

int		rt_expose_hook(t_env *env)
{
	ft_render(*env);
	return (0);
}

/*
** TODO : Check segfault
*/
int		main(int argc, char **argv)
{
	t_env	env;

	(void)argc;
	(void)argv;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 1200, 1200, "RayTracer");
	env.img = mlx_new_image(env.mlx, 1200, 1200);
	env.resolution.width = 1200;
	env.resolution.height = 1200;
	env.fov = 70;
	env.pos_absolute_camera = (t_vertex3) { 0, 0, 0 };
	env.dir_camera = (t_vector3) { 0, 0, 1 };
	ft_setup_fct_inter(&env.fctinter);
	rt_expose_hook(&env);
	mlx_expose_hook(env.win, rt_expose_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}

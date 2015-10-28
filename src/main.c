/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 21:03:28 by roblabla          #+#    #+#             */
/*   Updated: 2015/10/28 14:45:42 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "rt_main.h"

int		rt_expose_hook(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	env;

	(void)argc;
	(void)argv;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 500, 500, "RayTracer");
	env.img = mlx_new_image(env.mlx, 500, 500);
	mlx_expose_hook(env.win, rt_expose_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_event.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 11:27:44 by yderosie          #+#    #+#             */
/*   Updated: 2016/03/31 12:02:35 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_EVENT_H
# define FK_EVENT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <mlx.h>
# include "ft_env.h"

int		file_is_modified(const char *path, time_t *oldtime, int i);
int		loop_hook(t_env *env);
int		rt_expose_hook(t_env *env);
int		key_press(int key, t_env *env);

#endif

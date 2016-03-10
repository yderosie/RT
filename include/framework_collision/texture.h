/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 14:57:54 by yderosie          #+#    #+#             */
/*   Updated: 2016/03/04 14:57:55 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "framework_collision/fk_collision.h"
# include "framework_math/fk_vector.h"
# include "framework_shape/fk_ray.h"
#include "ft_env.h"

typedef struct	s_perlin
{
	int xx;
	int yy;
	int zz;
	double u;
	double v;
	double w;
	int 	a;
	int		b;
	int		aa;
	int		ab;
	int		ba;
	int		bb;
}				t_perlin;


typedef	struct s_noise
{
	int bx0;
	int bx1;
	int by0;
	int by1;
	int bz0;
	int bz1;
	int b00;
	int b10;
	int b01;
	int b11;
	double rx0;
	double rx1;
	double ry0;
	double ry1;
	double rz0;
	double rz1;
	double *q;
	double sy;
	double sz;
	double a;
	double b;
	double c;
	double d;
	double t;
	double u;
	double v;
	int i;
	int j;
}				t_noise;

t_color3			checkerboard(t_vertex3 pos);
double				perlin_noise(double x, double y, double z);

#define B 0x100
#define BM 0xff
#define N 0x1000
#define NP 12   /* 2^N */
#define NM 0xfff

#define s_curve(t) ( t * t * (3. - 2. * t) )
#define lerp(t, a, b) ( a + t * (b - a) )
#define setup(i,b0,b1,r0,r1)\
        n.t = vec[i] + N;\
        b0 = ((int)n.t) & BM;\
        b1 = (b0+1) & BM;\
        r0 = n.t - (int)n.t;\
        r1 = r0 - 1.;
#define at2(rx,ry) ( rx * n.q[0] + ry * n.q[1] )
#define at3(rx,ry,rz) ( rx * n.q[0] + ry * n.q[1] + rz * n.q[2] )

void				init(void);
double				noise3(double *);
void				normalize3(double *);
void				normalize2(double *);

double 				PerlinNoise3D(double x,double y,double z,double alpha,double beta,int n);

#endif
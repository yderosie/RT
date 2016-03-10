/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 14:33:27 by yderosie          #+#    #+#             */
/*   Updated: 2016/03/04 14:33:28 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_collision/texture.h"
#include "framework_math/fk_math.h"
#include <limits.h>

static int			check_pair(float point)
{
	int		x;
	float	len;

	len = 1;
	x = (int)(ABS((point + 0.001) / len)) % 2;
	if (point < 0)
		return x == 0 ? 1 : 0;
	return (x % 2);
}

#define round(x) ((x) < LONG_MIN-0.5 || (x) > LONG_MAX+0.5)

t_color3			checkerboard(t_vertex3 pos)
{
	int			result[3];
	t_color3	color;
	t_color3	color2;

	color = color_new(0, 0, 0);
	color2 = color_new(12, 34, 120);
	result[0] = check_pair((pos.x));
	result[1] = check_pair((pos.y));
	result[2] = check_pair((pos.z));

//test
/*	float          l;
    int         x1;
    int         x2;
    int         x3;

    l = .80;
    x1 = round(fabs(pos.x) / l);
    x2 = round(fabs(pos.y) / l);
    x3 = round(pos.z / fabs(l));
    if (x3 % 2 == 0)
    {
        if ((x2 % 2 == 1 && x1 % 2 == 1) || (x2 %2 == 0 && x1 % 2 == 0))
            return(color);
        else
            return(color2);
    }
    else    
    {
        if ((x2 % 2 == 1 && x1 % 2 == 1) || (x2 %2 == 0 && x1 % 2 == 0))
            return(color2);
        else
            return(color);
    }
*/
//Fin test



	if (result[2] == 0)
	{
		if ((!result[0] && !result[1]) || (result[0] && result[1]))
			return (color);
		else
		{
			return (color2);
		}
	}
	if ((!result[0] && !result[1]) || (result[0] && result[1]))
	{
		return (color2);
	}
	else
		return (color);
}

/*static int			g_p[] = {151, 160, 137, 91, 90, 15,
	131, 13, 201, 95, 96, 53, 194, 233, 7, 225, 140, 36, 103, 30, 69, 142, 8,
	99, 37, 240, 21, 10, 23, 190, 6, 148, 247, 120, 234, 75, 0, 26, 197, 62,
	94, 252, 219, 203, 117, 35, 11, 32, 57, 177, 33, 88, 237, 149, 56, 87, 174,
	20, 125, 136, 171, 168, 68, 175, 74, 165, 71, 134, 139, 48, 27, 166, 77,
	146, 158, 231, 83, 111, 229, 122, 60, 211, 133, 230, 220, 105, 92, 41, 55,
	46, 245, 40, 244, 102, 143, 54, 65, 25, 63, 161, 1, 216, 80, 73, 209, 76,
	132, 187, 208, 89, 18, 169, 200, 196, 135, 130, 116, 188, 159, 86, 164,
	100, 109, 198, 173, 186, 3, 64, 52, 217, 226, 250, 124, 123, 5, 202, 38,
	147, 118, 126, 255, 82, 85, 212, 207, 206, 59, 227, 47, 16, 58, 17, 182,
	189, 28, 42, 223, 183, 170, 213, 119, 248, 152, 2, 44, 154, 163, 70, 221,
	153, 101, 155, 167, 43, 172, 9, 129, 22, 39, 253, 19, 98, 108, 110, 79,
	113, 224, 232, 178, 185, 112, 104, 218, 246, 97, 228, 251, 34, 242, 193,
	238, 210, 144, 12, 191, 179, 162, 241, 81, 51, 145, 235, 249, 14, 239, 107,
	49, 192, 214, 31, 181, 199, 106, 157, 184, 84, 204, 176, 115, 121, 50, 45,
	127, 4, 150, 254, 138, 236, 205, 93, 222, 114, 67, 29, 24, 72, 243, 141,
	128, 195, 78, 66, 215, 61, 156, 180,
	151, 160, 137, 91, 90, 15,
	131, 13, 201, 95, 96, 53, 194, 233, 7, 225, 140, 36, 103, 30, 69, 142, 8,
	99, 37, 240, 21, 10, 23, 190, 6, 148, 247, 120, 234, 75, 0, 26, 197, 62,
	94, 252, 219, 203, 117, 35, 11, 32, 57, 177, 33, 88, 237, 149, 56, 87, 174,
	20, 125, 136, 171, 168, 68, 175, 74, 165, 71, 134, 139, 48, 27, 166, 77,
	146, 158, 231, 83, 111, 229, 122, 60, 211, 133, 230, 220, 105, 92, 41, 55,
	46, 245, 40, 244, 102, 143, 54, 65, 25, 63, 161, 1, 216, 80, 73, 209, 76,
	132, 187, 208, 89, 18, 169, 200, 196, 135, 130, 116, 188, 159, 86, 164,
	100, 109, 198, 173, 186, 3, 64, 52, 217, 226, 250, 124, 123, 5, 202, 38,
	147, 118, 126, 255, 82, 85, 212, 207, 206, 59, 227, 47, 16, 58, 17, 182,
	189, 28, 42, 223, 183, 170, 213, 119, 248, 152, 2, 44, 154, 163, 70, 221,
	153, 101, 155, 167, 43, 172, 9, 129, 22, 39, 253, 19, 98, 108, 110, 79,
	113, 224, 232, 178, 185, 112, 104, 218, 246, 97, 228, 251, 34, 242, 193,
	238, 210, 144, 12, 191, 179, 162, 241, 81, 51, 145, 235, 249, 14, 239, 107,
	49, 192, 214, 31, 181, 199, 106, 157, 184, 84, 204, 176, 115, 121, 50, 45,
	127, 4, 150, 254, 138, 236, 205, 93, 222, 114, 67, 29, 24, 72, 243, 141,
	128, 195, 78, 66, 215, 61, 156, 180
};

static double		fade(double t)
{
	return (t * t * t * (t * (t * 6 - 15) + 10));
}

static double		lerp(double t, double a, double b)
{
	return (a + t * (b - a));
}

static double		grad(int hash, double x, double y, double z)
{
	int		h;
	double	u;
	double	v;

	h = hash & 15;
	u = h < 8 || h == 12 || h == 13 ? x : y;
	v = h < 4 || h == 12 || h == 13 ? y : z;
	return (((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v));
}

double				perlin_noise(double x, double y, double z)
{
	t_perlin p;

	p.xx = (int)floor(x) & 255;
	p.yy = (int)floor(y) & 255;
	p.zz = (int)floor(z) & 255;
	x -= floor(x);
	y -= floor(y);
	z -= floor(z);
	p.u = fade(x);
	p.v = fade(y);
	p.w = fade(z);
	p.a = g_p[p.xx] + p.yy;
	p.aa = g_p[p.a] + p.zz;
	p.ab = g_p[p.a + 1] + p.zz;
	p.b = g_p[p.xx + 1] + p.yy;
	p.ba = g_p[p.b] + p.zz;
	p.bb = g_p[p.b + 1] + p.zz;
	return (lerp(p.w, lerp(p.v, lerp(p.u, grad(g_p[p.aa], x, y, z),
									grad(g_p[p.ba], x - 1, y, z)),
								lerp(p.u, grad(g_p[p.ab], x, y - 1, z),
									grad(g_p[p.bb], x - 1, y - 1, z))),
						lerp(p.v, lerp(p.u, grad(g_p[p.aa + 1], x, y, z - 1),
									grad(g_p[p.ba + 1], x - 1, y, z - 1)),
								lerp(p.u, grad(g_p[p.ab + 1], x, y - 1, z - 1),
								grad(g_p[p.bb + 1], x - 1, y - 1, z - 1)))));
}
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static int p[B + B + 2];
static double g3[B + B + 2][3];
static double g2[B + B + 2][2];
static double g1[B + B + 2];
static int start = 1;

double noise3(double vec[3])
{
   t_noise n;

   if (start) {
      start = 0;
      init();
   }

   setup(0, n.bx0, n.bx1, n.rx0, n.rx1);
   setup(1, n.by0, n.by1, n.ry0, n.ry1);
   setup(2, n.bz0, n.bz1, n.rz0, n.rz1);

   n.i = p[n.bx0];
   n.j = p[n.bx1];

   n.b00 = p[n.i + n.by0];
   n.b10 = p[n.j + n.by0];
   n.b01 = p[n.i + n.by1];
   n.b11 = p[n.j + n.by1];

   n.t  = s_curve(n.rx0);
   n.sy = s_curve(n.ry0);
   n.sz = s_curve(n.rz0);

   n.q = g3[n.b00 + n.bz0];
   n.u = at3(n.rx0, n.ry0, n.rz0);
   n.q = g3[n.b10 + n.bz0];
   n.v = at3(n.rx1, n.ry0, n.rz0);
   n.a = lerp(n.t, n.u, n.v);

   n.q = g3[n.b01 + n.bz0];
   n.u = at3(n.rx0, n.ry1, n.rz0);
   n.q = g3[n.b11 + n.bz0];
   n.v = at3(n.rx1, n.ry1, n.rz0);
   n.b = lerp(n.t, n.u, n.v);

   n.c = lerp(n.sy, n.a, n.b);

   n.q = g3[n.b00 + n.bz1];
   n.u = at3(n.rx0, n.ry0, n.rz1);
   n.q = g3[n.b10 + n.bz1];
   n.v = at3(n.rx1, n.ry0, n.rz1);
   n.a = lerp(n.t, n.u, n.v);

   n.q = g3[n.b01 + n.bz1];
   n.u = at3(n.rx0, n.ry1, n.rz1);
   n.q = g3[n.b11 + n.bz1];
   n.v = at3(n.rx1, n.ry1, n.rz1);
   n.b = lerp(n.t, n.u, n.v);

   n.d = lerp(n.sy, n.a, n.b);

   return lerp(n.sz, n.c, n.d);
}

void normalize2(double v[2])
{
   double s;

   s = sqrt(v[0] * v[0] + v[1] * v[1]);
   v[0] = v[0] / s;
   v[1] = v[1] / s;
}

void normalize3(double v[3])
{
   double s;

   s = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
   v[0] = v[0] / s;
   v[1] = v[1] / s;
   v[2] = v[2] / s;
}

void init(void)
{
   int i;
   int j;
   int k;

   i = -1;
   while (++i < B)
   {
      p[i] = i;
      g1[i] = (double)((random() % (B + B)) - B) / B;
      j = -1;
      while (++j < 2)
         g2[i][j] = (double)((random() % (B + B)) - B) / B;
      normalize2(g2[i]);
      j = -1;
      while (++j < 3)
         g3[i][j] = (double)((random() % (B + B)) - B) / B;
      normalize3(g3[i]);
   }
   while (--i) {
      k = p[i];
      p[i] = p[j = random() % B];
      p[j] = k;
   }
   i = -1;
   while (++i < B + 2) {
      p[B + i] = p[i];
      g1[B + i] = g1[i];
      j = -1;
      while (++j < 2)
         g2[B + i][j] = g2[i][j];
      j = -1;
      while (++j < 3)
         g3[B + i][j] = g3[i][j];
   }
}


double PerlinNoise3D(double x,double y,double z,double alpha,double beta,int n)
{
   int i;
   double val,sum = 0;
   double p[3],scale = 1;

   p[0] = x;
   p[1] = y;
   p[2] = z;
   i = -1;
   while (++i < n) {
      val = noise3(p);
      sum += val / scale;
      scale *= alpha;
      p[0] *= beta;
      p[1] *= beta;
      p[2] *= beta;
   }
   return(sum);
}


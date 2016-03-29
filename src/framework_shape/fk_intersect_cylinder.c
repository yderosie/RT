/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_intersect_cylinder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:28:56 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/01 14:53:11 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_shape/fk_cylinder.h"
#include "framework_math/fk_math.h"

/*static t_bool	 SolveQuarticEquation(float a, float b, float c, float d, float e, float roots[4])
    {
        if (a == 0.0)
        {
            return FALSE;
        }

        // See "Summary of Ferrari's Method" in http://en.wikipedia.org/wiki/Quartic_function
        
        // Without loss of generality, we can divide through by 'a'.
        // Anywhere 'a' appears in the equations, we can assume a = 1.
        b /= a;
        c /= a;
        d /= a;
        e /= a;

        float b2 = b * b;
        float b3 = b * b2;
        float b4 = b2 * b2;

        float alpha = (-3.0/8.0)*b2 + c;
        float beta  = b3/8.0 - b*c/2.0 + d;
        float gamma = (-3.0/256.0)*b4 + b2*c/16.0 - b*d/4.0 + e;

        float alpha2 = alpha * alpha;
        float t = -b / 4.0;

        if (beta == 0.0)
        {
            float rad = sqrt(alpha2 - 4.0*gamma);
            float r1 = sqrt((-alpha + rad) / 2.0);
            float r2 = sqrt((-alpha - rad) / 2.0);

            roots[0] = t + r1;
            roots[1] = t - r1;
            roots[2] = t + r2;
            roots[3] = t - r2;
        }
        else
        {
            float alpha3 = alpha * alpha2;
            float P = -(alpha2/12.0 + gamma);
            float Q = -alpha3/108.0 + alpha*gamma/3.0 - beta*beta/8.0;
            float R = -Q/2.0 + sqrt(Q*Q/4.0 + P*P*P/27.0);
            float U = cbrt(R);
            float y = (-5.0/6.0)*alpha + U;
            if (U == 0.0)
            {
                y -= cbrt(Q);
            }
            else
            {
                y -= P/(3.0 * U);
            }
            float W = sqrt(alpha + 2.0*y);

            float r1 = sqrt(-(3.0*alpha + 2.0*y + 2.0*beta/W));
            float r2 = sqrt(-(3.0*alpha + 2.0*y - 2.0*beta/W));

            roots[0] = t + ( W - r1)/2.0;
            roots[1] = t + ( W + r1)/2.0;
            roots[2] = t + (-W - r2)/2.0;
            roots[3] = t + (-W + r2)/2.0;
        }
        return TRUE;
    }

#define R 1.01
#define R_2 1.01

t_bool			intersect_cylinder(t_ray ray, t_cylinder *obj, float *t)
{
	float		a;
	float		b;
	float		c;
	float		d;
	float		e;
	int 		i = 0;
	t_vector3	etoc;
	float		roots[4];

	etoc = vector_substract(ray.pos, obj->pos);
	a = SQUARE(vector_magnitude(ray.dir));
	b = 4 * a * vector_dotproduct(ray.dir, etoc);
	c = SQUARE(4 * a) + 2 * a * vector_dotproduct(etoc, etoc) - 2 * (SQUARE(R) + SQUARE(R_2)) * a + 4 * SQUARE(R) * SQUARE(vector_dotproduct(ray.dir, obj->dir));
	d = 4 * vector_dotproduct(ray.dir, etoc) * vector_magnitude(etoc) - 4 * (SQUARE(R) + SQUARE(R_2)) * vector_dotproduct(ray.dir, etoc) + 8 * SQUARE(R) * vector_dotproduct(ray.dir, obj->dir) * vector_dotproduct(etoc, obj->dir);
	e = SQUARE(vector_magnitude(etoc)) - 2 * (SQUARE(R) + SQUARE(R_2)) * vector_magnitude(etoc) + 4 * SQUARE(R) * SQUARE(vector_dotproduct(etoc, obj->dir)) + SQUARE(SQUARE(R) + SQUARE(R_2));
	if (SolveQuarticEquation(a, b, c, d, e, roots))
	{
		//printf("%f %f %f %f \n", roots[0], roots[1], roots[2], roots[3]);
			*t = INFINITY;
            while (i < 4) {
            	if (roots[i] < *t && roots[i] > 0)
					*t = roots[i];
				i++;
            }
		if (*t < INFINITY)
			return TRUE;
	}
	return FALSE;
}*/


t_bool			intersect_cylinder(t_ray ray, t_cylinder *obj, float *t)
{
	float		a;
	float		b;
	float		c;
	float		d;
	t_vector3	etoc;

	etoc = vector_substract(ray.pos, obj->pos);
	a = vector_dotproduct(ray.dir, ray.dir) -
		SQUARE(vector_dotproduct(ray.dir, obj->dir));
	b = (vector_dotproduct(ray.dir, etoc) - vector_dotproduct(ray.dir,
		obj->dir) * vector_dotproduct(etoc, obj->dir)) * 2;
	c = vector_dotproduct(etoc, etoc) -
		SQUARE(vector_dotproduct(etoc, obj->dir)) - (obj->radius * obj->radius);
	d = b * b - 4 * a * c;
	if (d > 0.)
	{
		*t = FT_MIN(((-b - sqrt(d)) / (2 * a)), ((-b - sqrt(d)) / (2 * a)));
		if (*t >= 0.)
			return (TRUE);
	}
	return (FALSE);
}

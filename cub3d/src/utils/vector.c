/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:19:52 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/03 13:19:53 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	vec_new(double x, double y)
{
	t_vec	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_vec	vec_add(t_vec v1, t_vec v2)
{
	return (vec_new(v1.x + v2.x, v1.y + v2.y));
}

t_vec	vec_mul(t_vec v, double n)
{
	return (vec_new(v.x * n, v.y * n));
}

t_pos	double_to_int(t_vec v)
{
	t_pos	pos;

	pos.x = (int)v.x;
	pos.y = (int)v.y;
	return (pos);
}

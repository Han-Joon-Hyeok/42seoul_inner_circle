/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:19:28 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/03 13:19:34 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec {
	double	x;
	double	y;
}	t_vec;

typedef struct s_pos {
	int	x;
	int	y;
}	t_pos;

// vector.c
t_vec	vec_new(double x, double y);
t_vec	vec_add(t_vec v1, t_vec v2);
t_vec	vec_mul(t_vec v, double n);
t_pos	double_to_int(t_vec v);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:11:19 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/07 17:42:52 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isalpha(int c);

int	main(void)
{
	int	i;

	i = 0;
	printf("\n\n ✅ TEST1: ft_isalpha");
	while (i <= 127)
	{
		printf("\n\n");
		printf("Input char(int): %c(%d), isalpha: %d\n", i, i, isalpha(i));
		printf("Input char(int): %c(%d), ft_isalpha: %d\n", i, i, ft_isalpha(i));
		i += 1;
	}

	int	j;

	j = 0;
	while (j <= 127)
	{
		printf("Input: %c, isdigit: %d\n", j, isdigit(j));
		printf("Input: %c, ft_isdigit: %d\n", j, ft_isdigit(j));
		printf("\n\n");
		j += 1;
	}
	return (0);
}

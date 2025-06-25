/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:34:20 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/06/25 10:34:21 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	ret_ft_printf;
	int	ret_printf;

	ret_ft_printf = ft_printf("%x\n", 250);
	ret_printf = printf("%x\n", 250);
	printf("ft_printf returned: %d\n", ret_ft_printf);
	printf("printf returned: %d\n", ret_printf);
	printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	ret_ft_printf = ft_printf("%p\n", 0);
	ret_printf = printf("%p\n", 0);
	printf("ft_printf returned: %d\n", ret_ft_printf);
	printf("printf returned: %d\n", ret_printf);
	printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	return (0);
}

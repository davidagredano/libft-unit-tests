/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_test_result.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:16:43 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/19 14:26:12 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

void	ft_print_test_result(const char *test_name, int pass)
{
	printf("%s:\t", test_name);
        if (pass)
                printf("OK\n");
        else
                printf("KO\n");
}

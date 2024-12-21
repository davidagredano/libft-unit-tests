/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:16:43 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/21 11:33:49 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

void	ft_log_result_test(const char *test_name, bool pass)
{
	printf("%s:\t%s\n", test_name, pass ? "OK" : "KO");
}

void	ft_log_result_str(char *expected, char *result, bool pass)
{
	printf("%s:\t", pass ? "Pass" : "Error");
	printf("Exected '%s' got '%s'\n", expected, result);
}

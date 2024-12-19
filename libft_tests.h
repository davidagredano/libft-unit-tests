/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tests.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:40:36 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/19 14:58:22 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TESTS_H
# define LIBFT_TESTS_H

#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    ft_print_test_result(const char *test_name, int pass);

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);

void	ft_isalpha_test(void);
void	ft_isdigit_test(void);
void	ft_isalnum_test(void);
void	ft_isascii_test(void);
void	ft_isprint_test(void);
void	ft_strlen_test(void);
void	ft_memset_test(void);

#endif

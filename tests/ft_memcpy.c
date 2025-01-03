/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:39:05 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/02 16:12:09 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

static int	ft_assert(void *dest_std, void *dest_mine, void *src, size_t n)
{
	int	pass;

	pass = 1;
	dest_std = malloc(n);
	dest_mine = malloc(n);
	if (!dest_std || !dest_mine)
	{
		printf("Error: Malloc returned NULL.\n");
		return (0);
	}
	memcpy(dest_std, src, n);
	ft_memcpy(dest_mine, src, n);
	if (memcmp(dest_std, dest_mine, n) != 0)
	{
		pass = 0;
		printf("Error: ");
		printf("Expected '%s' ", (char *) dest_std);
		printf("instead of '%s'\n", (char *) dest_mine);
	}
	free(dest_std);
	free(dest_mine);
	return (pass);
}

static void	ft_test_segfault(void)
{
	void 	*dest;
	void	*src;
	int		n;

	//printf("Test 1: dest=NULL\n");
	/*
	dest = 0;
	if (!(src = strdup("a")))
	{
		printf("Malloc failed.\n");
		return ;
	}
	n = 2;
	printf("memcpy(dest=%p, src=\"%s\", n=%d)\n", dest, (char *) src, n);
	printf("Should Segmentation fault\n");
	memcpy(dest, src, 1); // Segmentation fault
	//ft_memcpy(dest, src, 1); // Should Segmentation fault
	*/

	//printf("Test 2: src=NULL\n");
	/*
	if (!(dest = strdup("a")))
	{
		printf("Malloc failed.\n");
		return ;
	}
	src = 0;
	n = 2;
	printf("memcpy(dest=\"%s\", src=%p, n=%d)\n", (char *) dest, src, n);
	printf("Should Segmentation fault\n");
	memcpy(dest, src, n); // Segmentation fault
	//ft_memcpy(dest, src, n); // Should Segmentation fault
	*/

	//printf("Test 3: dest=NULL src=NULL\n");
	/*
	dest = 0;
	src = 0;
	n = 3;
	printf("memcpy(dest=%p, src=%p, n=%d)\n", dest, src, n);
	printf("Should Segmentation fault\n");
	memcpy(dest, src, n); // Segmentation fault
	//ft_memcpy(dest, src, n); // Should Segmentation fault
	*/

	//printf("Test 4: dest=NULL src=NULL n=0\n");
	/*
	dest = 0;
	src = 0;
	n = 0;
	printf("memcpy(dest=%p, src=%p, n=%d)\n", dest, src, n);
	printf("Should return dest\n");
	void *ret = memcpy(dest, src, n); // Works fine
	//void *ret = ft_memcpy(dest, src, n); // Should work fine
	printf("Return val=%p\n", ret);
	*/
}

void    ft_memcpy_test(void)
{
	int	pass;
	void	*dest_std;
	void	*dest_mine;

	pass = 1;
	dest_std = NULL;
	dest_mine = NULL;

	if (!ft_assert(dest_std, dest_mine, (void *) "hello", 5))
		pass = 0;
	if (!ft_assert(dest_std, dest_mine, (void *) "hello world", 11))
		pass = 0;
	if (!ft_assert(dest_std, dest_mine, (void *) "hello world", 2))
		pass = 0;
	if (!ft_assert(dest_std, dest_mine, (void *) "hello world", 20))
		pass = 0;

	ft_test_segfault();

	ft_log_result_test("ft_memcpy", pass);
}

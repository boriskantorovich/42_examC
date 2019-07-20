/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boriskantorovich <boriskantorovich@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 08:05:51 by boriskantor       #+#    #+#             */
/*   Updated: 2019/07/20 08:41:42 by boriskantor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_memory(const void *addr, size_t size);

int		main(void)
{
	int	tab[10] = {0, 23, 150, 255, 12, 16,  21, 42};
	int	tab2[20] = {100, 123, 555, 25545, 1552, 14356,  2431, 100, 123, 555, 25545, 1552, 14356,  2431, 42, 42, __INT_MAX__, 0, __INT_MAX__};

	print_memory(tab, sizeof(tab));
	print_memory(tab2, sizeof(tab2));
	return (0);
}

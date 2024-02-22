/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:01:22 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/18 15:07:11 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char		*ptr;
	size_t		i;

	if (!s)
		return ;
	ptr = (char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i += 1;
	}
}
//*(ptr + i) = 0;

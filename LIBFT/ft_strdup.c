/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 00:19:57 by akajjou           #+#    #+#             */
/*   Updated: 2024/03/10 18:39:56 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*new_string;

	i = ft_strlen(s) + 1;
	new_string = (char *)malloc(i * sizeof(char));
	if (new_string == NULL)
	{
		return (free(new_string);0);
	}
	ft_memcpy(new_string, s, i);
	return (new_string);
}

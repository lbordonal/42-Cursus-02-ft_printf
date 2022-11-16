/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:48:02 by lbordona          #+#    #+#             */
/*   Updated: 2022/11/16 18:17:09 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

int	ft_printf(const char *input, ...)
{
	int	i;
	int	length;
	va_list	args;

	i = 0;
	length = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			length += type_check(args, input[i + 1]);
			i++;
		}
		else
		{
			length += ft_putchar(input[i]);
		}
		i++;
	}
	va_end(args);
	return (length);
}

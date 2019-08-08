/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:40:50 by mfahey            #+#    #+#             */
/*   Updated: 2019/07/30 19:10:27 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*ft_default(t_printf *ft, const char *format)
{
	ft = (t_printf *)malloc(sizeof(t_printf));
	ft->fmt = format;
	ft->i = 0;
	ft->j = 0;
	ft->value = (t_value *)malloc(sizeof(t_value));
	ft->aflag = (char *)malloc(sizeof(char) * 6);
	ft->aflag = "#0- +";
	ft->flag = (t_flag *)malloc(sizeof(t_flag));
	ft->asize = (char *)malloc(sizeof(char) * 7);
	ft->asize = "hljztL";
	ft->atype = (char *)malloc(sizeof(char) * 19);
	ft->atype = "diouxXfFeEgGaAcspn";
	ft_search_deafault(ft);
	return (ft);
}

int			ft_printf(const char *format, ...)
{
	t_printf	*ft;

	ft = ft_default(ft, format);
	va_start(ft->ap, format);
	while (format[ft->i] != '\0')
	{
		while ((format[ft->i] != '\0') && (format[ft->i] != '%'))
		{
			(ft->str)[ft->j] = format[ft->i];
			(ft->i)++;
			(ft->j)++;
		}
		if (format[ft->i] == '%')
		{
			(ft->i)++;
			ft_search(ft);
		}
	}
	va_end(ft->ap);
	(ft->str)[ft->j] = '\0';
	write(1, ft->str, ft->j);
	// printf("%s", ft->str);
	return (ft->j);
}

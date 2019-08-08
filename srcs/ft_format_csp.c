/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_csp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:58:39 by mfahey            #+#    #+#             */
/*   Updated: 2019/08/07 18:03:26 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_p(t_printf *ft)
{
	ft->value->z = va_arg(ft->ap, size_t);
	ft->value->s = ft_ulltoa_base(ft->value->z, 16);
	ft_format_s(ft);
}

void	ft_format_s(t_printf *ft)
{
	if (ft->type == s)
	{
		if (ft->prec)
			ft->length = ft_min(ft_strlen(ft->value->s), ft->precision);
		else
			ft->length = ft_strlen(ft->value->s);
		ft_format_s_frst(ft);
	}
	else
		while ((ft->value->s)[ft->k] != '\0')
		{
			ft_insert_chr(ft, 0, 1, (ft->value->s)[ft->k]);
			(ft->k)++;
		}
}

void	ft_format_c(t_printf *ft)
{
	int		chr;

	if (ft->flag->minus)
	{
		ft_insert_chr(ft, 0, 1, ft->value->c);
		ft_insert_chr(ft, 1, ft->width, ' ');
	}
	else
	{
		chr = ft->flag->zero ? '0' : ' ';
		ft_insert_chr(ft, 1, ft->width, chr);
		ft_insert_chr(ft, 0, 1, ft->value->c);
	}
}

void	ft_format_csp(t_printf *ft)
{
	if (ft->type == c)
	{
		ft->value->c = va_arg(ft->ap, int);
		ft_format_c(ft);
	}
	else if (ft->type == s)
	{
		if (!(ft->value->s = va_arg(ft->ap, char *)))
			ft->value->s = "(null)";
		ft_format_s(ft);
	}
	else if (ft->type == p)
	{
		ft_format_p(ft);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_oux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:59:28 by mfahey            #+#    #+#             */
/*   Updated: 2019/08/08 14:36:25 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_x(t_printf *ft)
{
	size_t	i;

	if (ft->size == ws)
		ft->value->s = ft_ulltoa_base(ft->value->oux, 16);
	else if (ft->size == hh)
		ft->value->s = ft_ulltoa_base(ft->value->hhoux, 16);
	else if (ft->size == h)
		ft->value->s = ft_ulltoa_base(ft->value->houx, 16);
	else if (ft->size == l)
		ft->value->s = ft_ulltoa_base(ft->value->loux, 16);
	else if ((ft->size == ll) || (ft->size == j))
		ft->value->s = ft_ulltoa_base(ft->value->lloux, 16);
	else if (ft->size == z)
		ft->value->s = ft_ulltoa_base(ft->value->z, 16);
	i = 0;
	if (ft->type == X)
		while ((ft->value->s)[i] != '\0')
		{
			(ft->value->s)[i] = ft_toupper((ft->value->s)[i]);
			i++;
		}
	ft->length = ft_strlen(ft->value->s);
	ft_format_x_frst(ft);
}

void	ft_format_u(t_printf *ft)
{
	if (ft->size == ws)
		ft->value->s = ft_ulltoa_base(ft->value->oux, 10);
	else if (ft->size == hh)
		ft->value->s = ft_ulltoa_base(ft->value->hhoux, 10);
	else if (ft->size == h)
		ft->value->s = ft_ulltoa_base(ft->value->houx, 10);
	else if (ft->size == l)
		ft->value->s = ft_ulltoa_base(ft->value->loux, 10);
	else if ((ft->size == ll) || (ft->size == j))
		ft->value->s = ft_ulltoa_base(ft->value->lloux, 10);
	else if (ft->size == z)
		ft->value->s = ft_ulltoa_base(ft->value->z, 10);
	ft->length = ft_strlen(ft->value->s);
	ft_format_u_frst(ft);
}

void	ft_format_o(t_printf *ft)
{
	if (ft->size == ws)
		ft->value->s = ft_ulltoa_base(ft->value->oux, 8);
	else if (ft->size == hh)
		ft->value->s = ft_ulltoa_base(ft->value->hhoux, 8);
	else if (ft->size == h)
		ft->value->s = ft_ulltoa_base(ft->value->houx, 8);
	else if (ft->size == l)
		ft->value->s = ft_ulltoa_base(ft->value->loux, 8);
	else if ((ft->size == ll) || (ft->size == j))
		ft->value->s = ft_ulltoa_base(ft->value->lloux, 8);
	else if (ft->size == z)
		ft->value->s = ft_ulltoa_base(ft->value->z, 8);
	ft->length = ft_strlen(ft->value->s);
	ft_format_o_frst(ft);
}

void	ft_format_oux(t_printf *ft)
{
	if (ft->size == ws)
	{
		ft->value->oux = va_arg(ft->ap, unsigned int);
		ft->z = (ft->value->oux == 0) ? 1 : 0;
	}
	else if (ft->size == hh)
	{
		ft->value->hhoux = (unsigned char)va_arg(ft->ap, unsigned int);
		ft->z = (ft->value->hhoux == 0) ? 1 : 0;
	}
	else if (ft->size == h)
	{
		ft->value->houx = (unsigned short int)va_arg(ft->ap, unsigned int);
		ft->z = (ft->value->houx == 0) ? 1 : 0;
	}
	else if (ft->size == l)
	{
		ft->value->loux = va_arg(ft->ap, unsigned long int);
		ft->z = (ft->value->loux == 0) ? 1 : 0;
	}
	else if ((ft->size == ll) || (ft->size == j))
	{
		ft->value->lloux = va_arg(ft->ap, unsigned long long int);
		ft->z = (ft->value->lloux == 0) ? 1 : 0;
	}
	else if (ft->size == z)
	{
		ft->value->z = va_arg(ft->ap, size_t);
		ft->z = (ft->value->z == 0) ? 1 : 0;
	}
	if (ft->type == o)
		ft_format_o(ft);
	else if (ft->type == u)
		ft_format_u(ft);
	else if ((ft->type == x) || (ft->type == X))
		ft_format_x(ft);
}

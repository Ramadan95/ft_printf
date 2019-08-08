/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <mfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:40:38 by mfahey            #+#    #+#             */
/*   Updated: 2019/08/08 18:06:42 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define STR "\n%4d"
#define C '!'
#define S "YEs"
#define NN 42
#define ULL 18446744073709551615
#define SLLP 9223372036854775807
#define SLLN -9223372036854775808
#define UL 4294967296
#define SLP 2147483647
#define SLN -2147483648

int		main(void)
{
	int		i;
	int		j;

	i = ft_printf(STR, -42);
	j = printf(STR, -42);
	printf("\nft_printf=%i printf=%i", i, j);
}

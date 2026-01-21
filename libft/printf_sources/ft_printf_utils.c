/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:41:27 by cmathot           #+#    #+#             */
/*   Updated: 2024/02/22 15:47:09 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h" 

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		size += ft_putchar((int)str[i]);
		i++;
	}
	return (size);
}

int	ft_putnbr(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (ft_putchar('0'));
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		size += ft_putchar('-');
		return (size + ft_putnbr(n * -1));
	}
	if (n > 9)
		size += (ft_putnbr(n / 10));
	size += ft_putchar((n % 10) + '0');
	return (size);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	unsigned int	size;

	size = 0;
	if (n == 0)
		return (ft_putchar('0'));
	if (n > 9)
		size += (ft_putnbr(n / 10));
	size += ft_putchar((n % 10) + '0');
	return (size);
}

int	ft_putnbr_hexa(int base, unsigned int n)
{
	int	size;

	size = 0;
	if (n >= 16)
	{
		size += ft_putnbr_hexa(base, n / 16);
		n = n % 16;
	}
	if (n < 16)
	{
		if (!base)
			size += ft_putchar("0123456789abcdef"[n]);
		else
			size += ft_putchar("0123456789ABCDEF"[n]);
	}
	return (size);
}

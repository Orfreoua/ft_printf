#include "ft_printf.h"

void	ft_putstr_printf(t_data *data, char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_putchar_printf(data, s[i]);
			i++;
		}
	}
}

void	ft_putnbr_printf(t_data *data, int n)
{
	if (n == -2147483648)
		ft_putstr_printf(data, "-2147483648");
	else if (n == 0)
		ft_putchar_printf(data, '0');
	else if (n < 0)
	{
		ft_putchar_printf(data, '-');
		n = n * -1;
		ft_putnbr_printf(data, n);
	}
	else if (n >= 10)
	{
		ft_putnbr_printf(data, n / 10);
		ft_putchar_printf(data, n % 10 + '0');
	}
	else
		ft_putchar_printf(data, n + '0');
}

void	ft_putnbr_unsigned_printf(t_data *data, unsigned int n)
{
	if (n == 0)
		ft_putchar_printf(data, '0');
	else if (n >= 10)
	{
		ft_putnbr_printf(data, n / 10);
		ft_putchar_printf(data, n % 10 + '0');
	}
	else
		ft_putchar_printf(data, n + '0');
}

void		ft_putnbr_base_printf(t_data *data, long int nbr, char *base)
{
	int		lbase;
	int		error;
	long	nb;

	lbase = 0;
	nb = nbr;
	if (nb < 0)
	{
		ft_putchar_printf(data, '-');
		nb *= -1;
	}
	while (base[lbase])
		lbase++;
	if (nb < lbase)
		ft_putchar_printf(data, base[nb]);
	if (nb >= lbase)
	{
		ft_putnbr_base_printf(data, nb / lbase, base);
		ft_putnbr_base_printf(data, nb % lbase, base);
	}
}

void	ft_putnbr_unsigned_base_printf(t_data *data, unsigned long nbr, char *base)
{
	int				lbase;
	int				error;
	unsigned long	nb;

	lbase = 0;
	nb = nbr;
	if (nb < 0)
	{
		ft_putchar_printf(data, '-');
		nb *= -1;
	}
	while (base[lbase])
		lbase++;
	if (nb < lbase)
		ft_putchar_printf(data, base[nb]);
	if (nb >= lbase)
	{
		ft_putnbr_base_printf(data, nb / lbase, base);
		ft_putnbr_base_printf(data, nb % lbase, base);
	}
}

#include "ft_printf.h"

void	ft_putchar_printf(t_data *data, char c)
{
	data->count_write++;
	write(1, &c, 1);
}

void	open_list(t_data *data, char c)
{
	if (c == 'c')
		ft_putchar_printf(data, va_arg(data->list, int));
	else if (c == 'd' || c == 'i')
		ft_putnbr_printf(data, va_arg(data->list, int));
	else if (c == 's')
		ft_putstr_printf(data, va_arg(data->list, char *));
	else if (c == 'u')
		ft_putnbr_unsigned_printf(data, va_arg(data->list, int));
	else if (c == 'x')
		ft_putnbr_base_printf(data, (va_arg(data->list, int)), "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base_printf(data, (va_arg(data->list, int)), "0123456789ABCDEF");
	else if (c == 'p')
	{
		ft_putstr_printf(data, "0x");
		ft_putnbr_unsigned_base_printf(data, (unsigned long)(va_arg(data->list, void *)), "0123456789abcdef");
	}
	else
		ft_putchar_printf(data, '%');
}

int	find_index(char c, char *index_tab)
{
	int			index;

	index = 0;
	while (index_tab[index])
	{
		if (index_tab[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

int ft_printf(const char *str, ...)
{
	t_data	data;
	int		i;

	data.count_write = 0;
	va_start(data.list, str);
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar_printf(&data, str[i]);
		else if (str[i + 1] &&
			find_index(str[i + 1], "cdispuxX%") != -1)
		{
			open_list(&data, str[i + 1]);
			i++;
		}
		i++;
	}
	return (data.count_write);
}

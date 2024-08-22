#include <stdarg.h>
#include <unistd.h>

int ft_putstr(char *s)
{
	int count = 0;
	if (!s)
		s = "(null)";
	while (*s) {
		count += write(1, s++, 1);
	}
	return count;
}

int ft_putnbr(int nbr, int base)
{
	char *digits = "0123456789abcdef";
	unsigned int n = nbr;
	int count = 0;

	if (base == 10 && nbr < 0) {
		count += write(1, "-", 1);
		n = -nbr;
	}
	if (n >= (unsigned int)base) {
		count += ft_putnbr(n / base, base);
	}
	count += write(1, &digits[n % base], 1);
	return count;
}

int ft_printf(const char *format, ...)
{
	int len = 0;
	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%') {
			format++;
			if (*format == 's')
				len += ft_putstr(va_arg(args, char *));
			else if (*format == 'd')
				len += ft_putnbr(va_arg(args, int), 10);
			else if (*format == 'x')
				len += ft_putnbr(va_arg(args, unsigned int), 16);
		}
		else
			len += write(1, format, 1);
		format++;
	}

	va_end(args);
	return len;
}

#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *format, ... )
{
	va_list(args);
	int len = 0;
	va_start(args, format);

	while(*format)
	{
		if(*format == '%')
		{
			format++;
			if(format == 's')
				len += putstr(va_arg(args, char *));
			else if(*format == 'd')
				len += putnbr(va_arg(args, int), 10);
			else if(*format == 'x')
				len += putnbr(va_arg(args, unsigned int), 16);
		}
		else
			len += write(1, format, 1);
		format++;
	}

	va_end(args);
	return len;
}

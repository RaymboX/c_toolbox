#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;

	va_start(ap, format);
	len = 0;
	i = -1;
	while (format[++i] != '\0')
	{
		if ()
	}




	va_end(ap);
}


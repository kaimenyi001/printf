#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int (*fun)(va_list, char *, unsigned int);
	unsigned int a = 0, len = 0, abuf = 0;
	va_list argts;
	char *bffr;

	va_start(argts, format), bffr = malloc(sizeof(char) * 1024);
	if (!format || !bffr || (format[a] == '%' && !format[a + 1]))
		return (-1);
	if (!format[a])
		return (0);
	for (a = 0; format && format[a]; a++)
	{
		if (format[a] == '%')
		{
			if (format[a + 1] == '\0')
			{
				print_buf(bffr, abuf), free(bffr), va_end(argts);
				return (-1);
			}
			else
			{
				fun = get_print_func(format, a + 1);
				if (fun == NULL)
				{
					if (format[a + 1] == ' ' && !format[a + 2])
						return (-1);
					handl_buf(bffr, format[a], abuf), len++, a--;
				}
				else
				{
					len += fun(argts, bffr, abuf);
					a += ev_print_func(format, a + 1);
				}
			} a++;
		}
		else
			handl_buf(bffr, format[a], abuf), len++;
		for (abuf = len; abuf > 1024; abuf -= 1024)
			;
	}
	print_buf(bffr, abuf), free(bffr), va_end(argts);
	return (len);
}

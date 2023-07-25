#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: void
 */
int _printf(const char *format, ...)
{
	int (*fun)(va_list, char *, unsigned int);
	va_list args;
	unsigned int abuf = 0, a = 0, ln = 0;
	char *bffr;

	va_start(args, format), bffr = malloc(sizeof(char) * 1024);
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
				print_buf(bffr, abuf), free(bffr), va_end(args);
				return (-1);
			}
			else
			{
				fun = get_print_func(format, a + 1);
				if (fun == NULL)
				{
					if (format[a + 1] == ' ' && !format[a + 2])
						return (-1);
					handl_buf(bffr, format[a], abuf), ln++ a--;
				}
				else
				{	
					ln += fun(args, bffr, abuf);
					a += ev_print_func(format, a + 1);
				}
			} a++;
		}
		else
			handl_buf(bffr, format[a], abuf), ln++;
		for (abuf = ln; abuf > 1024; abuf -= 1024)
			;
	}
	print_buf(bffr, abuf), free(bffr), va_end(args);
	return (ln);
}

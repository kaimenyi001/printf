#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
<<<<<<< HEAD
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];
=======
	int (*fun)(va_list, char *, unsigned int);
	unsigned int a = 0, len = 0, abuf = 0;
	va_list argts;
	char *bffr;
>>>>>>> a3034067462b892bf1a935d770a94cc5084d0c62

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
<<<<<<< HEAD
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
=======
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
>>>>>>> a3034067462b892bf1a935d770a94cc5084d0c62
}


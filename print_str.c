#include "main.h"

/**
 * print_str - writes the string to stdout
 * @argts: input string
 * @buf: buffer pointer
 * @abuf: index for buffer pointer
 * Return: On success 1.
 */
int print_str(va_list argts, char *buf, unsigned int abuf)
{
	char *str;
	unsigned int i;
	char nill[] = "(null)";

	str = va_arg(argts, char *);
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			abuf = handl_buf(buf, nill[i], abuf);
		return (6);
	}
	for (i = 0; str[i]; i++)
		abuf = handl_buf(buf, str[i], abuf);
	return (i);
}

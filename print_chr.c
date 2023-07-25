#include "main.h"

/**
 * print_chr - writes the character c to stdout
 * @argts: input char
 * @buf: buffer pointer
 * @abuf: index for buffer pointer
 * Return: On success 1.
 */
int print_chr(va_list argts, char *buf, unsigned int abuf)
{
	char c;

	c = va_arg(argts, int);
	handl_buf(buf, c, abuf);

	return (1);
}

#include "main.h"

/**
 * handl_buf - concats characters
 * @buf: buffer pointer
 * @c: character to concat
 * @abuf: index of buffer pointer
 * Return: void
 */
unsigned int handl_buf(char *buf, char c, unsigned int abuf)
{
	if (abuf == 1024)
	{
		print_buf(buf, abuf);
		abuf = 0;
	}
	buf[abuf] = c;
	abuf++;
	return (abuf);
}

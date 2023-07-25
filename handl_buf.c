#include "main.h"

/**
 * handl_buf - concats characters
 * @buf: buffer pointer
 * @c: character to concat
 * @ibuf: index of buffer pointer
 * Return: void
 */
unsigned int handl_buf(char *buf, char c, unsigned int ibuf)
{
	if (ibuf == 1024)
	{
		print_buf(buf, ibuf);
		ibuf = 0;
	}
	buf[ibuf] = c;
	ibuf++;
	return (ibuf);
}

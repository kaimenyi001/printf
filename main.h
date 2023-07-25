#ifndef MAIN_H_
#define MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct print - struct for printer functions
 * @type_arg: identifier
 * @f: pointer to a printer functions
 *
 * Description: struct that stores pointers to a
 * printer functions.
 */
typedef struct print
{
	char *type_arg;
	int (*f)(va_list, char *, unsigned int);
} print_t;

int _printf(const char *format, ...);
int ev_print_func(const char *s, int index);
unsigned int handl_buf(char *buf, char c, unsigned int abuf);
int print_buf(char *buf, unsigned int nbuf);
int (*get_print_func(const char *s, int index))(va_list, char *, unsigned int);
int print_chr(va_list argts, char *buf, unsigned int abuf);
int print_str(va_list argts, char *buf, unsigned int abuf);

#endif

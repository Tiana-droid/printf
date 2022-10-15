#include "main.h"

/**
 * cs -
 *
 */

char *cs(char c)
{
	char string[1];
	char *p;

	p = string;
	string[0] = c;
	return (p);
}

/**
 * none -
 */

char *none(char c)
{
	char string[3];
	char *p;

	p = string;
	string[0] = '%';
	string[1] = c;
	    string[2] = '\0';
    return (p);
}


/**
 * _printf - custom printf function
 * @format: format string
 * Return: number of characters printed (excluding null byte)
 */

int _printf(const char *format, ...)
{
	int a, len1, len2;
	double buffer;
	double *total;
	va_list argpt;
	char buffer_2[BUFFER_SIZE], *buff;
	char *(*get_op_pt)(va_list);

	if (format == NULL)
		return (-1);
	for (a = 0; a < BUFFER_SIZE; a++)
	{
		buffer_2[a] = 0;
	}
	buffer = 0;
	get_op_pt = NULL;
	total = &buffer;

	va_start(argpt, format);
	for (a =  len1 = len2 = 0; format && format[a]; a++)
	{
		if (format[a] == '%')
		{
			get_op_pt = get_ops(format[a + 1]);
			buff = (get_op_pt == NULL) ? none(format[a + 1]) :
				get_op_pt(argpt);

			len2 = _strlen(buff);
			len1 = memalloc(buff, len2, buffer_2, len1, total);
			a++;
		}
		else
		{
			buff = cs(format[a]);
			len1 = memalloc(buff, 1, buffer_2, len1, total);
		}
	}
	va_end(argpt);
	_putchar(buffer_2, len1);
	return (buffer + len1);


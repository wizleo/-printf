#include "main.h"
/**
  * _printf - function that prints to std
  * @format: character string
  * Return: the number of characters printed
  * excluding the null byte used to end output to strings
  */

int _printf(const char *format, ...)
{
	int count = 0;

	va_list args;
	int i = 0, (*func_select)(va_list);

	va_start(args, format);

	if (format[0] == '%' && format[1] == '\0')
		return (count);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
		}
		else
		{
			if (format[i + 1] == '%')
			{
				count += _putchar('%');
				i++;
			}
			else
			{
				func_select = choice(format[i + 1]);
				if (func_select != NULL)
				{
					count += func_select(args);
					i++;
				}
			}
		}
		i++;
	}
	va_end(args);
	return (count);
}

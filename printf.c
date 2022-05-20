#include "main.h"
/**
  * _printf - function that prints to std
  * @format: character string
  * Return: the number of characters printed
  * excluding the null byte used to end output to strings
  */

int _printf(const char *format, ...)
{
	int i = 0, cnt = 0;
	va_list args;

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%') /* first check */
		{
			_putchar(format[i]);
			cnt++;
		}
		else if (format[i] == '%') /* second check */
		{
			if (format[i + 1] == '%') /* third check */
			{
				_putchar('%');
				cnt++, i++;
			}
			else if (format[i + 1] == 'c') /* fourth check */
			{
				_putchar(va_arg(args, int));
				cnt++, i++;
			}
			else if (format[i + 1] == 's') /* fifth check */
			{
				_prints(va_arg(args, char *));
				cnt++, i++;
			}
			else if (format[i + 1] == 'i' || format[i + 1] == 'd') /* sixth check */
			{
				print_int(va_arg(args, int));
				cnt++, i++;
			}
		}
		i++;
	}
	va_end(args);
	return (cnt);
}

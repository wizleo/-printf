#include "main.h"
/**
  *_putchar - prints characters
  *@c: Character to be printed
  *Return: Always 0 (success)
  */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
  *_prints - prints a string
  *@s: string to be printed
  *Return: nothing
  */
void _prints(char *s)
{
	int j = 0;

	while (s[j] != '\0')
	{
		_putchar(s[j]);
		j++;
	}
}

/**
  *print_int - prints an integer
  *@n: integer to be printed
  *Return: nothing
  */
void print_int(int n)
{
	unsigned int num = n;

	if (n < 0)
	{
		_putchar('-');
		num = -num;
	}
		if ((num / 10) > 0)
			print_int(num / 10);
		_putchar((num % 10) + '0');
}

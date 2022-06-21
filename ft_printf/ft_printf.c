#include "ft_printf.h"

void	ft_printf_va_c(size_t *idx, char c)
{
	write(1, &c, 1);
	*idx += 2;
}

void	ft_printf_va_s(size_t *idx, char *s)
{
	ft_putstr_fd(s, 1);
	*idx += 2;
}

void	print_recursive_hex(size_t addr)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (addr == 0)
		return ;
	print_recursive_hex(addr / 16);
	write(1, &hex[addr % 16], 1);
}

void	ft_printf_va_p(size_t *idx, void *p)
{
	size_t	addr;

	addr = *(size_t *)&p; // size_t 자료형이 테스터기에서 작동하는지 확인 필요
	ft_putstr_fd("0x", 1);
	print_recursive_hex(addr);
	*idx += 2;
}

void	ft_printf_va_d(size_t *idx, int n)
{
	ft_putnbr_fd(n, 1);
	*idx += 2;
}

void	ft_printf_va_i(size_t *idx, int n)
{
	ft_printf_va_d(idx, n);
}

void	ft_printf_recursive_va_u(size_t *idx, unsigned int n)
{
	char	c;

	if (n == 0)
	{
		*idx += 2;
		return ;
	}
	ft_printf_recursive_va_u(idx, n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void	ft_printf_va_u(size_t *idx, unsigned int n)
{
	if (n == 0)
	{
		write(1, "0", 1);
		*idx += 2;
		return ;
	}
	ft_printf_recursive_va_u(idx, n);
}

void	ft_printf_recursive_va_x(size_t *idx, unsigned int n, char c)
{
	char	*hex;

	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n == 0)
	{
		*idx += 2;
		return ;
	}
	ft_printf_recursive_va_x(idx, n / 16, c);
	write(1, &hex[n % 16], 1);
}

void	ft_printf_va_x(size_t *idx, unsigned int n, char c)
{
	if (n == 0)
	{
		write(1, "0", 1);
		*idx += 2;
		return ;
	}
	ft_printf_recursive_va_x(idx, n, c);
}

void	ft_printf_args(char format, size_t *idx, va_list ap)
{
	if (format == 'c')
		ft_printf_va_c(idx, (char)va_arg(ap, int));
	else if (format == 's')
		ft_printf_va_s(idx, (char *)va_arg(ap, int *));
	else if (format == 'p')
		ft_printf_va_p(idx, (void *)va_arg(ap, void *));
	else if (format == 'd')
		ft_printf_va_d(idx, (int)va_arg(ap, int));
	else if (format == 'i')
		ft_printf_va_i(idx, (int)va_arg(ap, int));
	else if (format == 'u')
		ft_printf_va_u(idx, (unsigned int)va_arg(ap, unsigned int));
	else if (format == 'x')
		ft_printf_va_x(idx, (unsigned int)va_arg(ap, unsigned int), 'x');
	else if (format == 'X')
		ft_printf_va_x(idx, (unsigned int)va_arg(ap, unsigned int), 'X');
	else if (format == '%')
	{
		write(1, "%", 1);
		*idx += 2;
	}
}

int	ft_printf(const char *str, ...)
{
	size_t	idx;
	size_t	str_len;
	va_list	ap;
	va_list	ap2;

	idx = 0;
	str_len = ft_strlen(str);
	va_start(ap, str);
	while (idx < str_len && str[idx] != '\0')
	{
		if ((str[idx] == '%') && ft_strchr("cspdiuxX%", str[idx + 1]))
		{
			va_copy(ap2, ap);
			ft_printf_args(str[idx + 1], &idx, ap2);
			va_end(ap2);
		}
		else
		{
			write(1, &str[idx], 1);
			idx += 1;
		}
	}
	va_end(ap);
	return ((int)str_len);
}

int	main(void)
{
	int	num;

	num = 10;
	// 유효성 검사
	/*
		libft strnstr => 문자열 안에서 문자열을 찾는 함수
		구현해야 하는 서식 지정자가 아닌 다른 서식 지정자가 들어오면 프로그램을 종료헌다.
	*/
	// printf("%d %c", 1);			// 이 경우도 마찬가지로 
	// printf("hello %Q", 1234);	// 출력이 되지 않아야 한다.
	// printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	// printf("printf c	: hello %c\n", 'a');
	ft_printf("ft_printf c	: hello %c\n\n", 'a');

	// printf("printf s	: %s\n", "hello 42");
	ft_printf("ft_printf s	: %s\n\n", "hello 42");

	// printf("printf p	: %p\n", &num);
	ft_printf("ft_printf p	: %p\n\n", &num);

	// printf("printf d	: %d\n", num);
	ft_printf("ft_printf d	: %d\n\n", num);

	// printf("printf d	: %d\n", num);
	ft_printf("ft_printf d	: %d\n\n", num);

	// printf("printf i	: %i\n", num);
	ft_printf("ft_printf i	: %i\n\n", num);

	// printf("printf u	: %u\n", 1000);
	ft_printf("ft_printf u	: %u\n\n", 1000);

	// printf("printf x	: %x\n", 2147483647);
	ft_printf("ft_printf x	: %x\n\n", 2147483647);

	// printf("printf X	: %X\n", 2147483647);
	ft_printf("ft_printf X	: %X\n\n", 2147483647);

	// printf("printf percent		: %%\n");
	ft_printf("ft_printf percent	: %%\n\n");
	return (0);
}

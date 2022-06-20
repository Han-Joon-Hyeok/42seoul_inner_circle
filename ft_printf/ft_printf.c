#include "./libft/libft.h"
#include <stdio.h>
#include <stdarg.h>

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

	addr = *(unsigned long *)&p;
	ft_putstr_fd("0x", 1);
	print_recursive_hex(addr);
	*idx += 2;
}

int	ft_printf(const char *str, ...)
{
	size_t	idx;
	size_t	str_len;
	va_list	ap;

	idx = 0;
	str_len = ft_strlen(str);
	va_start(ap, str);
	while (idx < str_len && str[idx] != '\0')
	{
		if (ft_strnstr(&str[idx], "%c", 2))
		{
			ft_printf_va_c(&idx, (char)va_arg(ap, int));
		}
		else if (ft_strnstr(&str[idx], "%s", 2))
		{
			ft_printf_va_s(&idx, (char *)va_arg(ap, int *));
		}
		else if (ft_strnstr(&str[idx], "%p", 2))
		{
			ft_printf_va_p(&idx, (void *)va_arg(ap, void *));
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
	// printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("printf c	: hello %c\n", 'a');
	ft_printf("ft_printf c	: hello %c\n", 'a');

	printf("printf s	: %s\n", "hello 42");
	ft_printf("ft_printf s	: %s\n", "hello 42");

	printf("printf p	: %p\n", &num);
	ft_printf("ft_printf p	: %p\n", &num);
	return (0);
}

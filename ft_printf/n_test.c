#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    ft_printf("123%10%6789\n"); // 123456789
    ft_printf("12345%10%6789\n"); // 123456789
    ft_printf("1%10%6789\n"); // 16789
}
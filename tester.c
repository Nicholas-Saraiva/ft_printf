#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int ret_ft_printf;
    int ret_printf;

    ret_ft_printf = ft_printf("%x\n", 250);
    ret_printf = printf("%x\n", 250);
    printf("ft_printf returned: %d\n", ret_ft_printf);
    printf("printf returned: %d\n", ret_printf);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    return (0);
}

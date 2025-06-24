#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int ret_ft_printf;
    int ret_printf;

    ret_ft_printf = ft_printf("%7.5s\n", "yolo");
    ret_printf = printf("%7.5s\n", "yolo");
    printf("ft_printf returned: %d\n", ret_ft_printf);
    printf("printf returned: %d\n", ret_printf);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    ret_ft_printf = ft_printf("%-32s\n", "abc");
    ret_printf = printf("%-32s\n", "abc");
    printf("ft_printf returned: %d\n", ret_ft_printf);
    printf("printf returned: %d\n", ret_printf);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    ret_ft_printf = ft_printf("%7.5s\n", "bombastic");
    ret_printf = printf("%7.5s\n", "bombastic");
    printf("ft_printf returned: %d\n", ret_ft_printf);
    printf("printf returned: %d\n", ret_printf);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    ret_ft_printf = ft_printf("%-30s\n", (char *)NULL);
    ret_printf = printf("%-30s\n", (char *)NULL);
    printf("ft_printf returned: %d\n", ret_ft_printf);
    printf("printf returned: %d\n", ret_printf);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    ret_ft_printf = ft_printf("%c\n", 0);
    ret_printf = printf("%c\n", 0);
    printf("ft_printf returned: %d\n", ret_ft_printf);
    printf("printf returned: %d\n", ret_printf);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    ret_ft_printf = ft_printf("%.s\n", 0);
    ret_printf = printf("%.s\n", 0);
    printf("ft_printf returned: %d\n", ret_ft_printf);
    printf("printf returned: %d\n", ret_printf);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    ret_ft_printf = ft_printf("%-3.s\n", 0);
    ret_printf = printf("%-3.s\n", 0);
    printf("ft_printf returned: %d\n", ret_ft_printf);
    printf("printf returned: %d\n", ret_printf);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    ret_ft_printf = ft_printf("%3.6s\n", 0);
    ret_printf = printf("%3.6s\n", 0);
    printf("ft_printf returned: %d\n", ret_ft_printf);
    printf("printf returned: %d\n", ret_printf);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

	ret_ft_printf = ft_printf("%p\n", NULL);
    ret_printf = printf("%+p\n", NULL);
    printf("ft_printf returned: %d\n", ret_ft_printf);
    printf("printf returned: %d\n", ret_printf);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

	ret_ft_printf = ft_printf("%d\n", 0);
    ret_printf = printf("%d\n", 0);
    printf("ft_printf returned: %d\n", ret_ft_printf);
    printf("printf returned: %d\n", ret_printf);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

	ret_ft_printf = ft_printf("%.5d\n", 2);
    ret_printf = printf("%.5d\n", 2);
    printf("ft_printf returned: %d\n", ret_ft_printf);
    printf("printf returned: %d\n", ret_printf);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

	ret_ft_printf = ft_printf("%07d\n", -54);
    ret_printf = printf("%07d\n", -54);
    printf("ft_printf returned: %d\n", ret_ft_printf);
    printf("printf returned: %d\n", ret_printf);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

	ret_ft_printf = ft_printf("%7d\n", -54);
    ret_printf = printf("%7d\n", -54);
    printf("ft_printf returned: %d\n", ret_ft_printf);
    printf("printf returned: %d\n", ret_printf);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

	ret_ft_printf = ft_printf("%-8.3d\n", -84730);
    ret_printf = printf("%-8.3d\n", -84730);
    printf("ft_printf returned: %d\n", ret_ft_printf);
    printf("printf returned: %d\n", ret_printf);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

	ret_ft_printf = ft_printf("%8.5d\n", 34);
    ret_printf = printf("%8.5d\n", 34);
    printf("ft_printf returned: %d\n", ret_ft_printf);
    printf("printf returned: %d\n", ret_printf);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");



    return (0);
}

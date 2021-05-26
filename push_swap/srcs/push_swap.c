/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 08:29:37 by okim              #+#    #+#             */
/*   Updated: 2021/05/26 09:27:34 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len] != '\0')
        len++;
    return (len);
}

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    else
        return (-1);
}

int char_to_int(char *str)
{
    int idx;
    int rtn;
    int sign;

    rtn = 0;
    sign = 1;
    idx = 0;
    if (str[idx] == '-')
    {
        sign = -1;
        idx++;
    }
    while (idx < ft_strlen(str))
    {
        if (is_digit(str[idx]) != -1 || (rtn < 214748364 && is_digit(str[idx]) <= 7)) // 최대, 최소 정수인 경우 0이 나오는지 확인
            rtn = rtn * 10 + is_digit(str[idx]);
        else
            return (0);
        idx++;
    }
    return (sign * rtn);
}

int main()
{
    int rtn1 = char_to_int("-123456789");
    int rtn2 = char_to_int("123456789");
    int rtn3 = char_to_int("0");
    int rtn4 = char_to_int("2147483648");
    printf("%d\n%d\n%d\n%d\n", rtn1, rtn2, rtn3, rtn4); // 정수 입력 처리가 끝나면 main에서의 인자에 따라 스택이 제대로 저장되는지 확인, 이후에 스택을 활용한 정렬방법 검색(최소 횟수 정렬)
    // int     *a;
    // int     *b;
    // int     idx;
    
    // a = (int *)malloc(sizeof(int) * argc);
    // b = (int *)malloc(sizeof(int) * argc);
    // idx = 0;
    // while (idx < argc)
    // {
    //     if ((a[idx] = char_to_int(argv[idx])) == 0)
    //     {
    //         write(2, "error\n", 6);
    //         exit;
    //     }
    //     idx++;
    // }
    // free (a);
    // free (b);
    // printf("push_swap is working");
    return (0);
}
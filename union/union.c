/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 20:04:42 by drina             #+#    #+#             */
/*   Updated: 2020/07/28 20:04:44 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int     check(char *str, char c, int len)
{
    int count;
    
    count = 0;
    while (count < len)
    {
        if (str[count] == c)
            return (0);
        count++;
    }
    return (1);
}

void    ft_union(char *str1, char *str2)
{
    int i;
    int len;

    i = 0;
    
    while (str1[i])
    {
        if ((check(str1, str1[i], i)) == 1)
            write(1, &str1[i], 1);
        i++;
    }
    len = i;
    i = 0;
    while (str2[i])
    {
        if ((check(str2, str2[i], i)) == 1)
        {
            if ((check(str1, str2[i], len)) == 1)
                write(1, &str2[i], 1);
        }
        i++;
    }
}

int     main(int argc, char **argv)
{
    if (argc == 3)
        ft_union(argv[1], argv[2]);
    write(1, "\n", 1);
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:52:32 by drina             #+#    #+#             */
/*   Updated: 2020/07/28 18:52:35 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int     check(char *str, char c, int len)
{
    int count = 0;
    
    while (count < len)
    {
        if (str[count] == c)
            return (0);
        count++;
    }
    return (1);
}

void    inter(char *str1, char *str2)
{
    int i, j;
    
    i = 0;
    while (str1[i])
    {
        if ((check(str1, str1[i], i)) == 1)
        {
            j = 0;
            while (str2[j])
            {
                if (str1[i] == str2[j])
                {
                    write(1, &str1[i] ,1);
                    break ;
                }
                j++;
            }
        }
        i++;
    }
}

int     main(int argc, char **argv)
{
    
    if (argc == 3)
        inter(argv[1], argv[2]);
    write(1, "\n" ,1);
    return (1);
}

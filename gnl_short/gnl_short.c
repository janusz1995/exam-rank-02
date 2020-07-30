/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_short.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 13:23:13 by drina             #+#    #+#             */
/*   Updated: 2020/07/28 16:11:07 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int     ft_strlen(char *str)
{
    int count = 0;
    while (str[count] != '\0')
        count++;
    return (count);
}

char    *strjoin(char *str, char c)
{
    int count;
    char *list;
    count = 0;
    list = (char*)malloc((ft_strlen(str) + 2) * sizeof(char));
    while (str[count] != '\0')
    {
        list[count] = str[count];
        count++;
    }
    list[count++] = c;
    list[count] = '\0';
    return (list);
}


int     get_next_line(char **line)
{
    char list[2];
    char *tmp;
    int count;
    
    *line = NULL;
    list[1] = '\0';

    *line = (char*)malloc(1 * sizeof(char));
    line[0] = '\0';
    while ((count = read(0, list, 1)) > 0)
    {
        if (list[0] == '\n')
            return (1);
        tmp = *line;
        *line = strjoin(*line,  list[0]);
        free(tmp);
        tmp = NULL;
    }
    if (count == -1)
    {
        free(*line);
        *line = NULL;
        return (-1);
    }
    return (0);
}

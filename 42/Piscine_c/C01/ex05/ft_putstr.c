/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elghouai <elghouai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:40:08 by elghouai          #+#    #+#             */
/*   Updated: 2022/06/24 12:59:21 by elghouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void        ft_putstr(char *str){
    int i=0;
    while(str[i]!='\0'){
    write(1,&str[i],1);
    i++;
    }
}
int         main(){
    ft_putstr("Bonjour");
    }
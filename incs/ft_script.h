/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <mmostafa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 12:16:40 by mmostafa          #+#    #+#             */
/*   Updated: 2020/12/12 17:15:15 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCRIPT_H
#define FT_SCRIPT_H

#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_grantpt(int fd);
int		ft_unlockpt(int fd);
int		ft_openpt(int flags);
int		ft_ptsname(int fd, const char pts_name[]);

#endif
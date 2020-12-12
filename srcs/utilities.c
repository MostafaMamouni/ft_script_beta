/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <mmostafa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:44:04 by mmostafa          #+#    #+#             */
/*   Updated: 2020/12/05 17:46:46 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

int		ft_grantpt(int fd)
{
	return ioctl(fd, TIOCPTYGRANT);
}

int ft_unlockpt(int fd)
{
	return ioctl(fd, TIOCPTYUNLK);
}

int		ft_openpt(int flags)
{
	return open("/dev/ptmx", flags);
}

int		ft_ptsname(int fd, const char pts_name[])
{
	struct stat sbuf;

	if (ioctl(fd, TIOCPTYGNAME, pts_name) == - 1 || stat(pts_name, &sbuf) == -1)
		return -1;
	return 0;
}
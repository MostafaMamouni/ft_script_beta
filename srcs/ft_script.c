/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <mmostafa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:45:52 by mmostafa          #+#    #+#             */
/*   Updated: 2020/12/12 17:48:36 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

int main(int ac, char **av)
{
	int			master_fd = -1;
	(void)ac;
	char input[150];
	int ret;
	const char	slave_name[128];
	int tf_fd = open("ft_typescript", O_RDWR | O_CREAT); 
	
	if ((master_fd = ft_openpt(O_RDWR)) == -1)
		perror("ft_openpt: ");
	if (ft_unlockpt(master_fd) == -1)
		perror("ft_unlochpt: ");
	if (ft_grantpt(master_fd) < -1)
		perror("ft_grantpt: ");
	if (ft_ptsname(master_fd, slave_name) == -1)
		perror("ft_ptsname: ");
	int		slave_fd = open(slave_name, O_RDWR);
	int cpid = fork();
	if (cpid > 0)
	{
		fd_set fd_in;
		close(slave_fd);
		while (1)
		{
			FD_ZERO(&fd_in);
			FD_SET(0, &fd_in);
			FD_SET(master_fd, &fd_in);

			ret = select(master_fd + 1, &fd_in, NULL, NULL, NULL);
			if (ret == -1)
			{
				fprintf(stderr, "Error %d on select()\n", errno);
                exit(1);
			}
			if (FD_ISSET(0, &fd_in))
			{
				ret = read(0, input, sizeof(input));
				if (ret > 0)
					write(master_fd, input, sizeof(input) - 1);
				else if (ret < 0)
				{
					fprintf(stderr, "Error %d on read standard input\n", errno);
                	exit(1);
				}	
			}
			if (FD_ISSET(master_fd, &fd_in))
			{
				ret = read(master_fd, input, sizeof(input));
				if (ret > 0)
				{
					write(1, input, ret);
					write(tf_fd, input, ret);
				}
				else if (ret < 0)
				{
					fprintf(stderr, "Error %d on read master PTY\n", errno);
					exit(1);
				}
				
			}
		}
	}
	else
	{
		struct termios slave_orig_term_settings;
		struct termios new_term_settings;

		close(master_fd);

		ret = tcgetattr(slave_fd, &slave_orig_term_settings);
		new_term_settings = slave_orig_term_settings;
		cfmakeraw(&new_term_settings);
		tcsetattr(slave_fd, TCSANOW, &new_term_settings);
		
		close(0);
		close(1);
		close(2);
		
		dup(slave_fd);
		dup(slave_fd);
		dup(slave_fd);
	
	    close(slave_fd);

    	setsid();

	    ioctl(0, TIOCSCTTY, 1);
      	ret = execvp(av[1], &av[1]);
    }
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:38:12 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/18 14:09:05 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_line(char *line)
{
	char	*cur_line_end;
	char	*next_line;

	cur_line_end = ft_strchr2(line, '\n');
	if (!cur_line_end)
		return (NULL);
	next_line = ft_strdup2(cur_line_end + 1);
	*(cur_line_end + 1) = '\0';
	return (next_line);
}

char	*get_1line_4buf(char *buf, int fd)
{
	char	tmp[BUFFER_SIZE + 1];
	int		read_bytes;

	while (!ft_strchr2(buf, '\n'))
	{
		read_bytes = read(fd, tmp, BUFFER_SIZE);
		if (read_bytes < 1)
			break ;
		tmp[read_bytes] = '\0';
		buf = ft_strjoin2(buf, tmp);
	}
	if (read_bytes == -1)
	{
		free(buf);
		buf = NULL;
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	line = get_1line_4buf(buf, fd);
	if (!line)
	{
		buf = NULL;
		return (NULL);
	}
	buf = next_line(line);
	return (line);
}

/*
int	main()
{
	char	*fname = "sample.txt";
	char	buf[BUFFER_SIZE];
	char	*buf2;
	int		i;
	int	fd = open("sample.txt", O_RDONLY);
	buf2 = get_next_line(fd);
	printf("%s\n",buf2);
	buf2 = get_next_line(fd);
	printf("%s\n",buf2);
	
	char *line1 = "Hello\nWorld";

	if (fd < 0)
		printf("error\n");
	else
	{
		printf("filename = %s, Descriptor = %d\n", fname, fd);
		buf2 = get_next_line(fd);
		while (buf2)
		{
			i = 0;
			while (buf2[i])
				printf("%c", buf2[i++]);
			free(buf2);
			buf2 = get_next_line(fd);
			printf("\n");
		}
		//read(fd, buf, BUFFER_SIZE);
		//printf("%s\n",buf);
		close(fd);		
	}
	return (0);
}*/

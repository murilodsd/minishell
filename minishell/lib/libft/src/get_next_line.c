/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:37:07 by mde-souz          #+#    #+#             */
/*   Updated: 2024/08/30 10:35:28 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Frees memory allocated for a buffer and a pointer.
 *
 * This function frees the memory allocated for a buffer and a pointer.
 * If the buffer is NULL,it calls the ft_free_ptr_buffer function
 * to free all the pointer in a the buffer.
 * Otherwise, it frees just one pointer in the buffer and sets it to NULL. 
 * It also frees the pointer ptr if it is not NULL.
 * Set the global variable errno
 *
 * @param buffer The address of the pointer in the buffer to be freed.
 * @param ptr The pointer to be freed.
 * @param erro_num The error number to be set.
 * @return NULL.
 */
static void	*ft_free_memmory(char **buffer, char *ptr, int erro_num)
{
	errno = erro_num;
	if (buffer != NULL && erro_num == 0)
	{
		free(*buffer);
		*buffer = NULL;
	}
	else
		ft_free_ptr_buffer(buffer, MAX_FD);
	if (ptr)
		free(ptr);
	return (NULL);
}

static void	*ft_insert_into_line(char **line, char *buffer)
{
	size_t	s_cat;
	size_t	s_buffer_cat;
	char	*tmp;
	int		i;

	s_buffer_cat = ft_strlen(buffer);
	if (ft_strchr(buffer, '\n'))
		s_buffer_cat += 1 - ft_strlen(ft_strchr(buffer, '\n'));
	s_cat = ft_strlen(*line) + s_buffer_cat;
	if (!s_cat)
		return (*line);
	tmp = *line;
	*line = (char *)ft_calloc(sizeof(char), s_cat + 1);
	if (!*line)
		return (ft_free_memmory(NULL, tmp, ENOMEM));
	ft_strcpy(*line, tmp);
	free(tmp);
	i = 0;
	while ((*line)[i])
		i++;
	while (*buffer && *buffer != '\n')
		(*line)[i++] = *buffer++;
	(*line)[i] = *buffer;
	return (*line);
}

static void	ft_move_buffer(char *buffer)
{
	char	*endoftheline;
	int		i;

	endoftheline = ft_strchr(buffer, '\n');
	if (!endoftheline)
		ft_memset(buffer, '\0', BUFFER_SIZE + 1);
	else
	{
		i = 0;
		while (endoftheline[1 + i])
			*buffer++ = endoftheline[1 + i++];
		while (*buffer)
			*buffer++ = '\0';
	}
}

static int	check_buffer_and_fd(char **buffer, int fd)
{
	if (fd == -1)
	{
		ft_free_ptr_buffer(buffer, MAX_FD);
		return (0);
	}
	if (fd < -1 || fd > MAX_FD || BUFFER_SIZE <= 0)
	{
		errno = EINVAL;
		return (0);
	}
	if (!buffer[fd])
		buffer[fd] = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer[fd])
	{
		errno = ENOMEM;
		ft_free_ptr_buffer(buffer, MAX_FD);
		return (0);
	}
	return (1);
}

/**
 * @brief Reads the next line from a file descriptor.
 *
 * This function reads the next line from the file descriptor specified by `fd`.
 * It uses a static buffer to store the data read from the file, allowing it to
 * handle multiple file descriptors simultaneously. The function returns the
 * next line as a dynamically allocated string.
 *
 * @param fd The file descriptor to read from. 
 * If fd = -1, the function just free the buffer;
 * @return A pointer to the next line
 * NULL if there is nothing to read (EOF).
 * NULL and set errno if an error occurred.
 */
char	*get_next_line(int fd)
{
	ssize_t		bytes_read;
	static char	*buffer[MAX_FD];
	char		*line;

	if (!check_buffer_and_fd(buffer, fd))
		return (NULL);
	line = (char *)ft_calloc(sizeof(char), 1);
	if (!line)
		return (ft_free_memmory(NULL, NULL, ENOMEM));
	if (!ft_insert_into_line(&line, buffer[fd]))
		return (ft_free_memmory(NULL, NULL, ENOMEM));
	ft_move_buffer(buffer[fd]);
	while (!ft_strchr(line, '\n'))
	{
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read == 0 && *line != '\0')
			return (line);
		else if (bytes_read == 0 || bytes_read == -1)
			return (ft_free_memmory(&buffer[fd], line, errno));
		if (!ft_insert_into_line(&line, buffer[fd]))
			return (ft_free_memmory(NULL, NULL, ENOMEM));
		ft_move_buffer(buffer[fd]);
	}
	return (line);
}
/* #include <fcntl.h>
#include <stdio.h>
#include <strings.h>

int main(void)
{
	int	fd1,fd2;
	char	*line;
	
 	//fd0 = open("read_error.txt", O_RDWR);
 	//fd2 = open("lines_around_10.txt", O_RDWR);
	//printf("%s",get_next_line(fd0));
	//printf("%s",get_next_line(fd2));
	//printf("%s",get_next_line(fd0));
	//printf("%s",get_next_line(fd2));

	fd1 = open("../../../README.md", O_RDWR);
	fd2 = open("ft_strtrim.c", O_RDWR);
	line = get_next_line(fd1);
	printf("%s",line);
	free(line);
	line = get_next_line(fd1);
	printf("%s",line);
	free(line);
	line = get_next_line(fd1);
	printf("%s",line);
	free(line);
	line = get_next_line(fd1);
	printf("%s",line);
	free(line);
	line = get_next_line(fd1);
	printf("%s",line);
	free(line);
	line = get_next_line(fd2);
	printf("%s",line);
	free(line);
	line = get_next_line(fd2);
	printf("%s",line);
	free(line);
	line = get_next_line(fd2);
	printf("%s",line);
	free(line);
	//printf("%s",get_next_line(fd));
	//printf("%s",get_next_line(fd));
	//printf("%s",get_next_line(fd));
	//printf("%s",get_next_line(fd));
	//bzero(buffer,BUFFER_SIZE + 1);
 	//bytes_read = read(fd,buffer,BUFFER_SIZE);
	//ft_insert_into_line(&line,buffer);
	//ft_move_buffer(buffer);
	//printf("Linha:\n%s", line);
	//printf("buffer:\n%s\n", buffer);
	//printf("%s\n",buffertoline(buffer,line));
	//next_line = buffertoline(buffer,&line);
	//printf("%s",line);
	//bytes_read = read(fd,buffer,BUFFER_SIZE);
	//buffertoline(buffer,&next_line);
	//printf("%s",next_line);
	//printf("%li\n",bytes_read);
	//bytes_read = read(fd,buffer,32);
	//printf("%s\n",buffer);
	//printf("%li\n",bytes_read);
	//close(fd0);
	close(fd1);
	close(fd2);
	return 0;
} */
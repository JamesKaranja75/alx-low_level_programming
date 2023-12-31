#include "main.h"

/**
 * append_text_to_file - A function that appends text at the end of a file
 * @filename: The name of the filename
 * @text_content: The NULL terminated string to add at the end of the file
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
int fd;
ssize_t result;

if (!filename)
return (-1);

fd = open(filename, O_WRONLY | O_APPEND);

if (fd == -1)
return (-1);

if (!text_content)
{
close(fd);
return (1);
}

result = write(fd, text_content, strlen(text_content));
if (result == -1 || result != (ssize_t)strlen(text_content))
{
close(fd);
return (-1);
}

close(fd);
return (1);
}

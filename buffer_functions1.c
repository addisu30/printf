#include <unistd.h>
#include "main.h"
#include <stdio.h>
/**
 * _flush - Fill the buffer with decimal notation \0
 * @buffer: buffer for the flush
 * The length of the buffer is defned in a macro
 * Return: Always 0.
 */
char *_flush(char *buffer)
{
int i;

for (i = 0; i < BUF_LENGTH; ++i)
buffer[i] = '\0';
return (buffer);
}


/**
 * fill_buffer - fills the buffer with string s conversions
 * @buffer: buffer with strings int
 * @s: a string to fill buffer with string
 * @count_c: number of chars put in buffer before s
 * IMPORTANT: update count_c in printf only after filling the buffer, I need to
 * know here at which index I can start to append to the buffer
 * @s_length: length of string, not required, but if I have it rigth away
 * in printf I might just pass it instead of calling strlen here
 * Fills the buffer starting at index count_c with string s of length s_length
 * Return: Always 0.
 */
char *fill_buffer(char *buffer, const char *s, int count_c, int s_length)
{
int i, buffer_index;

i = 0;
buffer_index = (count_c > BUF_LENGTH) ? count_c % BUF_LENGTH : count_c;
while (i < s_length)
{
if (buffer_index == BUF_LENGTH)
{
print_buffer(buffer, BUF_LENGTH);
buffer = _flush(buffer);
buffer_index = 0;
}
buffer[buffer_index] = s[i];
++i;
++buffer_index;
}
if (buffer_index == BUF_LENGTH)
{
print_buffer(buffer, BUF_LENGTH);
buffer = _flush(buffer);
}
return (buffer);
}

/**
 * print_buffer - prints the buffer array for decimal conversion
 * @buffer: a buffer, char array
 * @length: number of characters I need to print
 *
 * Return: Always 0.
 */
void print_buffer(char *buffer, int length)
{

if (length > BUF_LENGTH)
length = length % BUF_LENGTH;
write(1, buffer, length);
}

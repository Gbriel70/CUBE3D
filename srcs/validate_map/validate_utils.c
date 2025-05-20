#include "cube.h"

int is_empty_line(char *line)
{
	int index;

	index = 0;
	while (line[index])
	{
		if (line[index] != ' ' && line[index] != '\t' && line[index] != '\n'
			&& line[index] != '\r' && line[index] != '\v' && line[index] != '\f')
				return (FALSE);
		index++;
	}
	return (TRUE);
}

void replace_char(char *str, char old, char new)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (str[index] == old)
			str[index] = new;
		index++;
	}
}
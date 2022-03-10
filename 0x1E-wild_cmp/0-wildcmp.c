#include "holberton.h"

char *find_string(char *s1, char *s2);

/**
 * check_ahead - test if string exist in located position
 * @crnt1: position to compare
 * @crnt2: string to find
 * @orig1: original position found
 * @orig2: original position to find
 *
 * Return: position or 0
 */
char *check_ahead(char *crnt1, char *crnt2, char *orig1, char *orig2)
{
	if (crnt2[0] == '*' || (!crnt1[0] && !crnt2[0]))
		return (orig1);
	else if (crnt1[0] != crnt2[0])
		return (find_string(crnt1, orig2));
	else
		return (check_ahead(crnt1 + 1, crnt2 + 1, orig1, orig2));
}

/**
 * find_string - check if next string exist
 * @s1: string to look into
 * @s2: string to find
 *
 * Return: position of string
 */
char *find_string(char *s1, char *s2)
{
	if (s1[0] != s2[0])
	{
		if (!s1[0])
			return (0);
		return (find_string(s1 + 1, s2));
	}
	return (check_ahead(s1 + 1, s2 + 1, s1, s2));
}

/**
 * wildcmp - compare two strings
 * @s1: string to compare
 * @s2: string to compare and can contain the special character *
 *
 * Return: 1 if the string are identical otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{
	char *pos;

	if (s2[0] == '*' && !s2[1])
		return (1);
	else if (s2[0] == '*' && s2[1] == '*')
		return (wildcmp(s1, s2 + 1));
	else if (s2[0] == '*')
	{
		pos = find_string(s1, s2 + 1);
		if (pos == 0)
			return (0);
		return (wildcmp(pos + 1, s2 + 2));
	}
	else if (s1[0] != s2[0])
		return (0);
	if (!s1[0] && !s2[0])
		return (1);

	return (wildcmp(s1 + 1, s2 + 1));
}

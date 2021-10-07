#include "menger.h"

/**
 * menger - A function that draws a 2D Menger Sponge
 * @level: is the level of the Menger Sponge to draw
 */
void menger(int level)
{
	int i, j, x, y, c, size;

	if (level >= 0)
	{
		size = pow(3, level);
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size;)
			{
				c = '#';
				x = i;
				y = j++;
				while (x > 0 || y > 0)
				{
					if (x % 3 == 1 && y % 3 == 1)
						c = ' ';
					x /= 3;
					y /= 3;
				}
				putchar(c);
			}
			putchar('\n');
		}
	}
}

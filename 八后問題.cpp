#include <stdio.h>
#include <stdlib.h>

void place_queen (int i, int queen_pos[8])
{
	int j, k, conflict;
	if (i == 8)
	{
		for (k = 0; k < 8; k++)
			printf ("%d", queen_pos[k]);
		printf ("\n");
		return;	
	}
	for (k = 0; k < 8; k++)
	{
		conflict = 0;
		for (j = 0; j < i && !conflict; j++)
			if (queen_pos[j] == k ||
				abs(k - queen_pos[j]) == (i - j))
				conflict = 1;
		if (!conflict)
		{
			queen_pos[i] = k;
			place_queen(i + 1, queen_pos);
		}
	}
}

int main ()
{
	int queen_pos[8];
	place_queen(0, queen_pos);
	return 0;
}


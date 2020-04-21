#include "justine.h"

void cyan()
{
	printf("\x1B[36m");
}
void magenta()
{
	printf("\x1B[35m");
}

void blue()
{
	printf("\x1B[34m");
}

void green()
{
	printf("\x1B[32m");
}
void red()
{
	printf("\033[1;31m");
}

void yellow()
{
	printf("\033[1;33m");
}

void reset() {
  printf("\033[0m");
}

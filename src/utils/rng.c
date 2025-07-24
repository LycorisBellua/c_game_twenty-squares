#include <sys/time.h>

int	generate_seed(void)
{
	struct timeval	curr_time;

	if (gettimeofday(&curr_time, 0) < 0)
		return (42);
	return (curr_time.tv_usec);
}

/* Simple 32-bit Xorshift pseudo-RNG */
int	rng_minmax(int *seed, int min, int max)
{
	unsigned int	random;

	if (!*seed)
		*seed = 1;
	random = *seed;
	random ^= random << 13;
	random ^= random >> 17;
	random ^= random << 5;
	*seed = random;
	return (random % (max - min + 1) + min);
}

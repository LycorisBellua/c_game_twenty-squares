#include <sys/time.h>

static int	generate_seed(void);

/* Simple 32-bit Xorshift pseudo-RNG */
int	rng_minmax(int min, int max)
{
	static int		seed;
	static int		is_seed_generated;
	unsigned int	random;

	if (!is_seed_generated)
	{
		seed = generate_seed();
		is_seed_generated = 1;
	}
	if (!seed)
		seed = 1;
	random = seed;
	random ^= random << 13;
	random ^= random >> 17;
	random ^= random << 5;
	seed = random;
	return (random % (max - min + 1) + min);
}

static int	generate_seed(void)
{
	struct timeval	curr_time;

	if (gettimeofday(&curr_time, 0) < 0)
		return (42);
	return (curr_time.tv_usec);
}

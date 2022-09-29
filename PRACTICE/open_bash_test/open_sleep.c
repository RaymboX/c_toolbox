#include <unistd.h>
#include <errno.h>

int	main(void)
{
	write(1, "hi1\nhi2\n", 8);
	write(10, "10\n", 3);
	write(11, "11\n", 3);
	write(12, "12\n", 3);
	return (errno);
}

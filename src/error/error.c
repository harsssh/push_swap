#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "error.h"

void	exit_with_message(void)
{
	ft_putstr_fd(ERR_MSG, STDERR_FILENO);
	exit(1);
}
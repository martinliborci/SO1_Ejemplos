// Using fork and exec Together
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int spawn (char* program, char** arg_list)
{
	pid_t child_pid;

	/* Duplicate this process. */
	child_pid = fork ();

	if (child_pid != 0) {
		return child_pid;
	}
	else {
		execvp (program, arg_list);
		/* returns only if an error occurs. */
		fprintf (stderr, "an error occurred in execvp\n");
		abort ();
	}
}


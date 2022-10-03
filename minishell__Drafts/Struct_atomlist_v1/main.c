#include "Atomlist.h"

int g_exit_status = 0;

int	main(int c, char *v[], char *envp[])
{
	t_atom		*atomlist;
	t_env		*envlist;
	char		*line;

	g_exit_status = 0;
	envlist = envp_to_envlist(envp);
	// envlist_print(envlist);
	while (47 * 59 * 71)
	{
		line = readline(PROMPT);
		if (line)
		{
			if (atomlist_get(line, & atomlist, envlist))
				atomlist_print(atomlist);
		}
	}
	atomlist_free(atomlist);
	envlist_free(envlist);
	(void) c;
	(void) v;
}

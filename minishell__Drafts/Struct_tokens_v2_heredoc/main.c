#include "v6.h"

int g_exit_status = 0;

int	main(int c, char *v[], char *envp[])
{
	t_token		*tokenlist;
	t_atom		*atomlist;
	t_env		*envlist;
	char		*line;

	//handle_signal(READLINE); // New . READLINE is 0

	g_exit_status = 0;
	envlist = envp_to_envlist(envp);

	// envlist_print(envlist);		// printer debugger 1
	// print_char_star_array(envlist_to_arr(envlist)); // printer debugger 2

	//atomlist = null; // to not SEGV, nullify inside while
	tokenlist = null;
	while (1)
	{
		line = readline(PROMPT);
		print_input(line);
		if (!slen(line))
			continue ;
		print("here :) \n");
		add_history(line);

		// atom
		atomlist = null; // to not SEGV, nullify alst here
		if (atomlist_get(line, & atomlist, envlist))
			print_atomlist(atomlist);

		// token
		if (tokenlist_get(& tokenlist, atomlist, envlist))
			print_tokenlist(tokenlist);

		// heredoc
		if (heredoc_1st_layer(tokenlist))
			print( color2 "heredoc ok. :D " noc nl2);
		else
			print( color2 "heredoc fails. xD " noc nl2);



		// cleanup
		if (tokenlist)
		{
			heredoc_unlink(tokenlist);
			tokenlist_free(tokenlist);
			tokenlist = null;
		}
	}
	envlist_free(envlist); // we only need to free the environ list
	(void) c;
	(void) v;

	//atomlist_free(atomlist);
	//tokenlist_free(tokenlist);
	//(void) tokenlist;
}

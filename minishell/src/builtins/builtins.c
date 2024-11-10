#include "../../includes/builtins.h"

void	builtins(void)
{
	printf("Builtins:\n");
	cd_builtin();
	echo_builtin();
	env_builtin();
	exit_builtin();
	export_builtin();
	pwd_builtin();
	unset_builtin();
}

#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: structure containing potential arguments. used to maintain
 *  constant function prototype.
 *  Return: exits with agiven exit status
 */
int _myexit(info_t *info)
{
	int exitck;

	if (info->argv[1])
	{
		exitck = _erratoi(info->argv[1]);
		if (exitck == -1)
		{
			info->status = 2;
			print_error(info, "Wrong number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = -1;
		return (-2);
	}

/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _mycd(info_t *info)
{
	char *a, *dir, buffer[1024];
	int chdir_ret;

	a = getcwd(buffer, 1024);
	if (!a)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME = ");
		if (!dir)
			chdir_ret = chdir((dir = _getenv(info, "PWD = ")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->rgv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD = "))
		{
			_puts(a);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD = ")), _putchar('\n');
		chdir_ret = chdir((dir = _getenv(info, "OLDPWD = ")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "cannot cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD ="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help works. function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}

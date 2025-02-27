#include <iostream>

class Megaphone
{	
	public:
		Megaphone(int argc, char **argv);
		void		print_uppercase();
	private:
		int			_argc;
		char		**_argv;
};

Megaphone::Megaphone(int argc, char **argv) {
	_argc = argc;
	_argv = argv;
}

void	Megaphone::print_uppercase()
{
	for (int i = 1; i < _argc; i++)
	{
		for (int j = 0; _argv[i][j]; j++)
			std::cout << (char)toupper(_argv[i][j]);
	}
	std::cout << std::endl;
}

int		main(int argc, char **argv)
{
	Megaphone	megaphone(argc, argv);

	if (argc > 1)
		megaphone.print_uppercase();
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
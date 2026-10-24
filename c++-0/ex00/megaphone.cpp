#include <iostream> // std::cout and std::endl for printing to the terminal
#include <string>   // std::string so we can work with each argument as text
#include <cctype>   // std::toupper to convert a character to uppercase

// argc = how many arguments were passed (including the program name)
// argv = the actual argument strings (argv[0] is the program name)
int	main(int argc, char **argv)
{
	// If the user ran the program with no extra words, argc is 1
	// (only the program name exists). Print the default noise message.
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0); // Exit successfully; nothing else to shout
	}

	// Loop over every argument after the program name (index 1, 2, 3, ...)
	for (int i = 1; i < argc; ++i)
	{
		// Copy this C-string argument into a C++ std::string
		std::string	arg(argv[i]);

		// Walk through each character in this argument
		for (std::string::size_type j = 0; j < arg.length(); ++j)
			// toupper returns an int; cast it back to char, then print it
			std::cout << static_cast<char>(std::toupper(arg[j]));
	}

	// After all arguments are printed in uppercase, end the line
	std::cout << std::endl;
	return (0); // Program finished successfully
}

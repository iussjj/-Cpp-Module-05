#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation Form", 145, 137), _target("Unspecified")
{
	std::cout << "Shrubbery default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
	: AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
	std::cout << "Shrubbery parameterized constructor called" << std::endl;
}


//Must call AForm copy constructor to copy base class members!
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& source) 
	: AForm(source), _target(source._target)
{
	std::cout << "Shrubbery copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& source)
{
	std::cout << "Shrubbery assignment operator called" << std::endl;
	if (this != &source)
	{
		// AForm has const variables, so we only need to copy the local target
		_target = source._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery destructor called" << std::endl;
}

/*
	since checkRequirements is defined in AForm and we are inheriting from it,
	the function is treated as if it were a native part of ShrubberyCreationForm
	-> NO SCOPE RESOLUTION OPERATOR NEEDED!
	Not necessary to manually close the outfile: it is destroyed automatically,
	and its destructor closes the file safely when the function ends.
*/

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	checkRequirements(executor);

	std::string filename = _target + "_shrubbery";

	std::cout << "Creating " << filename << std::endl;

	std::ofstream outfile(filename);

	if (!outfile.is_open())
	{
		throw ShrubberyCreationForm::FileOpenException();
	}

	outfile <<	"\n"
			<<	"                 ░░\n"
			<<	"                ░▒▒░\n"
			<<	"      ░░░░░░   ░▒▓▓▒░\n"
			<<	"    ░▒▒▓▓▓▓▒▒░ ░▒██▒░\n"
			<<	"   ░▒▓██████▓▒░▒▓██▓▒░  ░░░░\n"
			<<	"  ░▒▓████████▓▒▓██▓▒░ ░▒▒▓▓▒▒░\n"
			<<	" ░▒▓██████████▓████▓▒░▒▓████▓▒░ ░░\n"
			<<	" ░▒▓██████████▓████▓▒░▒▓██████▓▒░▒▒░\n"
			<<	" ░▒▓██████████▓████▓▒░▒▓██████▓▒▒▓▓▒░\n"
			<<	"   ░▒▓██████▓▒░░▒▓▓▒░░▒▓████▓▒░░▒▓▓▒░\n"
			<<	"       ║██║      ║║    ║██║      ║║\n"
			<<	"═══════╩██╩══════╩╩════╩██╩══════╩╩════\n"
			<< std::endl;
}
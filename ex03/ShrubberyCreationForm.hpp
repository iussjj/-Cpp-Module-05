/*
	Required grades: sign 145, exec 137
	Creates a file <target>_shrubbery in the working directory and writes ASCII trees
	inside it.
*/
#pragma once

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& source);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& source);
	~ShrubberyCreationForm();

	class FileOpenException : public std::exception
	{
	public:
		const char* what() const noexcept override
		{
			return "The file is fubar!";
		}
	};

	// The Pure Virtual Function Implementation
	// The 'override' keyword tells the compiler to verify we are exactly matching AForm
	void execute(Bureaucrat const & executor) const override;
};
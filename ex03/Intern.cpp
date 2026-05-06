#include "Intern.hpp"
#include <iostream>

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

/*
	Because of OCF, copy constructors and copy assignment operators need 
	to be written even when they are functionally useless, as they are
	here since Intern has no member variables
*/

Intern::Intern(const Intern &source)
{
	//silence unused parameter warning
	(void)source;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern &source)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	if (this != &source)
	{
		//silence unused parameter warning
		(void)source;
	}
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeShrubbery(const std::string& target) const {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(const std::string& target) const {
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePardon(const std::string& target) const {
	return new PresidentialPardonForm(target);
}

/*
	Array of pointers to member functions syntax explained from inside to out:
	1. formCreators = variable name
	2. formCreators[3] = the variable is an array of 3 things
	3. (Intern::*formCreators[3]) = the things are pointers to Intern MEMBER FUNCTIONS
	4. (Intern::*formCreators[3])(const std::string& target) = ...which must take exactly 
	one parameter: a const std::string& named target
	5. AForm* (Intern::*formCreators[3])(const std::string& target) = these functions must
	return a pointer to an AForm object
	6. AForm* (Intern::*formCreators[3])(const std::string& target) const = the state of
	the calling object will not be affected 

*/

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (Intern::*formCreators[3])(const std::string& target) const = {
		&Intern::makeShrubbery,
		&Intern::makeRobotomy,
		&Intern::makePardon
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates a " << formName << " form." << std::endl; 
			return (this->*formCreators[i])(target);
		}
	}
	std::cout	<< "Intern could not create a " << formName
				<< " form because the form type doesn't exist." << std::endl;

	return NULL;
}
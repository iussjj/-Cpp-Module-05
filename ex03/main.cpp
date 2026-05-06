#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

/*
	Because Intern uses the new keyword when creating member function pointers
	to return, they are heap allocated and must be deleted to avoid memory leaks!
*/

int	main()
{
	Bureaucrat bureaucrat("The Dude", 1);
	Intern anon;
	AForm* a;
	AForm* b;
	AForm* c;
	AForm* d;
	
	std::cout << "\nTESTING SUCCESSFUL FORM CREATION:\n" << std::endl;
	
	a = anon.makeForm("shrubbery creation", "bathroom");
	b = anon.makeForm("robotomy request", "Bender");
	c = anon.makeForm("presidential pardon", "Zapp Brannigan");

	if (a != NULL)
	{
		bureaucrat.signForm(*a);
		bureaucrat.executeForm(*a);
		delete a;
	}
	if (b != NULL)
	{
		bureaucrat.signForm(*b);
		bureaucrat.executeForm(*b);
		delete b;
	}
	if (c != NULL)
	{
		bureaucrat.signForm(*c);
		bureaucrat.executeForm(*c);
		delete c;
	}

	std::cout << "\nTESTING UNSUCCESSFUL FORM CREATION:\n" << std::endl;
	d = anon.makeForm("nuclear test permit", "The Professor");

	return 0;
}

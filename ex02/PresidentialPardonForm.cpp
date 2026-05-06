/*
	PresidentialPardonForm: Required grades: sign 25, exec 5
	Informs that <target> has been pardoned by Zaphod Beeblebrox.
*/

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presidential Pardon Form", 25, 5), _target("Unspecified")
{
	std::cout << "Pardon Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
	: AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	std::cout << "Pardon Parameterized Constructor called" << std::endl;
}


//Must call AForm copy constructor to copy base class members!
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& source) 
	: AForm(source), _target(source._target)
{
	std::cout << "Pardon Copy Constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& source)
{
	std::cout << "Pardon Assignment Operator called" << std::endl;
	if (this != &source)
	{
		// AForm has const variables, so we only need to copy the local target
		_target = source._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Pardon Destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	checkRequirements(executor);

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
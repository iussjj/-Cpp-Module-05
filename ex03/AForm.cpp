#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm() : _name("Blank"), _signGrade(150), _executeGrade(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int sign, int exec) : _name(name), _signGrade(sign), _executeGrade(exec)
{
	if (sign > _lowestGrade || exec > _lowestGrade)
	{
		throw AForm::GradeTooLowException();
	}
	if (sign < _highestGrade || exec < _highestGrade)
	{
		throw AForm::GradeTooHighException();
	}
	
	std::cout << "AForm parametrized constructor called" << std::endl;
}

AForm::AForm(const AForm &source) : _name(source._name), _signed(source._signed), _signGrade(source._signGrade), _executeGrade(source._executeGrade)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &source)
{
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &source)
	{
		std::cout << "Unable to overwrite const variables" << std::endl;
		_signed = source._signed;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

const std::string& AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecGrade() const
{
	return _executeGrade;
}

void AForm::checkRequirements(Bureaucrat const & executor) const
{
	if (!_signed)
	{
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > _executeGrade)
	{
		throw AForm::GradeTooLowException();
	}
}

void AForm::beSigned(const Bureaucrat& signer)
{
	if (_signed)
	{
		throw AForm::FormAlreadySignedException();
	}

	if (signer.getGrade() > _signGrade)
	{
		throw AForm::GradeTooLowException();
	}

	_signed = true;
}

/*
	std::boolalpha converts boolean values from the standard output of 1 and 0
	to "true" and "false"
	-it's sticky and affects the target stream even after function termination,
	so it needs to be disabled with std::noboolalpha 
*/

std::ostream &operator<<(std::ostream &out, const AForm &source)
{
	out	<< std::boolalpha << "AForm name: " << source.getName() << std::endl
		<< "Signed: " << source.getSigned() << std::endl
		<< "Sign grade: " << source.getSignGrade() << std::endl
		<< "Execute grade: " << source.getExecGrade() << std::endl
		<< std::noboolalpha;

	return out;
}

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() : _name("Blank"), _signGrade(150), _executeGrade(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int sign, int exec) : _name(name), _signGrade(sign), _executeGrade(exec)
{
	if (sign > _lowestGrade || exec > _lowestGrade)
	{
		throw Form::GradeTooLowException();
	}
	if (sign < _highestGrade || exec < _highestGrade)
	{
		throw Form::GradeTooHighException();
	}
	
	std::cout << "Form parametrized constructor called" << std::endl;
}

Form::Form(const Form &source) : _name(source._name), _signed(source._signed), _signGrade(source._signGrade), _executeGrade(source._executeGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form &source)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &source)
	{
		std::cout << "Unable to overwrite const variables" << std::endl;
		_signed = source._signed;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

const std::string& Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecGrade() const
{
	return _executeGrade;
}

void Form::beSigned(const Bureaucrat& signer)
{
	if (_signed)
	{
		throw Form::FormAlreadySignedException();
	}

	if (signer.getGrade() > _signGrade)
	{
		throw Form::GradeTooLowException();
	}

	_signed = true;
}

/*
	std::boolalpha converts boolean values from the standard output of 1 and 0
	to "true" and "false"
	-it's sticky and affects the target stream even after function termination,
	so it needs to be disabled with std::noboolalpha 
*/

std::ostream &operator<<(std::ostream &out, const Form &source)
{
	out	<< std::boolalpha << "Form name: " << source.getName() << std::endl
		<< "Signed: " << source.getSigned() << std::endl
		<< "Sign grade: " << source.getSignGrade() << std::endl
		<< "Execute grade: " << source.getExecGrade() << std::endl
		<< std::noboolalpha;

	return out;
}

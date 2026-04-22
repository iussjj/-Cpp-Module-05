#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Anonymous"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade > _lowestGrade)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	if (grade < _highestGrade)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	_grade = grade;
	std::cout << "Bureaucrat parametrized constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &source) : _name(source._name), _grade(source._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &source)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &source)
	{
		std::cout << "Unable to overwrite const _name variable" << std::endl;
		_grade = source._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

const std::string& Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

/*
	-post increment _grade++ creates a temporary copy of _grade, increments
	it and returns the incremented copy
	-pre increment simply increments the original variable and returns it,
	and so is more efficient.

	!Always use pre-increment for efficiency, unless you specifically need the
	!old value for some reason!
*/

void Bureaucrat::incrementGrade()
{
	if ((_grade - 1) < _highestGrade)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	--_grade;
}

void Bureaucrat::decrementGrade()
{
	if ((_grade + 1) > _lowestGrade)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	++_grade;
}

/*
	here e.what() returns correct exception because of what() overwrite in Form.hpp:
	
	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const noexcept override
		{
			return "The grade is too damn high!";
		}
	};
*/

void Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		//next line is only executed if try is successful
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout	<< _name << " couldn't sign " << form.getName()
					<< " because: " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &source)
{
	out << source.getName() << ", bureaucrat grade " << source.getGrade() << ".";
	return out;
}

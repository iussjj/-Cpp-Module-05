#pragma once

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <exception>

/*
	!The term for the relationship between Bureaucrat and the
	!exception classes is Enclosing Class and Nested Class!

	String parameters should be passed by const reference
	as in Bureaucrat(const std::string& name, int grade);

	Exception class definition syntax notes:
	-Can be nested inside the enclosing class
	-inherits (public) std::exception
	const char* what() const noexcept override
	const char* = return type (classic C-style string)
	what() = function inherited from std::exception
	
*/

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
	static const int	_highestGrade = 1;
	static const int	_lowestGrade = 150;

public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat &source);
	Bureaucrat &operator=(const Bureaucrat &source);
	~Bureaucrat();

	//(void) is unnecessary and discouraged in C++
	//return type needs to be const for const member variable
	const std::string&	getName() const;
	int					getGrade() const;

	void			incrementGrade();
	void			decrementGrade();
	
	//const here means that the bureucrat's variables are unchanged
	void			signForm(AForm& form) const;

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const noexcept override
		{
			return "The grade is too damn high!";
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const noexcept override
		{
			return "The grade is too low, bro!";
		}
	};

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &source);
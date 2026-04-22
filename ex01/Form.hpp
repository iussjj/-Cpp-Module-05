#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat; //forward declaration avoids circular dependancy trap

/*
	!The term for the relationship between Form and the
	!exception classes is Enclosing Class and Nested Class!

	String parameters should be passed by const reference
	as in Form(const std::string& name, int grade);

	Exception class definition syntax notes:
	-Can be nested inside the enclosing class
	-inherits (public) std::exception
	const char* what() const noexcept override
	const char* = return type (classic C-style string)
	what() = function inherited from std::exception
	
*/

class Form
{
private:
	const std::string	_name;
	bool				_signed = false;
	const int			_signGrade;
	const int			_executeGrade;
	static const int	_highestGrade = 1;
	static const int	_lowestGrade = 150;

public:
	Form();
	Form(const std::string& name, int sign, int exec);
	Form(const Form &source);
	Form &operator=(const Form &source);
	~Form();

/*	
	-primitive return types returning by value don't need to be const,
	since the value being returned is a copy
	-heavier return types (like string objects) which are returned by reference
	need to be set to const, so the getter can't accidentally modify the 
	original
*/

	const std::string&	getName() const;
	bool				getSigned() const;
	int					getSignGrade() const;
	int					getExecGrade() const;

	void				beSigned(const Bureaucrat& signer);

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

	class FormAlreadySignedException : public std::exception
	{
	public:
		const char* what() const noexcept override
		{
			return "The form is already signed!";
		}
	};

};

std::ostream &operator<<(std::ostream &out, const Form &source);
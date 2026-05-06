#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

class Intern
{
private:
/*
	Refresher: the first const guarantees that the target reference won't be altered
	the second guarantees that calling the function will not change the internal state
	of the caller function
	-a const (unmodifiable) object can only call const functions!
*/
	AForm* makeShrubbery(const std::string& target) const;
	AForm* makeRobotomy(const std::string& target) const;
	AForm* makePardon(const std::string& target) const;

public:
	Intern();
	Intern(const Intern &source);
	Intern &operator=(const Intern &source);
	~Intern();

	AForm* makeForm(const std::string& formName, const std::string& target) const;
};
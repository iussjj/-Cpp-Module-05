/*
	Required grades: sign 72, exec 45
	Makes some drilling noises, then informs that <target> has been robotomized
	successfully 50% of the time. Otherwise, it informs that the robotomy failed.
*/

#pragma once

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& source);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& source);
	~RobotomyRequestForm();

	// The Pure Virtual Function Implementation
	// The 'override' keyword tells the compiler to verify we are exactly matching AForm
	void execute(Bureaucrat const & executor) const override;
};
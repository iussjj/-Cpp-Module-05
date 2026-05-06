/*
	PresidentialPardonForm: Required grades: sign 25, exec 5
	Informs that <target> has been pardoned by Zaphod Beeblebrox.
*/

#pragma once

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& source);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& source);
	~PresidentialPardonForm();

	// The Pure Virtual Function Implementation
	// The 'override' keyword tells the compiler to verify we are exactly matching AForm
	void execute(Bureaucrat const & executor) const override;
};
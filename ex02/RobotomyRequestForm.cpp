/*
	Required grades: sign 72, exec 45
	Makes some drilling noises, then informs that <target> has been robotomized
	successfully 50% of the time. Otherwise, it informs that the robotomy failed.
*/

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <random>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request Form", 72, 45), _target("Unspecified")
{
	std::cout << "Robotomy default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
	: AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << "Robotomy parameterized constructor called" << std::endl;
}


//Must call AForm copy constructor to copy base class members!
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& source) 
	: AForm(source), _target(source._target)
{
	std::cout << "Robotomy copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& source)
{
	std::cout << "Robotomy assignment operator called" << std::endl;
	if (this != &source)
	{
		// AForm has const variables, so we only need to copy the local target
		_target = source._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	checkRequirements(executor);

	std::cout << "*OMINOUS DRILLING NOISES...*" << std::endl;

	//generates random seed (starting number) from current hardware state
	std::random_device seed;

	//create random number generator from random seed, using Mersenne Twister algorithm
	std::mt19937 gen(seed());

	//dist object takes int input and normalizes it to 0 or 1
	std::uniform_int_distribution<int> dist(0, 1);

	if (dist(gen) == 1)
	{
		std::cout << "Yay, " << _target << " was robotomized successfully! :)" << std::endl;
	}
	else
	{
		std::cout	<< "Oh dear, " << _target
					<< "'s robotomy failed horrifically! Sorry about that! :(" << std::endl;
	}
}
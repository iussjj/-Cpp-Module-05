#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main()
{
	try
	{
		Bureaucrat jesus("Literally Jesus", 1);
		Bureaucrat earl("Earl", 150);
		{
			std::cout << "\nTESTING SHRUBBERY FORM:" << std::endl;
			ShrubberyCreationForm shrub("bathroom");
			std::cout << "\nTrying to execute unsigned form:" << std::endl;
			earl.executeForm(shrub);
			jesus.executeForm(shrub);

			std::cout << "\nTrying to sign form:" << std::endl;
			earl.signForm(shrub);
			jesus.signForm(shrub);

			std::cout << "\nTrying to execute signed form:" << std::endl;
			earl.executeForm(shrub);
			jesus.executeForm(shrub);
		}
		{
			std::cout << "\nTESTING ROBOTOMY FORM:" << std::endl;
			RobotomyRequestForm robo("Bender");
			std::cout << "\nTrying to execute unsigned form:" << std::endl;
			earl.executeForm(robo);
			jesus.executeForm(robo);

			std::cout << "\nTrying to sign form:" << std::endl;
			earl.signForm(robo);
			jesus.signForm(robo);

			std::cout << "\nTrying to execute signed form:" << std::endl;
			earl.executeForm(robo);
			jesus.executeForm(robo);
		}
		{
			std::cout << "\nTESTING PARDON FORM:" << std::endl;
			PresidentialPardonForm pardon("Fry");
			std::cout << "\nTrying to execute unsigned form:" << std::endl;
			earl.executeForm(pardon);
			jesus.executeForm(pardon);

			std::cout << "\nTrying to sign form:" << std::endl;
			earl.signForm(pardon);
			jesus.signForm(pardon);

			std::cout << "\nTrying to execute signed form:" << std::endl;
			earl.executeForm(pardon);
			jesus.executeForm(pardon);
		}
		std::cout << "\nTESTS COMPLETE!\n" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Fatal error: " << e.what() << std::endl;
	}

	return 0;
}

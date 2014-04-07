#include <iostream>

#include "divider.hpp"
#include "stir_quote.hpp"
#include "total_value.hpp"

int main()
{
        divider();

	std::cout << "                       == Welcome to Miyagi! ==                       \n\n"
                  << "The following problem types are available:                            \n\n"
                  << " * 1 - Total Trade Value                                                \n"
                  << " * 2 - STIR Future Quote                                              \n\n"
                  << "Please enter the number corresponding to your choice: ";

	int choice;

	std::cin >> choice;
	std::cin.ignore();

        if (choice != 1 && choice != 2) {
                std::cerr << "\nThat's not a valid choice. "
                          << "Please try again once you have learned how\n"
                          << "to follow simple instructions.\n";

                divider();

                return 1;
        }

        int problem_count;

        while (1) {
                std::cout << "\nPlease enter the number of problems you want to solve: ";

                std::cin >> problem_count;
                std::cin.ignore();

                if (problem_count > 0)
                        break;

                std::cout << "That's not a valid choice.\n";
        }

        divider();

	switch (choice) {
		case 1:
			total_value(problem_count);
			break;
                case 2:
                        stir_quote(problem_count);
                        break;
	}

	return 0;
}

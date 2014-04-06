#include <iostream>

#include "divider.hpp"
#include "totalvalue.hpp"

int main()
{
        divider();

	std::cout << "                       == Welcome to Miyagi! ==                       \n\n"
                  << "The following problem types are available:                            \n\n"
                  << " * 1 - Total Trade Value                                              \n\n"
                  << "Please enter the number corresponding to your choice: ";

	int choice;

	std::cin >> choice;
	std::cin.ignore();

	switch (choice) {
		case 1:
			total_value();
			break;
		default:
			std::cerr << "\nThat's not a valid choice. "
                                  << "Please try again once you have learned how\n"
                                  << "to follow simple instructions.\n";
                        divider();
			return 1;
	}

	return 0;
}

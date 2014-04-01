#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <random>
#include <vector>

int total_value()
{
	std::cout << "\n == Instructions ==\n\n"
                  << "The best bid and offer of a stock will be displayed on the screen\n"
                  << "with a client request to buy or sell some shares. Example:\n\n"
                  << "XYZ BBO: 12.01 - 12.02 | Client Request: Buy 1000 XYZ @ Market\n\n"
                  << "Your job is to calculate the total value of the trade. The game\n"
                  << "ends when you get a question wrong.\n\n"
                  << "Press ENTER to start.";

	std::cin.ignore();

	std::vector<int> sizes = {1000, 5000, 10000, 25000, 50000, 75000, 100000, 1000000};

	std::uniform_int_distribution<int> size_dist(0, sizes.size() - 1);
	std::default_random_engine size_gen(time(NULL));

	std::vector<std::string> sides = {"Buy", "Sell"};

	std::uniform_int_distribution<int> side_dist(0, 1);
	std::default_random_engine side_gen(time(NULL));

	std::uniform_real_distribution<double> price_dist(0.0, 99.99);
	std::default_random_engine price_gen(time(NULL));

	while (1) {
		int size_idx, size;

		size_idx = size_dist(size_gen);
		size     = sizes[size_idx];

		int 	    side_idx;
		std::string side;

		side_idx = side_dist(side_gen);
		side     = sides[side_idx];

		double bid, ask, price;

		bid = std::round(100.0 * price_dist(price_gen)) / 100.0;
		ask = bid + 0.01;

		if (side == "Buy")
			price = ask;
		else
			price = bid;

		long real_ans, ans;

		real_ans = std::lround(price * size);

		std::cout << std::fixed << std::setprecision(2) << "\n"
                          << "XYZ BBO: " << bid << " - " << ask << " | "
                          << "Client Request: " << side << " " << size << " XYZ @ Market\n"
                          << "Trade Value = ";

		std::cin >> ans;

		if (ans != real_ans) {
			std::cout << "\nWrong!\n";
			break;
		}
	}

	return 0;
}
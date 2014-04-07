#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <random>
#include <vector>

#include "tracker.hpp"
#include "utils.hpp"

int total_value(int problem_count)
{
        Tracker tracker;

	std::vector<int> sizes = {1000, 5000, 10000, 25000, 50000, 75000, 100000, 1000000};

	std::uniform_int_distribution<int> size_dist(0, sizes.size() - 1);
	std::default_random_engine size_gen(time(nullptr));

	std::vector<std::string> sides = {"Buy", "Sell"};

	std::uniform_int_distribution<int> side_dist(0, 1);
	std::default_random_engine side_gen(time(nullptr));

	std::uniform_real_distribution<double> price_dist(0.0, 99.99);
	std::default_random_engine price_gen(time(nullptr));

        for (int i = 1; i <= problem_count; i++) {
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

                std::chrono::time_point<std::chrono::steady_clock> start, end;
                double solve_time;

                start = std::chrono::steady_clock::now();

		std::cout << std::fixed << std::setprecision(2)
                          << "XYZ BBO: " << bid << " - " << ask << " | "
                          << "Client Request: " << side << " " << size << " XYZ @ Market\n"
                          << "Trade Value = ";

		std::cin >> ans;

                end        = std::chrono::steady_clock::now();
                solve_time = std::chrono::duration_cast<std::chrono::milliseconds>
                             (end - start).count() / 1000.0;

                tracker.update(solve_time, ans == real_ans);

                if (ans != real_ans)
                        std::cout << "Wrong!\n";

                std::cout << "\n";
	}

        tracker.print();

	return 0;
}

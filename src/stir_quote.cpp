#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>

#include "tracker.hpp"
#include "utils.hpp"

int stir_quote(int problem_count)
{
        Tracker tracker;

	std::uniform_real_distribution<double> quote_dist(95.000, 99.995);
	std::default_random_engine quote_gen(time(nullptr));

        for (int i = 1; i <= problem_count; i++) {
                double quote, real_ans, ans;

                quote = std::round(1000.0 * quote_dist(quote_gen)) / 1000.0;
                quote -= std::fmod(quote, 0.005);

		real_ans = 100.0 - quote;

                std::chrono::time_point<std::chrono::steady_clock> start, end;
                double solve_time;

                start = std::chrono::steady_clock::now();

		std::cout << std::fixed << std::setprecision(3)
                          << "STIR Quote: " << quote << " | Interest Rate = ";

		std::cin >> ans;

                end        = std::chrono::steady_clock::now();
                solve_time = std::chrono::duration_cast<std::chrono::milliseconds>
                             (end - start).count() / 1000.0;

                tracker.update(solve_time, double_equals(ans, real_ans));

                if (!double_equals(ans, real_ans))
                        std::cout << "Wrong!\n";

                std::cout << "\n";
	}

        tracker.print();

	return 0;
}

#include <iomanip>
#include <iostream>

#include "divider.hpp"
#include "tracker.hpp"

Tracker::Tracker()
{
        correct      = 0;
        attempted    = 0;
        elapsed_time = 0.0;
}

void Tracker::update(double time, bool answer_correct)
{
        attempted++;

        if (answer_correct)
                correct++;

        elapsed_time += time;
}

void Tracker::print()
{
        std::cout << "                           == Game Over! ==\n\n"
                  << std::fixed << std::setprecision(2)
                  << " * Correct Answers:  " << correct << " / " << attempted << " ("
                  << (double) correct / attempted * 100 << "%)\n"
                  << " * Time per Problem: " << elapsed_time / attempted << " seconds\n";

        divider();
}

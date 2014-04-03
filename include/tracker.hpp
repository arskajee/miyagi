#ifndef TRACKER_H
#define TRACKER_H

class Tracker
{
private:
        int correct;
        int attempted;
        double elapsed_time;
public:
        Tracker();

        void update(double time, bool answer_correct);

        void print();
};

#endif

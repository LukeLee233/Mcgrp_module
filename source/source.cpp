#include "source.h"


using namespace std;


vector<int> get_negative_coding(const vector<int> &sequence)
{
    int sign = 1;
    vector<int> negative_coding_sol;
    negative_coding_sol.clear();

    for (auto task : sequence) {
        if (task == DUMMY) {
            sign = -1;
        }
        else {
            negative_coding_sol.push_back(sign * task);
            sign = 1;
        }
    }

    return negative_coding_sol;
}

vector<int> get_delimeter_coding(const vector<int> &negative_coding)
{
    vector<int> delimeter_coding;
    delimeter_coding.clear();
    for (auto task:negative_coding) {
        if (task < 0) {
            delimeter_coding.push_back(DUMMY);
        }
        delimeter_coding.push_back(abs(task));
    }
    delimeter_coding.push_back(DUMMY);

    return delimeter_coding;
}



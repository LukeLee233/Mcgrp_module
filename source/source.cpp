#include "source.h"
#include <iostream>
#include <sys/timeb.h>


using namespace std;

struct timeb epoch_start_time;

ofstream result_out;
ofstream log_out;

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

void __My_Assert(const char *expr_str, bool expr, const char *file, int line, const char *msg)
{
    if (!expr) {
        std::cerr << "Assert failed:\t" << msg << "\n"
                  << "Expected:\t" << expr_str << "\n"
                  << "Source:\t\t" << file << ", line " << line << "\n";
        abort();
    }
}

bool print(std::ostream &os1, const std::string &str){
    if(os1 << str << endl){
        return true;
    }

    return false;
}
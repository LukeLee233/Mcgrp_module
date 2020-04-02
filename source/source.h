//Author: Luke
//Date: 2020-3-20
#include <vector>
#include <string>
#include <fstream>

#define DUMMY 0
#define ARC_NO_INVERSE -1
#define NODE_NO_INVERSE -2


#ifndef NODEBUG
#   define My_Assert(Expr, Msg) \
    __My_Assert(#Expr, Expr, __FILE__, __LINE__, Msg)

#   define DEBUG_PRINT(stuff) std::cout<<(stuff)<<endl
#else
#   define My_Assert(Expr, Msg) ;

#   define DEBUG_PRINT(stuff) ;
#endif

extern std::ofstream result_out;

extern std::ofstream log_out;


using namespace std;

struct arc
{
    int tail_node;
    int head_node;
    int trav_cost;
};

struct Individual
{
    std::vector<int> sequence;
    std::vector<int> route_seg_load;
    double total_cost;
    int total_vio_load;
};

struct task
{
    int head_node;
    int tail_node;
    int trave_cost;
    int serv_cost;
    int demand;
    int inverse;
};

void __My_Assert(const char *expr_str, bool expr, const char *file, int line, const char *msg);


vector<int> get_negative_coding(const vector<int> &sequence);

vector<int> get_delimeter_coding(const vector<int> &negative_coding);

bool print(std::ostream &os1, const std::string &str);

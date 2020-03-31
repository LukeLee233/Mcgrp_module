//
// Created by luke on 2020/4/1.
//

#ifndef FILE_H
#define FILE_H

#include <string>

struct instance_num_information
{
    int node_num;
    int edge_num;
    int arc_num;
    int req_edge_num;
    int req_arc_num;
    int req_node_num;

    instance_num_information():node_num(0),edge_num(0),arc_num(0)
        ,req_edge_num(0),req_arc_num(0),req_node_num(0) {}
};


void GetTasksNum(std::string filename, instance_num_information &number_info);


#endif //FILE_H

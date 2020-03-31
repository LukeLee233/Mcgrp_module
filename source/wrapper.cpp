#include <pybind11/include/pybind11.h>
#include <pybind11/include/stl.h>

#include "source.h"
#include "file.h"

namespace py = pybind11;


//templeate of ordinary funtion
PYBIND11_MODULE(McgrpUtils, m) {
    m.doc() = "Interface of mcgrp"; // optional module docstring

    //constants
    m.attr("DUMMY") = DUMMY;

    //structs
    py::class_<instance_num_information>(m, "instance_num_information")
        .def(pybind11::init<>())
        .def_readwrite("node_num", &instance_num_information::node_num)
        .def_readwrite("edge_num", &instance_num_information::edge_num)
        .def_readwrite("arc_num", &instance_num_information::arc_num)
        .def_readwrite("req_edge_num", &instance_num_information::req_edge_num)
        .def_readwrite("req_arc_num", &instance_num_information::req_arc_num)
        .def_readwrite("req_node_num", &instance_num_information::req_node_num);

    //fumctions
    m.def("get_negative_coding",&get_negative_coding,"get negative coding format");
    m.def("get_delimeter_coding", &get_delimeter_coding,"get zero coding format");

    m.def("GetTasksNum",&GetTasksNum,"get instance meta info");
}


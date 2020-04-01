#include <pybind11/include/pybind11.h>
#include <pybind11/include/stl.h>

#include "source.h"
#include "file.h"
#include "RNG.h"

namespace py = pybind11;


//templeate of ordinary funtion
PYBIND11_MODULE(McgrpUtils, m) {
    m.doc() = "A dedicated library of heuristic algos for"
              "Mixed Capacitated General Routing Problem.";

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


    //classes
    //I decided not to expose template method cause I think I dont need to call it in python
    //If you want to use it, you need to specialization it :)
    py::class_<RNG>(m,"RNG")
        .def(pybind11::init<int>(), py::arg("seed") = 0)
        .def("Randint",&RNG::Randint, py::arg("low"),py::arg(("high")))
        .def("Randfloat",&RNG::Randfloat, py::arg("low"),py::arg("high"))
        .def("change", &RNG::change, py::arg("seed"))
        .def("show_seed",&RNG::show_seed)
        .def("restore", &RNG::restore);

    //fumctions
    m.def("get_negative_coding",&get_negative_coding,py::arg("zero format seq"));
    m.def("get_delimeter_coding", &get_delimeter_coding,py::arg("negative format seq"));

    m.def("GetTasksNum",&GetTasksNum,py::arg("filename"),py::arg("instance metainfo ptr"));
}


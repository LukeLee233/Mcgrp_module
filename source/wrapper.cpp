#include <pybind11/include/pybind11.h>
#include <pybind11/include/stl.h>
#include <pybind11/include/stl_bind.h>

#include "file.h"
#include "RNG.h"
#include "MCGRP.h"

namespace py = pybind11;

//expose vector<int> to python
PYBIND11_MAKE_OPAQUE(std::vector<int>);


//templeate of ordinary funtion
PYBIND11_MODULE(McgrpUtils, m) {
    m.doc() = "A dedicated library of heuristic algos for"
              "Mixed Capacitated General Routing Problem.";

    //dedicated data type
    py::bind_vector<std::vector<int>>(m, "VectorInt",py::module_local());
    py::bind_vector<std::vector<RNG>>(m, "VectorRNG",py::module_local());
    py::bind_vector<std::vector<instance_num_information>>(m, "Vectorinstanceinfo",py::module_local());



    //constants
    m.attr("DUMMY") = DUMMY;

    //structs
    py::class_<arc>(m,"arc")
        .def_readonly("tail_node",&arc::tail_node)
        .def_readonly("head_node",&arc::head_node)
        .def_readonly("trav_cost",&arc::trav_cost);

    py::class_<MCGRPNeighborInfo>(m,"MCGRPNeighborInfo")
        .def_readonly("task_id",&MCGRPNeighborInfo::task_id)
        .def_readonly("distance",&MCGRPNeighborInfo::distance);

    py::class_<task>(m,"task")
        .def_readonly("head_node",&task::head_node)
        .def_readonly("tail_node",&task::tail_node)
        .def_readonly("trave_cost",&task::trave_cost)
        .def_readonly("serv_cost",&task::serv_cost)
        .def_readonly("demand",&task::demand)
        .def_readonly("inverse",&task::inverse);



    py::class_<MCGRP>(m,"MCGRP")
        .def_readonly("instance_name", &MCGRP::instance_name)

        .def_readonly("node_num", &MCGRP::node_num)
        .def_readonly("edge_num", &MCGRP::edge_num)
        .def_readonly("arc_num", &MCGRP::arc_num)

        .def_readonly("req_node_num", &MCGRP::req_node_num)
        .def_readonly("req_edge_num", &MCGRP::req_edge_num)
        .def_readonly("req_arc_num", &MCGRP::req_arc_num)

        .def_readonly("nonreq_node_num", &MCGRP::nonreq_node_num)
        .def_readonly("nonreq_edge_num", &MCGRP::nonreq_edge_num)
        .def_readonly("nonreq_arc_num", &MCGRP::nonreq_arc_num)

        .def_readonly("actual_task_num", &MCGRP::actual_task_num)
        .def_readonly("total_arc_num", &MCGRP::total_arc_num)
        .def_readonly("vehicle_num", &MCGRP::vehicle_num)
        .def_readonly("capacity", &MCGRP::capacity)

        .def_readonly("DEPOT", &MCGRP::DEPOT)

        .def_readonly("neigh_size", &MCGRP::neigh_size)
        .def_readonly("trav_cost", &MCGRP::trav_cost)

        .def_readonly("serve_cost", &MCGRP::serve_cost)

        .def_readonly("inst_arcs", &MCGRP::inst_arcs)

        .def_readonly("min_cost", &MCGRP::min_cost)

        .def_readonly("shortest_path", &MCGRP::shortest_path)
        .def_readonly("inst_tasks", &MCGRP::inst_tasks)
        .def_readonly("sentinel", &MCGRP::sentinel)

        .def_readonly("task_dist", &MCGRP::task_dist)
        .def_readonly("task_neigh_list", &MCGRP::task_neigh_list)

        .def_readonly("total_service_cost", &MCGRP::total_service_cost)
//        .def_readwrite("_rng", &MCGRP::_rng)

        .def_readonly("best_sol_buff", &MCGRP::best_sol_buff)
        .def_readonly("best_total_route_length", &MCGRP::best_total_route_length)
        .def_readonly("best_sol_time", &MCGRP::best_sol_time)

        .def_readonly("global_best_sol_buff", &MCGRP::global_best_sol_buff)
        .def_readonly("global_best_total_route_length", &MCGRP::global_best_total_route_length)
        .def_readonly("global_best_sol_time", &MCGRP::global_best_sol_time)
        .def_readonly("global_mut", &MCGRP::global_mut)

        .def(pybind11::init<string&, int>(), py::arg("filename"), py::arg("random_seed"))
        .def("create_neighbor_lists",&MCGRP::create_neighbor_lists,py::arg("neighbor_size"))
        ;



//    py::class_<instance_num_information>(m, "instance_num_information")
//        .def(pybind11::init<>())
//        .def_readwrite("node_num", &instance_num_information::node_num)
//        .def_readwrite("edge_num", &instance_num_information::edge_num)
//        .def_readwrite("arc_num", &instance_num_information::arc_num)
//        .def_readwrite("req_edge_num", &instance_num_information::req_edge_num)
//        .def_readwrite("req_arc_num", &instance_num_information::req_arc_num)
//        .def_readwrite("req_node_num", &instance_num_information::req_node_num);





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

    py::class_<COMB>(m,"COMB")
        .def(pybind11::init<int,int>(), py::arg("c"),py::arg("r"))
        .def("get_combinations",&COMB::get_combinations,py::return_value_policy::reference);


    //fumctions
    m.def("get_negative_coding",&get_negative_coding,py::arg("zero format seq"));
    m.def("get_delimeter_coding", &get_delimeter_coding,py::arg("negative format seq"));

    m.def("GetTasksNum",&GetTasksNum,py::arg("filename"),py::arg("instance metainfo ptr"));
}


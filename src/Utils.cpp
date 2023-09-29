#include <iostream>
#include <boost/program_options.hpp>

#include "Utils.hpp"

namespace po = boost::program_options;

// ============================================================
//  PRIVATE FUNCTION
// ============================================================

bool execute_param(po::variables_map vm, po::options_description desc){

    if (vm.count("help")) {
        std::cout << desc << std::endl;
        return true;
    }

    if (vm.count("version")) {
        std::cout << "Version 1.0" << std::endl;
        return true;
    }

    return false;
}

// ============================================================
//  PUBLIC FUNCTION
// ============================================================

bool Utils::get_input_param(int argc, char const *argv[]) {
    po::variables_map vm;
    po::options_description desc("Allowed options");
    
    desc.add_options()
        ("help,h", "Produce help message")
        ("version,v", "Show version");

    try {   /// Try to capture date
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);
    } catch(const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }

    return execute_param(vm, desc);
}

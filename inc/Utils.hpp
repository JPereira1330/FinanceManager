/**
 * @file    Utils.hpp
 * @author  José C. Pereira (jpereira1330@gmail.com)
 * @brief 
 * @version 0.1
 * @date    2023-09-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef INC_UTILS_HPP
#define INC_UTILS_HPP

namespace Utils {

    /// @brief get input argument and execute
    /// @param argc count argument input
    /// @param argv verbose argument input
    /// @return @c true     to success
    /// @return @c false    to fail
    bool get_input_param(int argc, char const *argv[]);

}

#endif  // INC_UTILS_HPP

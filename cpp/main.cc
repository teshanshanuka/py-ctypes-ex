/**
 * @file main.cc
 * @author Teshan Liyanage (teshanuka@gmail.com)
 * @brief Just to test `sample_lib` in c++
 * @version 0.1
 * @date 2022-06-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include "sample_lib.hh"

int main() {
    std::cout << "Creating polygon" << std::endl;
    auto p = Polygon(5);
    p.setEdgeLengths({1, 4.5, 3.5, 4.5, 6.5});
    std::cout << "Sum edge len: " << p.sumEdgeLengths() << std::endl;

    auto v = p.getEdgesBy2();
    std::cout << "Edges x2: ";
    for (const auto& l: v)
        std::cout << l << ", ";
    std::cout << std::endl;
    return 0;
}
#ifndef TYPES_H
#define TYPES_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <chrono>
#include <ctime>
#include "Point.h"
#include "Vertex.h"

using vector_type = std::vector<Point*>;
using map_type = std::map<double, Vertex*>;
using path_type = std::unordered_map<int, int>;

using clock_type = std::chrono::high_resolution_clock::time_point;
using time_period = std::chrono::duration<double>;

#endif //TYPES_H

#ifndef AAL_LS_LAMANA_TYPES_H
#define AAL_LS_LAMANA_TYPES_H

#include <iostream>
#include <vector>
#include <map>
#include <chrono>
#include <ctime>
#include "Point.h"
#include "Vertex.h"

using vector_type = std::vector<Point>;
using map_type = std::map<double, Vertex*>;
using path_type = std::map<int, int>;

using clock_type = std::chrono::high_resolution_clock::time_point;
using time_period = std::chrono::duration<double>;

#endif //AAL_LS_LAMANA_TYPES_H

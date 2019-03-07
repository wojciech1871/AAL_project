#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unistd.h>
#include <getopt.h>

#include "Point.h"
#include "Vertex.h"
#include "MyAlgorithm.h"

void txtFileParser(std::vector<Point>& points) {
    int number, weight;
    double x, y;
    while (std::cin >>number >>x >>y >>weight) {
        points.emplace_back(Point(number, x, y, weight));
    }
}
int main(int argc, char* argv[])
{
    int opt;
    int mValue, nValue;
    int kValue, sValue, rValue;
    std::vector<Point> pointsVector;
    MyAlgorithm myAlgorithm;
    static struct option long_options[] = {
            {"mode",        required_argument, nullptr,  'm'},
            {"probSize",    optional_argument, nullptr,  'n'},
            {"numOfProbs",  optional_argument, nullptr,  'k'},
            {"step",        optional_argument, nullptr,  's'},
            {"instPerProb", optional_argument, nullptr,  'r'},
            {nullptr, 0, nullptr, 0}
    };
    int long_index = 0;
    while ((opt = getopt_long(argc, argv, "m:n:k:s:r:", long_options, &long_index)) != -1)
        switch(opt) {
            case 'm':
                mValue = atoi(optarg);
                break;
            case 'n':
                nValue = atoi(optarg);
                break;
            case 'k':
                kValue = atoi(optarg);
                break;
            case 's':
                sValue = atoi(optarg);
                break;
            case 'r':
                rValue = atoi(optarg);
                break;
            default:
                break;
        }
    std::cout <<mValue <<std::endl;
    std::cout <<nValue <<std::endl;
    std::cout <<kValue <<std::endl;
    std::cout <<sValue <<std::endl;


    txtFileParser(pointsVector);
    myAlgorithm.runAlgorithmLSLamana(pointsVector);
    std::cout <<"Result: " <<myAlgorithm.returnAlgorithmResult() <<std::endl;
}

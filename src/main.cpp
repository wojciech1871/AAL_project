#include <iostream>
#include <algorithm>
#include <unistd.h>
#include <getopt.h>

#include "MyAlgorithm.h"
#include "PointsGenerator.h"

void pointsFromStream(vector_type& points) {
    int number, weight;
    double x, y;
    while (std::cin >>number >>x >>y >>weight) {
        points.emplace_back(number, x, y, weight);
    }
}

void algResultsForOneInstance(MyAlgorithm& myAlgorithm, vector_type& pointsVector) {
    myAlgorithm.printPoints(pointsVector);
    myAlgorithm.runAlgorithmLSLamana(pointsVector);
    std::cout <<"Max path: " <<myAlgorithm.returnAlgorithmResult() <<std::endl;
    std::cout <<"Vertex path: " <<std::endl;
    myAlgorithm.printVertexPath();
    std::cout <<std::endl;
}

void usageHelp() {
    std::cout<<"Wrong program call" <<std::endl;
}

int main(int argc, char* argv[])
{
    int opt;
    int mValue=0;
    int nValue=0;
    int kValue=0;
    int sValue=0;
    int rValue=0;
    std::vector<Point> pointsVector;
    MyAlgorithm myAlgorithm;
    PointsGenerator pointsGenerator;
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
    switch (mValue) {
        case 1:
            pointsFromStream(pointsVector);
            algResultsForOneInstance(myAlgorithm, pointsVector);
            return(0);
        case 2:
            if(nValue > 0) {
                pointsGenerator.generateNPoints(pointsVector, nValue);
                algResultsForOneInstance(myAlgorithm, pointsVector);
            }
            break;
        case 3:
            if(nValue >0 && kValue >0 && sValue > 0 && rValue > 0) {
                for(int i = 0; i < kValue; i++) {
                    for(int j=0; j < rValue; j++) {
                        pointsGenerator.generateNPoints(pointsVector, nValue);
                        myAlgorithm.runAlgorithmLSLamana(pointsVector);
                    }
                    nValue += (i+1) * sValue;
                }
            }
            break;
        default:
            break;
    }
    usageHelp();
    return(-1);

}

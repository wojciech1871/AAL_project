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
        points.push_back(new Point(number, x, y, weight));
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

void usageHelp(char* name) {
    std::cout <<"Incorrect program call. ";
    std::cout <<"Usage:" <<std::endl;
    std::cout <<name <<" [-m <value> | --mode=<value>]" <<std::endl;
    std::cout <<"Options:" <<std::endl;
    std::cout <<" < [file_name] - required in mode 1" <<std::endl;
    std::cout << "[-n <value> | --probSize= <value>] - required in mode 2 and 3" <<std::endl;
    std::cout << "[-k <value> | --numOfProbs= <value>] - required in mode 3" <<std::endl;
    std::cout << "[-s <value> | --step= <value>] - required in mode 3" <<std::endl;
    std::cout << "[-r <value> | --instPerProb= <value>] - required in mode 3" <<std::endl;
    exit (-1);
}

int main(int argc, char* argv[])
{
    int opt;
    int mValue=0;
    int nValue=0;
    int kValue=0;
    int sValue=0;
    int rValue=0;
    vector_type pointsVector;
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
            pointsGenerator.destroyPoints(pointsVector);
            return(0);
        case 2:
            if(nValue > 0) {
                pointsGenerator.generateNPoints(pointsVector, nValue);
                algResultsForOneInstance(myAlgorithm, pointsVector);
                pointsGenerator.destroyPoints(pointsVector);
                return(0);
            }
            break;
        case 3:
            if(nValue >0 && kValue >0 && sValue > 0 && rValue > 0) {
                clock_type t1, t2;
                for(int i = 0; i < kValue; i++) {
                    time_period durationTime(0);
                    for(int j=0; j < rValue; j++) {
                        pointsGenerator.generateNPoints(pointsVector, nValue);
                        t1 = std::chrono::high_resolution_clock::now();
                        myAlgorithm.runAlgorithmLSLamana(pointsVector);
                        t2 = std::chrono::high_resolution_clock::now();
                        durationTime += (t2-t1);
                    }
                    std::cout <<nValue <<"\t";
                    std::cout <<durationTime.count()/rValue <<std::endl;
                    nValue += sValue;
                }
                pointsGenerator.destroyPoints(pointsVector);
                return(0);
            }
        default:
            break;
    }
    usageHelp(argv[0]);
    return(-1);

}

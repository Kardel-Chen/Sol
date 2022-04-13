#include <iostream>
#include <fstream>
#include <sstream>
#include "Solution.h"
using namespace std;
// function for unit testing
bool unit_test(Solution* solution, const char* input, int expectedNEc, int expectedNEw, int expectedNCc){
    Result * res = solution->count(input);
    std::cout << "***********"<<endl;
    std::cout<<"input: "<<endl<<input<<endl<<"Expected oput:" <<endl<< "Number of English words: " << expectedNEw<<endl<<"Number of English characters: " <<expectedNEc << endl<<"Number of Chinese characters: "<<expectedNCc << endl<<endl;
    std::cout << "Actual output: " << endl<< res->toString()<<endl;
    if(res->getNChnChar() == expectedNCc && res->getNEngCharacter()==expectedNEc && res->getNEngWord() == expectedNEw){
        std::cout << "testing passed" << std::endl;
        return true;
    }else{
        std::cout << "testing not passed" << std::endl;
        return false;
    }
}

int main() {

    std::ifstream file("testingCases.txt");
    Solution * solution = new Solution();
    int N = 7;
    int passed = 0;
    std::string input;

    for(int i = 0; i<N;i++){

        string tmp;
        int enec;
        int enew;
        int encc;

        std::getline(file, input);
        std::getline(file, tmp);
        enec = std::stoi(tmp);
        std::getline(file, tmp);
        enew = std::stoi(tmp);
        std::getline(file, tmp);
        encc = std::stoi(tmp);
        if (unit_test(solution, input.c_str(), enec, enew, encc)) {
            passed += 1;
        }

    }
    file.close();
    std::cout << "****Unit Test End, Case pass percentage: " << (1.0*passed)/N<<"***" <<endl;

}

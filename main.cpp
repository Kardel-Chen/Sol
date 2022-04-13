#include <iostream>
#include <fstream>
#include <sstream>
#include "Solution.h"
using namespace std;
// function for unit testing
bool unit_test(Solution* solution, const char* input, int expectedNEc, int expectedNEw, int expectedNCc){
    Result * res = solution->count(input);
    std::cout << "***********"<<endl;
    std::cout<<"input: "<<endl<<input<<endl<<endl<<"Expected output:" <<endl<< "Number of English words: " << expectedNEw<<endl<<"Number of English characters: " <<expectedNEc << endl<<"Number of Chinese characters: "<<expectedNCc << endl<<endl;
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
    // reading testing cases
    std::ifstream file("testingCases.txt");
    Solution * solution = new Solution();
    int N = 7;
    int passed = 0;
    std::string input;

    for(int i = 0; i<N;i++){
        // temporary variable input from use cases and stored into expected outputs
        string tmp;
        int enec; //expected number of English characters
        int enew;//expected number of English words
        int encc;//expected number of Chinese characters
        //read inputs
        std::getline(file, input);
        // read expected Num of English Char and store it into enec
        std::getline(file, tmp);
        enec = std::stoi(tmp);
        // read expected Num of English words and store it into enew
        std::getline(file, tmp);
        enew = std::stoi(tmp);
        // read expected Num of Chinese Char and store it into encc
        std::getline(file, tmp);
        encc = std::stoi(tmp);
        if (unit_test(solution, input.c_str(), enec, enew, encc)) {
            passed += 1;
        }

    }
    file.close();
    std::cout << "****Unit Test End, Case pass percentage: " << (1.0*passed)/N<<"***" <<endl;

}

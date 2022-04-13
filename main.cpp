#include <iostream>
#include "Solution.h"
using namespace std;
bool unit_test(Solution* solution, char* input, int expectedNEc, int expectedNEw, int expectedNCc){
    Result * res = solution->count(input);
//    cout<<res->toString()<<endl;
    if(res->getNChnChar() == expectedNCc && res->getNEngCharacter()==expectedNEc && res->getNEngWord() == expectedNEw){
        std::cout << "testing passed" << std::endl;
        return true;
    }else{
        std::cout << "testing not passed" << std::endl;
        return false;
    }
}
int main() {
    // NEc->Number of English characters
    // NEw->Number of English words
    // NCc->Number of Chinese characters
    std::cout << "****Unit Test****"<<endl;
    int total = 0;
    int passed = 0;
    auto* sol = new Solution();
    // all english characters. single word
    char example1[] = "helloworld";
    int expectedOutput1[] = {10, 1, 0};
    if(unit_test(sol, example1, expectedOutput1[0],expectedOutput1[1],expectedOutput1[2])){
        passed+=1;
    }
    total += 1;
    // all english characters. multiple word
    char example2[] = "hello wo rld";
    int expectedOutput2[] = {10, 3, 0};
    if(unit_test(sol, example2, expectedOutput2[0],expectedOutput2[1],expectedOutput2[2])){
        passed+=1;
    }
    total += 1;

    // english & Chinese characters. single english word
    char example3[] = "hello 世界";
    int expectedOutput3[] = {5, 1, 2};
    if(unit_test(sol, example3, expectedOutput3[0],expectedOutput3[1],expectedOutput3[2])){
        passed+=1;
    }
    total += 1;
    // english & Chinese characters. chinese character
    char example4[] = "hello 世world界";
    int expectedOutput4[] = {10, 2, 2};
    if(unit_test(sol, example4, expectedOutput4[0],expectedOutput4[1],expectedOutput4[2])){
        passed+=1;
    }
    total += 1;
    // All empty string
    char example5[] = "      ";
    int expectedOutput5[] = {0,0,0};
    if(unit_test(sol, example5, expectedOutput5[0],expectedOutput5[1],expectedOutput5[2])){
        passed+=1;
    }
    total += 1;
    // All empty string2
    char example6[] = "";
    int expectedOutput6[] = {0,0,0};
    if(unit_test(sol, example6, expectedOutput6[0],expectedOutput6[1],expectedOutput6[2])){
        passed+=1;
    }
    total += 1;

    // english & Chinese characters. single english word, with character from other languages
    char example7[] = "hello 世不قويㅂㅈㅁ١worうld界";
    int expectedOutput7[] = {10,3,3};
    if(unit_test(sol, example7, expectedOutput7[0],expectedOutput7[1],expectedOutput7[2])){
        passed+=1;
    }
    total += 1;
    std::cout << "****Unit Test End, Case pass percentage: " << (1.0*passed)/total<<"***" <<endl;


}

//
// Created by kardel on 4/12/22.
//

#ifndef SOL_RESULT_H
#define SOL_RESULT_H


#include <string>
/*
 *
 *  Result for Solution
 *  NEc->Number of English characters
 *  NEw->Number of English words
 *  NCc->Number of Chinese characters
 * */
class Result {
private:
    int nEc;
    int nCc;
    int nEw;
public:
    explicit Result(int nEc=0, int nCc=0, int nEw=0);
    ~Result();
    int getNEngWord();
    int getNChnChar();
    int getNEngCharacter();
    void setNEngWord(int nEw);
    void setNChnChar(int nCc);
    void setNEngCharacter(int nEc);
    std::string toString() {
        return  "number of English word: " + std::to_string(nEw) + "\n" +
                "number of English characters: " + std::to_string(nEc) + "\n" +
                "number of Chinese Characters: " + std::to_string(nCc) + "\n";

    }
};


#endif //SOL_RESULT_H

//
// Created by kardel on 4/12/22.
//

#include "Result.h"

int Result::getNChnChar() {
    return nCc;
}

int Result::getNEngWord() {
    return nEw;
}

int Result::getNEngCharacter() {
    return nEc;
}

void Result::setNChnChar(int nCc) {
    this->nCc = nCc;
}

void Result::setNEngCharacter(int nEc) {
    this->nEc = nEc;
}
void Result::setNEngWord(int nEw) {
    this->nEw = nEw;
}

Result::Result(int nEc, int nCc, int nEw) {
    this->nEc = nEc;
    this->nCc = nCc;
    this->nEw = nEw;
}

Result::~Result() = default;

//
// Created by kardel on 4/12/22.
//

#include "Solution.h"
#include <iostream>
using namespace std;
/*
 * Overview:
 * 1. determine the decoding method: utf-8/unicode/GBK ()
 * 2. According to the decoding method, find the range of chinese character
 * 3. normally english character takes 1-2
 * */
Result *Solution::count(char *input) {
    int nEngWord = 0;
    int nEngChar = 0;
    int nChChar = 0;
// in linux, the decoding method is by default utf-8
    while(*input != 0){
//        cout<<"0"<<(int)*input<<endl;
        //in utf-8 chinese character(non-ascii character) takes 3 bytes, but for all ascii characters(English character) it takes 1 byte.
        //Also, For UTF-8, characters in ASCII starting with 0, others starting with 1, meaning that if *input < 0, then *input is not a english character
        if((65 <= *input && *input <= 90) || (97 <= *input && *input <= 122)){
            //if input is in the range [A, Z] or [a, z], we determine there will be an english word
            while((65 <= *input && *input <= 90) || (97 <= *input && *input <= 122)){
//                cout<<1;

                input++;
                nEngChar++;
            }
            nEngWord++;
        }else if(*input < 0){
//            cout<<1<<endl;
            // for utf-8, chinese characters are in the range [u4e00-u9fef] (unicode)
            // if the character not starting with \xexxxx, then it is not a chinese character.
            //else, if the character is not in the range[\xe4\xb8\x80, \xe9\xbf\xaf], then it is not a chinese character
            if((256+*input)>>4 == 14){
                //starting with e
                int value = ((256+*input)<<16) + ((256+*(input+1))<<8) + 256+*(input+2);
                int startingRange = (0xe4<<16) + (0xb8<<8) + 0x80;
                int endingRange = (0xe9<<16) + (0xbf<<8) + 0xaf;
                if (startingRange<=value && value <= endingRange){
                    nChChar++;
                }
//                cout<<3;
                input += 3;
            }else{
                int startingValue = (256+*input)>>4;
                if(0b1100==startingValue || startingValue==0b1101){
//                    cout<<2;
                    input += 2;
                }else if(0b1111 == startingValue){
//                    cout<<4;
                    input += 4;
                }
            }
        }else{
            input++;
        }
    }
    cout << nEngChar << " "  << nChChar << " " << nEngWord;
    return new Result(nEngChar, nChChar, nEngWord);
}
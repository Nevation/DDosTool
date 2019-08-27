#include "etc_function.h"

vector<string> str_split(string str, const char point){
    int strLen = str.size();
    vector<string> result;
    string part;
    for (int i=0; i<strLen; i++){
        if (str[i] == point){
            result.push_back(part);
            part = "";
        } else {
            part += str[i];
        }
    }
    result.push_back(part);
    return result;
}




vector<uchar> MakeDummy(vector<uchar> packet){
    uchar tmp;

    for (int i = packet.size(); i < 1500; i++) {
        tmp = rand() % 256;
        packet.push_back(tmp);
    }

    return packet;
}

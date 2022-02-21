#include <iostream>
#include <string>
#include <typeinfo>
#include "impFromJfrogLib.h"

using namespace std;

int main(){
    setFileName("my_config.json");
    string fromJson = readJson();
    cout<<"main.cpp::"<<typeid(fromJson).name()<<endl;
    cout<<"main.cpp::"<< (string(typeid(fromJson).name())=="NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE") <<endl;
    cout<<"main.cpp::"<<fromJson <<endl;
    return 0;
}
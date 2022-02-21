#include "impFromJfrogLib.h"
#include <fstream>
#include <iostream>
//https://conan.io/ -> btn[Conan-Center]-> find nlohmann = https://conan.io/center/search/nlohmann
#include <nlohmann/json.hpp>

string fileName = "";

int setFileName(string name){
    fileName = name;
    return 0;
}
int getNumber(){
    return 7;
}

nlohmann::json jsonObjectFromFile(){
    ifstream my_file(fileName);
    nlohmann::json obj;
    my_file>>obj;
    return obj;
}

string readJson(){
    if(fileName!=""){
        nlohmann::json obj = jsonObjectFromFile();
        return obj["Dextra"]["demoJson"]["title"];
    }
    return "";
}

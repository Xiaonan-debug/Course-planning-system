#include "Requirement.h"
#include <iostream>
#include <fstream>
#include <string>

Requirement::Requirement (string name, Type type):name(name), type(type){
    build_sections();
}

Requirement::~Requirement(){
    for(int i = 0; i < section_list.size(); ++i){
        delete section_list[i];
        section_list[i] = nullptr;
    }
}

Requirement::Type Requirement::get_type() const{
    return type;
}

string Requirement::get_name(){
    return name;
}

vector<Section*> Requirement::get_section_list() const{
    return this -> section_list;
}

void Requirement::adjust(){
    //check every section in section_list and adjust the private variable "satisfied" accordingly
    for(int i = 0; i <section_list.size(); i++){
        section_list[i]->verify_if_satisfied();
    }
};

void Requirement::show(){}/*先不写*/

void Requirement::build_sections(){
    string filename = "./Requirements/"+ name +".txt";
    //get the name of txt file
    ifstream ifs(filename);
    //find the txt file and open it


    if(!ifs){// can't open the file
        return;
        //do some thing on the user interface
    };

    string c;//use it to read the txt file
    getline(ifs,c);
    getline(ifs,c);

    //we devided requirement into several sections as in curriculum document of cohort admission
    //for every two line in txt file, the first line stores section_type, the second line stores the section content
    while(getline(ifs,c)){
        if(atoi(c.c_str()) == 1){
            getline(ifs,c);
            section_list.push_back(new Required_Section(c));
        }
        else{
            int min_required_credit=0;
            if (c.length()==3){
                min_required_credit = atoi(c.substr(2,1).c_str());
            }
            else{
                min_required_credit = atoi(c.substr(2,2).c_str());
            } 
            getline(ifs,c);
            section_list.push_back(new Elective_Section(min_required_credit,c));
        }
       
    }
    ifs.close();
};
#include "Requirement.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

Requirement::Requirement (string name, Type type):name(name), type(type){
    section_list.reserve(100);
    build_sections();
}

Requirement::~Requirement(){
    if(!section_list.empty()){
        for(int i = 0; i < section_list.size(); ++i){
            delete section_list[i];
            section_list[i] = nullptr;
        }
    }
}

Requirement::Type Requirement::get_type() const{
    return type;
}

string Requirement::get_name(){
    return name;
}

vector<Section*> Requirement::get_section_list() const{//新加的
    return this -> section_list;
}

void Requirement::adjust(){
    //check every section in section_list and adjust the private variable "satisfied" accordingly
    for(int i = 0; i <section_list.size(); i++){
        section_list[i]->verify_if_satisfied();
    }
}

void Requirement::build_sections(){
    string filename = "./Requirements/"+ name +".txt";
    //get the name of txt file
    ifstream ifs(filename);
    //find the txt file and open it

    if(!ifs){// can't open the file
        return;
        //do some thing on the user interface
    }

    string typeinfo;
    string nameinfo;
    ifs >> typeinfo >> nameinfo;
    if (typeinfo == "CCC") {
        this -> type = CCC;
    }
    else if (typeinfo == "SCHOOL"){
        this -> type = SCHOOL;
    }
    else if (typeinfo == "MAJOR"){
        this -> type = MAJOR;
    }
    this -> name = nameinfo;

    //we devided requirement into several sections as in curriculum document of cohort admission
    //for every two line in txt file, the first line stores section_type, the second line stores the section content

    string c;
    while(ifs >> c){
        if(c == "1"){
            string courseinfo;
            string useless; getline(ifs, useless);
            getline(ifs,courseinfo);
            section_list.push_back(new Required_Section(courseinfo));
            c = "";
        }
        else{
            int min_required_credit=0;
            //get information of min required credit from the string c
            string min_credit_info;
            ifs >> min_credit_info;
            min_required_credit = atoi(min_credit_info.c_str());
            //get course information from the next line
            string courseinfo;
            string useless; getline(ifs, useless);
            getline(ifs,courseinfo);
            section_list.push_back(new Elective_Section(min_required_credit,courseinfo));
            c = "";
        }
    }
    ifs.close();
}